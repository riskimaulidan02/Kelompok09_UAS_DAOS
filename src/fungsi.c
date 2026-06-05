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