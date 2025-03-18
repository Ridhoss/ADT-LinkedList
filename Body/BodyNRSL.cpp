/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
#include "../Header/spnrsll.h"

/********** BODY SUB PROGRAM ***********/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L)
/* Mengirim true jika List Kosong */
{
	return (First(L) == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	First(*L) = Nil;
}

/**** Manajemen Memory ****/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = (address) malloc (sizeof (ElmtList));
	if (P != Nil)		/* Alokasi berhasil */
	{
		Info(P) = X;
		Next(P) = Nil;
	}
	return (P);
}

void DeAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	if (P != Nil)
	{
		free (P);
	}
}

/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	 /* Kamus Lokal */
	address P;
	boolean found =  false;
	 /* algoritma */
	P = First(L);
	while ((P != Nil) && (!found))
	{
		if (Info(P) == X)
		{	found = true; 	}
		else
		{	P = Next(P);	}
	}	/* P = Nil atau Ketemu */
	
	return (P);
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	 /* Kamus Lokal */
	 boolean found=false;
	 address PSearch;
	 /* Algortima */
	 PSearch = First(L);
	 while ((PSearch != Nil) && (!found))
	 {
		if (PSearch == P)
		{	found = true; 	}
		else
		{	PSearch = Next(PSearch);	}
	 }	/* PSearch = Nil atau Ketemu */
	 
	 return (found);
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	 /* Kamus Lokal */
	address Prec, P;
	boolean found=false;
	 /* Algoritma */
	Prec = Nil;
	P = First(L);
	while ((P != Nil) && (!found))
	{
		 if (Info(P) == X)
		 {	found = true;	}
		 else
		 {
			Prec = P;
			P = Next(P);
		 }
	}    /* P = Nil atau Ketemu */
	if (found)
	{	return (Prec);		}
	else
	{	return (Nil);		}
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	 /* Kamus Lokal */
	address P;

	 /* Algoritma */
	P = Alokasi(X);

	if(P != Nil){
		Next(P) = First(*L);
		First(*L) = P;
	}

	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsVLast (List * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	 /* Kamus Lokal */
	address P, temp;
	
	 /* Algoritma */
	P = Alokasi(X);

	temp = First(*L);

	while (Next(temp) != Nil)
	{
		temp = Next(temp);
	}

	Next(temp) = P;
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = First(*L);

	*X = Info(P);
	First(*L) = Next(P);
	DeAlokasi(P);
	
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelVLast (List * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	 /* Kamus Lokal */
	address PDel, Prev;
	 /* Algoritma */
	PDel = First(*L);

	while (Next(PDel) != Nil)
	{
		Prev = PDel;
		PDel = Next(PDel);
	}

	*X = Info(PDel);
	Next(Prev) = Nil;
	DeAlokasi(PDel);
	
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{
	//Buatkan algoritma sesuai spesifikasi modul ini
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List * L, address P, address Prec)
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//Buatkan algoritma sesuai spesifikasi modul ini
	address temp;

	temp = First(*L);
	
	while (temp != Prec)
	{
		temp = Next(temp);
	}

	Next(P) = Next(temp);
	Next(temp) = P;

}

void InsertLast (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	address Last;
	 /* Algoritma */
	Last = First(*L);

	while (Next(Last) != Nil)
	{
		Last = Next(Last);
	}

	Next(Last) = P;
	 
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
{
	//Buatkan algoritma sesuai spesifikasi modul ini
	address temp;

	temp = First(*L);
	if(temp != Nil){
		(*P) = Alokasi(Info(temp));

		First(*L) = Next(temp);
		DeAlokasi(temp);
	}
}


void DelP (List * L, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	 /* Kamus Lokal */
	address P, prec;
	boolean found=false;
	 
	 /* Algoritma */
	P = Search((*L), X);
	prec = SearchPrec((*L), Info(P));

	if(prec == Nil){
		DelFirst(L, &P);
	}else {
		Next(prec) = Next(P);
		DeAlokasi(P);
	}

	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelLast (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
	 /* Kamus Lokal */
	address Prec, temp;
	 /* Algoritma */

	temp = First(*L);

	while (Next(temp) != Nil)
	{
		temp = Next(temp);
	}

	Prec = SearchPrec((*L), Info(temp));

	if(temp != Nil){
		(*P) = Alokasi(Info(temp));

		Next(Prec) = Nil;
		DeAlokasi(temp);
	}
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelAfter (List * L, address * Pdel, address Prec)
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
{
	 //Buatkan algoritma sesuai spesifikasi modul ini
	address temp;

	if (Next(Prec) == Nil)
	{
		printf("Tidak ada element list berikutnya!\n");
	}

    if (Prec != Nil && Next(Prec) != Nil) {
        temp = Next(Prec);
        *Pdel = Alokasi(Info(temp));
        
        Next(Prec) = Next(temp);
        DeAlokasi(temp);
    }
}

/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */

	if(First(L) == Nil){
		printf("List Kosong!\n");
	} else {
		P = First(L);
		while (P != Nil) {
			printf("%d -> ", Info(P));
			P = Next(P); 
		}
		printf("NULL \n");
	}
    printf("======================== \n");

	//Buatkan algoritma sesuai spesifikasi modul ini
}


void DelAll (List * L)
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
	 /* Kamus Lokal */
	address PDel, temp;
	 /* Algoritma */
	
	PDel = First(*L);

	while (PDel != Nil)
	{
		temp = PDel;
		PDel = Next(PDel);
		DeAlokasi(temp);
	}

	First(*L) = Nil;

	printf("Berhasil Menghapus Semua Element List!\n");
}

void DelGanjil(List * L) 
{
    address PBefore, PNext, Pdel;
	
    while (First(*L) != Nil && Info(First(*L)) % 2 == 1) {
        Pdel = First(*L);
        First(*L) = Next(Pdel);
        DeAlokasi(Pdel);
    }

    if (First(*L) == Nil) return;

    PBefore = First(*L);
    PNext = Next(PBefore);

    while (PNext != Nil) {
        if (Info(PNext) % 2 == 1) {
            Pdel = PNext;
            PNext = Next(PNext);
            Next(PBefore) = PNext;
            DeAlokasi(Pdel);
        } else {
            PBefore = PNext;
            PNext = Next(PNext);
        }
    }

    printf("Node Ganjil Berhasil Dihapus!\n");
}
