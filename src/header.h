#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1 struct untuk menyimpan data tugas
typedef struct Node {
    char nama_tugas[100];
    int sisa_hari_Deadline;
    float bobot_nilai;
    float estimasi_waktu;
    float skor_prioritas;
    struct Node* next;
} Node;

// Operasi Linked List Untuk Memasukkan data tugas
Node* insert_head(Node* head, Node data_baru); 
// Insert terurut berdasarkan sisa hari (Ascending)
Node* sorting_insert_by_deadline(Node* head, Node data_baru); 
// Insert terurut berdasarkan skor prioritas (Descending / Greedy)
Node* sorting_insert_by_prioritas(Node* head, Node data_baru); 

// fungsi untuk menampilkan data tugas
void tampilkan_tugas(Node* head);
// fungsi untuk menampilkan rekomendasi berdasarkan skor prioritas
void tampilkan_prioritas(Node* head);
// fungsi untuk mencari tugas berdasarkan keyword
void cari_tugas(Node* head, char keyword[]);
// fungsi untuk menandai tugas selesai dan memindahkannya ke riwayat
Node* finish_tugas(Node* head, char nama[], Node* temp_selesai, int* found);
// fungsi untuk undo tugas selesai dengan memindahkannya kembali ke daftar tugas
Node* popHead(Node* head, Node* poppedData, int* success); 
// fungsi untuk menghasilkan priority queue baru yang berisi tugas-tugas dengan skor prioritas terhitung
Node* generate_priority_queue(Node* mainList);
// fungsi untuk membebaskan memori
void free_list(Node* head);

#endif
