#include "library.h"

int main() {
    // Inisialisasi linked list untuk daftar tugas, riwayat tugas, dan rekomendasi prioritas
    Node* daftar_tugas = NULL; 
    Node* riwayat_tugas = NULL; 
    Node* rekomendasi_tugas = NULL;

    int pilihan;
    do {
        printf("\n=========================================\n");
        printf("  SISTEM MANAJEMEN TUGAS MAHASISWA\n");
        printf("=========================================\n");
        printf("1. Tambah Tugas Baru\n");
        printf("2. Lihat Daftar Tugas\n");
        printf("3. Cari Tugas\n");
        printf("4. Lihat Rekomendasi Prioritas\n");
        printf("5. Tandai Tugas Selesai/Undo\n");
        printf("6. Keluar program\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1: {
                // Input data tugas baru
                Node t;
                printf("Nama Tugas: ");
                scanf(" %[^\n]", t.nama_tugas);

                printf("Sisa Hari Deadline (Angka): ");
                scanf("%d", &t.sisa_hari_Deadline);

                printf("Bobot Nilai (%%): ");
                scanf("%f", &t.bobot_nilai);

                printf("Estimasi Waktu Pengerjaan (Jam): ");
                scanf("%f", &t.estimasi_waktu);

                // Sorting insert berdasarkan deadline
                daftar_tugas = sorting_insert_by_deadline(daftar_tugas, t);
                printf("Tugas berhasil ditambahkan!\n");
                break;
            }
            case 2:
                // Tampilkan daftar tugas disorting berdasarkan deadline
                tampilkan_tugas(daftar_tugas);
                break;
        }
}  while (pilihan != 6);