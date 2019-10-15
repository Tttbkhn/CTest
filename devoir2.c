
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "devoir2.h"

char *lettres = "abcdefghijklmnopqrstuvwxz";

char *encrypt(char *message, char *key) {
  int keylength = strlen(key);
  int messlength = strlen(message);
  int nrows = ceil(messlength*1.0/keylength);

  /* allocation d'un tableau pour stocker le message déchiffré */
  char *tab = malloc((nrows*keylength+1)*sizeof(char));

  if (!tab) {
    printf("Erreur d'allocation de mémoire dans encrypt\n");
    exit(-1);
  }
  
  /* remplissage du vecteur selon la règle */
  int i;
  for (i = 0; i < messlength; i++)
    tab[(i % keylength)*nrows+(i/keylength)] = message[i];

  /* remplissage de la fin aléatoirement */
  for (; i < nrows*keylength; i++){
    //i = 109, 108, 107, 106
tab[(i % keylength)*nrows+(i/keylength)] = lettres[rand() % 26];
  }
    
  tab[i] = '\0';
  
  /* rotation des colonnes selon la clé */  
  for (i = 0; i < keylength; i++) {
    rotate(tab+i*nrows, (key[i]-'m'), nrows);
  }
  return tab;
}


int search_pattern(char *pattern, char *message) {
  return -1;
}

char *decrypt(char *message, char *key) {
  return NULL;
}

char *test_all_key_permutations(char *encmessage, char *pattern, char *key) {
  return NULL;
}

//n=22
void rotate(char *arr, int d, int n) { 
  printf("%s\n", arr);
char *test = malloc(sizeof(char));
strncpy(test, arr, n);
int i;
char *m = "bcde";
for (i=0; i< 5; i++) {
  *(arr+i) = *(m+i);
}
printf("%s\n", test);
// char *m = "bcscdscdc";
// *arr = *m;
// *(arr+1) = *(m+1);
// printf("%d\n", strlen(m));
// printf("%s\n", arr);
}
