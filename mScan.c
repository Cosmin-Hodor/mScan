#include <stdio.h>
#include <stdlib.h>

// Definiti dimensiunea buffer-ului pentru citirea si scrierea datelor
#define BUFFER_SIZE 1024

int main() {
  // Declarati variabila de tip FILE * pentru a retine referinta catre fisierul deschis
  FILE *fp;

  // Deschideti fisierul pentru citire si scriere folosind modul "rw" 📁
  fp = fopen("memory.dat", "rw");
  if (fp == NULL) {
    // Afisati un mesaj de eroare daca fisierul nu a putut fi deschis
    printf("Eroare: fisierul nu poate fi deschis!\n");
    return 1; // Terminati programul cu codul de eroare 1
  };

  // Declarati un buffer pentru citirea si scrierea datelor din si in fisier ✍️
  char buffer[BUFFER_SIZE];

  // Cititi datele din fisier si stocati-le in buffer
  if (fread(buffer, BUFFER_SIZE, 1, fp) != 1) {
    // Afisati un mesaj de eroare daca datele nu au putut fi citite din fisier
    printf("Eroare: datele nu au putut fi citite din fisier!\n");
    return 1; // Terminati programul cu codul de eroare 1
  };

  // Modificati datele din buffer dupa cum este necesar
  for (int i = 0; i < BUFFER_SIZE; i++) {
    // In acest exemplu, inversam fiecare octet din buffer
    // Orice metoda de manipulare se poate folosi in aceasta iteratie 👀
    buffer[i] = ~buffer[i];
  };

  // Scrieti datele modificate inapoi in fisier
  if (fwrite(buffer, BUFFER_SIZE, 1, fp) != 1) {
    // Afisati un mesaj de eroare daca datele nu au putut fi scrise in fisier
    printf("Eroare: datele nu au putut fi scrise in fisier!\n");
    return 1; // Terminati programul cu codul de eroare 1 😞
  };

  // Inchideti fisierul si eliberati resursele alocate
  fclose(fp);

  // Afisati un mesaj de succes
  printf("Memoria aplicatiei a fost citita si editata cu succes!\n");

  return 0; // Terminati programul cu codul de succes 0 🙌
}