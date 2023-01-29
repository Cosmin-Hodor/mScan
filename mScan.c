#include <stdio.h>
#include <stdlib.h>

// Define the size of the buffer for reading and writing data
// Definiti dimensiunea buffer-ului pentru citirea si scrierea datelor
#define BUFFER_SIZE 1024

int main() {
  // Declare a FILE * variable to hold the reference to the opened file
  // Declarati variabila de tip FILE * pentru a retine referinta catre fisierul deschis
  FILE *fp;

  // Open the file for reading and writing using the "rw" mode
  // Deschideti fisierul pentru citire si scriere folosind modul "rw" 📁
  
  // Change the new of the file to the desired one ("memory.dat" -> "vscode.exe")
  // Schimbati numele fisierului cu cel dorit ("memory.dat" -> "vscode.exe")
  fp = fopen("memory.dat", "rw");
  if (fp == NULL) {
    // Display an error message if the file could not be opened
    // Afisati un mesaj de eroare daca fisierul nu a putut fi deschis
    printf("Eroare: fisierul nu poate fi deschis!\n");
    // End the program with error code 1
    // Terminati programul cu codul de eroare 1
    return 1; 
  };

  // Declare a buffer for reading and writing data from and to the file
  // Declarati un buffer pentru citirea si scrierea datelor din si in fisier ✍️
  char buffer[BUFFER_SIZE];

  // Read the data from the file and store it in the buffer
  // Cititi datele din fisier si stocati-le in buffer
  if (fread(buffer, BUFFER_SIZE, 1, fp) != 1) {
    // Display an error message if the data could not be read from the file
    // Afisati un mesaj de eroare daca datele nu au putut fi citite din fisier
    printf("Eroare: datele nu au putut fi citite din fisier!\n");
    return 1; // Terminati programul cu codul de eroare 1
  };

  // Modificati datele din buffer dupa cum este necesar
  for (int i = 0; i < BUFFER_SIZE; i++) {
    // In this example, we reverse each byte in the buffer
    // Any data manipulation method can be used in this iteration

    // In acest exemplu, inversam fiecare octet din buffer
    // Orice metoda de manipulare se poate folosi in aceasta iteratie 👀
    buffer[i] = ~buffer[i];
  };

  // Write the modified data back to the file
  // Scrieti datele modificate inapoi in fisier
  if (fwrite(buffer, BUFFER_SIZE, 1, fp) != 1) {
    
    // Display an error message if the data could not be written to the file
    // Afisati un mesaj de eroare daca datele nu au putut fi scrise in fisier
    printf("Eroare: datele nu au putut fi scrise in fisier!\n");
    
    // End the program with error code 1
    // Terminati programul cu codul de eroare 1 😞
    return 1;
  };

  // Close the file and free up the allocated resources
  // Inchideti fisierul si eliberati resursele alocate
  fclose(fp);

  // Display a success message
  // Afisati un mesaj de succes
  printf("Memoria aplicatiei a fost citita si editata cu succes!\n");
  
  // End the program with success code 0
  // Terminati programul cu codul de succes 0 🙌
  return 0; 
};
