#include "header.h"

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
            case 3: {
                // Cari tugas berdasarkan keyword
                char keyword[100];
                printf("Masukkan nama tugas yang dicari: ");
                scanf(" %[^\n]", keyword);
                // Fungsi cari_tugas akan menampilkan tugas yang mengandung keyword tersebut
                cari_tugas(daftar_tugas, keyword);
                break;
            }
            case 4:
                // Bebaskan memori rekomendasi tugas lama sebelum menghasilkan yang baru
                free_list(rekomendasi_tugas); 
                // Tampilkan rekomendasi prioritas berdasarkan skor prioritas yang dihitung dari data tugas
                rekomendasi_tugas = generate_priority_queue(daftar_tugas);
                // Fungsi tampilkan_prioritas akan menampilkan tugas-tugas berdasarkan skor prioritas tertinggi
                tampilkan_prioritas(rekomendasi_tugas);
                break;
            case 5: {
                // Submenu untuk tandai tugas selesai atau undo tugas selesai
                int subPilihan;
                printf("\n--- Submenu Selesai / Undo ---\n");
                printf("1. Tandai Tugas Selesai\n");
                printf("2. Undo Tugas Selesai\n");
                printf("Pilih submenu: ");
                scanf("%d", &subPilihan);

                if (subPilihan == 1) {
                    char nama[100];
                    Node temp_selesai;
                    int found = 0;
                    
                    printf("Masukkan nama persis tugas yang selesai: ");
                    scanf(" %[^\n]", nama);
                    // Fungsi finish_tugas akan mencari tugas berdasarkan nama, menandainya selesai,
                    // dan memindahkannya ke riwayat tugas
                    daftar_tugas = finish_tugas(daftar_tugas, nama, &temp_selesai, &found);
                    
                    if (found) {
                        // Jika tugas ditemukan dan dipindahkan ke riwayat,
                        // maka kita masukkan data tugas yang selesai ke stack riwayat_tugas
                        riwayat_tugas = insert_head(riwayat_tugas, temp_selesai);
                        printf("Tugas '%s' ditandai selesai dan masuk riwayat!\n", nama);
                    } else {
                        printf("Tugas tidak ditemukan.\n");
                    }
                } else if (subPilihan == 2) {
                    Node temp_undo;
                    int success = 0;
                    // Fungsi popHead akan mengambil tugas terakhir yang selesai dari stack riwayat_tugas
                    // dan mengembalikannya ke daftar tugas jika ada
                    riwayat_tugas = popHead(riwayat_tugas, &temp_undo, &success);

                    if (success) {
                        // Jika ada tugas yang berhasil di-undo, 
                        // maka kita masukkan kembali ke daftar tugas dengan sorting berdasarkan deadline
                        daftar_tugas = sorting_insert_by_deadline(daftar_tugas, temp_undo);
                        printf("Tugas '%s' berhasil di-undo dan dikembalikan ke daftar tugas!\n", temp_undo.nama_tugas);
                    } else {
                        printf("Gagal: Belum ada tugas di riwayat yang bisa di-undo.\n");
                    }
                } else {
                    printf("Pilihan submenu tidak valid.\n");
                }
                break;
            }
            case 6:
                printf("Program keluar, terimakasih sudah menggunakan aplikasi ini!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        } // Penutup switch yang benar
    } while (pilihan != 6);

    free_list(daftar_tugas);
    free_list(riwayat_tugas);
    free_list(rekomendasi_tugas);

    return 0;
}