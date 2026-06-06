#ifndef LIBRARY_H
#define LIBRARY_H

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

// Insert terurut berdasarkan sisa hari (Ascending)
Node* sorting_insert_by_deadline(Node* head, Node data_baru); 
// Insert terurut berdasarkan skor prioritas (Descending / Greedy)
Node* sorting_insert_by_prioritas(Node* head, Node data_baru); 

// fungsi untuk menampilkan data tugas
void tampilkan_tugas(Node* head);
// fungsi untuk menampilkan rekomendasi berdasarkan skor prioritas
void tampilkan_prioritas(Node* head);
// fungsi untuk menghasilkan priority queue baru yang berisi tugas-tugas dengan skor prioritas terhitung
Node* generate_priority_queue(Node* mainList);

#endif
