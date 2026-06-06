#include "library.h"

// Insert terurut berdasarkan sisa hari (Ascending)
Node* sorting_insert_by_deadline(Node* head, Node data_baru) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    *newNode = data_baru;

    if (head == NULL || head->sisa_hari_Deadline >= newNode->sisa_hari_Deadline) {
        newNode->next = head;
        return newNode;
    }
    
    Node* current = head;
    while (current->next != NULL && current->next->sisa_hari_Deadline < newNode->sisa_hari_Deadline) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Insert terurut berdasarkan skor prioritas (Descending / Greedy)
Node* sorting_insert_by_prioritas(Node* head, Node data_baru) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    *newNode = data_baru;

    if (head == NULL || head->skor_prioritas <= newNode->skor_prioritas) {
        newNode->next = head;
        return newNode;
    }
    
    Node* current = head;
    while (current->next != NULL && current->next->skor_prioritas > newNode->skor_prioritas) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Fungsi untuk menampilkan data tugas
void tampilkan_tugas(Node* head) {
    if (head == NULL) {
        printf("Daftar tugas kosong.\n");
        return;
    }
    printf("\n--- Daftar Semua Tugas ---\n");
    while (head != NULL) {
        printf("- Tugas: %s\n", head->nama_tugas);
        printf("  Deadline: %d hari\n", head->sisa_hari_Deadline);
        printf("  Bobot Nilai: %.1f%%\n", head->bobot_nilai);
        printf("  Estimasi Waktu: %.1f Jam\n\n", head->estimasi_waktu);
        head = head->next;
    }
}

// Fungsi untuk menghasilkan priority queue baru yang berisi tugas-tugas dengan skor prioritas terhitung
Node* generate_priority_queue(Node* mainList) {
    Node* pqHead = NULL;
    while (mainList != NULL) {
        Node data_copy = *mainList;
        float pembagi = (data_copy.sisa_hari_Deadline + 1.0) * (data_copy.estimasi_waktu + 1.0);
        data_copy.skor_prioritas = data_copy.bobot_nilai / pembagi;
        data_copy.next = NULL;
        
        pqHead = sorting_insert_by_prioritas(pqHead, data_copy);
        mainList = mainList->next;
    }
    return pqHead;
}

// Fungsi untuk menampilkan rekomendasi berdasarkan skor prioritas
void tampilkan_prioritas(Node* head) {
    if (head == NULL) {
        printf("Tidak ada tugas untuk diprioritaskan.\n");
        return;
    }
    printf("\n--- Rekomendasi Prioritas (Algoritma Greedy) ---\n");
    int i = 1;
    while (head != NULL) {
        printf("%d.", i++); 
        printf(" Tugas: %s\n", head->nama_tugas);
        printf("   Skor Prioritas: %.4f\n", head->skor_prioritas);
        printf("   Deadline: %d hari\n", head->sisa_hari_Deadline);
        printf("   Bobot Nilai: %.1f%%\n", head->bobot_nilai);
        printf("   Estimasi Waktu: %.1f Jam\n\n", head->estimasi_waktu);
        head = head->next;
    }
}
