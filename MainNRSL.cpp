/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */
/* Diupdate oleh : WW & AM, 8-3-2025, penyesuaian area body & main untuk latihan Diploma 3 */

#include "Header/spnrsll.h"
#include <stdio.h>

int main()
{
	/* Kamus Lokal */
		List MyList;
		infotype isi, isiBekas, isiPrec;
		address P, Prec;
		int pil = 0;
		char y = 'N';

	/* Program */
	CreateList (&MyList);

	//aksi mahasiswa untuk implementasi studi kasus
	for (;;) {
        printf("Pilihlah Menu Berikut : \n");
        printf("1. Tambah Awal Berdasarkan Nilai\n");
        printf("2. Tambah Akhir Berdasarkan Nilai\n");
        printf("3. Hapus Awal Berdasarkan Nilai\n");
        printf("4. Hapus Akhir Berdasarkan Nilai\n");
        printf("5. Tambah Awal Berdasarkan Alamat\n");
        printf("6. Tambah Tengah Berdasarkan Alamat\n");
        printf("7. Tambah Akhir Berdasarkan Alamat\n");
        printf("8. Hapus Awal Berdasarkan Alamat\n");
        printf("9. Hapus Sesuai info Berdasarkan Alamat\n");
        printf("10. Hapus Akhir Berdasarkan Alamat\n");
        printf("11. Hapus Setelah Alamat (After)\n");
        printf("12. Hapus Node Ganjil\n");	
        printf("13. Print List\n");
        printf("14. Delete All\n");
        printf("15. Keluar\n");
        printf("Pilihanmu : ");
        scanf("%d", &pil);
        printf("\n========================= \n");

        switch (pil)
        {
        case 1:
			printf("Masukan Nilai info : ");
			scanf("%d", &isi);
			InsVFirst(&MyList, isi);
			printf("======================== \n");

            break;
        case 2:
			printf("Masukan Nilai info : ");
			scanf("%d", &isi);
			InsVLast(&MyList, isi);
			printf("======================== \n");

            break;
        case 3:
			DelVFirst(&MyList, &isiBekas);
			printf("Element Awal List Berhasil Dihapus, Isinya adalah = %d \n", isiBekas);
			printf("======================== \n");

            break;
        case 4:
			DelVLast(&MyList, &isiBekas);
			printf("Element Akhir List Berhasil Dihapus, Isinya adalah = %d \n", isiBekas);
			printf("======================== \n");

            break;
        case 5:
			printf("Masukan Nilai P = ");
			scanf("%d", &isi);
			P = Alokasi(isi);
			InsertFirst(&MyList, P);
			printf("======================== \n");

            break;
        case 6:
			PrintInfo(MyList);
			printf("Pilih Node mana prec = ");
			scanf("%d", &isiPrec);

			Prec = Search(MyList, isiPrec);

			printf("Masukan isi element baru = ");
			scanf("%d", &isi);
			P = Alokasi(isi);

			InsertAfter(&MyList, P, Prec);
			printf("======================== \n");

            break;
        case 7:
			printf("Masukan Nilai P = ");
			scanf("%d", &isi);
			P = Alokasi(isi);
			InsertLast(&MyList, P);
			printf("======================== \n");

            break;
        case 8:
			DelFirst(&MyList, &P);

			printf("Element Awal List Berhasil Dihapus, Isinya adalah = %d \n", Info(P));
			printf("======================== \n");

            break;
        case 9:
			printf("Element yang akan dihapus = ");
			scanf("%d", &isi);

			DelP(&MyList, isi);

			printf("Element List Berhasil Dihapus, Isinya adalah = %d \n", isi);
			printf("======================== \n");
            break;
        case 10:
			DelLast(&MyList, &P);

			printf("Element Akhir List Berhasil Dihapus, Isinya adalah = %d \n", Info(P));
			printf("======================== \n");
            break;
        case 11:
			PrintInfo(MyList);
			printf("Pilih node before yang akan di delete = ");
			scanf("%d", &isiPrec);

			Prec = Search(MyList, isiPrec);
			DelAfter(&MyList, &P, Prec);

			printf("Element List Berhasil Dihapus, Isinya adalah = %d \n", Info(P));
			printf("======================== \n");
            break;
		case 12:
			PrintInfo(MyList);

			printf("Apakah yakin ingin menghapus semua element Ganjil? Y/N \n");
			scanf("%s", &y);
				if(y == 'Y' || y == 'y'){
					DelGanjil(&MyList);
				}else {
					break;
				}
			break;
        case 13:
			PrintInfo(MyList);
			break;
		case 14:
			printf("Apakah yakin ingin menghapus semua element List? Y/N \n");
			scanf("%s", &y);
			if(y == 'Y' || y == 'y'){
				DelAll(&MyList);
			}else {
				break;
			}
			break;
		case 15:
			return 0;
			break;
        }
    }
	

	/* Finishing */
	
	//Pastikan List di Dealokasi setelah manipulasi elemen selesai
	
	return 0;
}

