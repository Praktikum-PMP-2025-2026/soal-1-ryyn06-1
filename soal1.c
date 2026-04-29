/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Achmad Rayyan Hawari (13224110)
 *   Nama File           : soal1.c
 *   Deskripsi           : 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_len 99


typedef struct Arsip
{
    char *nama;
    char *kategori;
    int tahun;
    int nilai; 
}Arsip;

int compare(const void *a, const void *b) {
    Arsip *p1 = (Arsip *)a;
    Arsip *p2 = (Arsip *)b;

    if (p1->kategori != p2->kategori) {
        return strcmp(p1->kategori, p2->kategori);}

    if (p1->nama != p2->nama) {
        return strcmp(p1->nama, p2->nama);}
    
    if (p1->tahun != p2->tahun) {
        return p1->tahun - p2->tahun;
    }

    if (p1->nilai != p2->nilai) {
        return p2->nilai - p1->nilai;
    }

    if (p1->nama != p2->nama) {
        return strcmp(p1->nama, p2->nama);
    
}}



int main(){
    int jumlah_artefak;;
    char buffer_nama[max_len], buffer_kategori[max_len];
    char *sorted_nama;
    char *sorted_kategori;
    


    scanf("%d", &jumlah_artefak);

    Arsip *Artefak = (Arsip *)malloc( jumlah_artefak* sizeof(Arsip));

    Artefak = (Arsip*) realloc(Artefak, jumlah_artefak * sizeof(Arsip));

    for (size_t i = 0; i < jumlah_artefak; i++)
    {
        scanf("%s", buffer_nama);
        scanf("%s", buffer_kategori);
        scanf("%d", &Artefak[i].tahun);
        scanf("%d", &Artefak[i].nilai);

        Artefak[i].nama = (char *)malloc((strlen(buffer_nama) + 1) * sizeof(char));
        strcpy(Artefak[i].nama, buffer_nama);

        Artefak[i].kategori = (char *)malloc((strlen(buffer_kategori) + 1) * sizeof(char));
        strcpy(Artefak[i].kategori, buffer_kategori);


    }

    qsort(Artefak,jumlah_artefak, sizeof(Arsip), compare);

    for (size_t i = 0; i < jumlah_artefak; i++)
    {
        printf("%s %s %d %d\n", Artefak[i].nama,Artefak[i].kategori, Artefak[i].tahun, Artefak[i].nilai);
    }

    free(Artefak);
    return 0;

}
