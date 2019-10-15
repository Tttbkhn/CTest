
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "devoir1.h"


char *lettres = "abcdefghijklmnopqrstuvwxz";

char *encrypt(char *message, char *key) {
  int keylength = strlen(key);  //p
  int messlength = strlen(message);   //n
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
  for (i = messlength ; i < nrows*keylength; i++)           //for (; i < nrows*keylength; i++)
    tab[(i % keylength)*nrows+(i/keylength)] = lettres[rand() % 26];
  tab[i] = '\0';

  /* rotation des colonnes selon la clé */
  for (i = 0; i < keylength; i++) {
    // rotate(tab+i*nrows, (key[i]-'m'), nrows);
  }

  return tab;
}


int search_pattern(char *pattern, char *message) {
  int pos;
  char *ptr;
  ptr = strstr(message, pattern);   //tra ve con tro dau tien cua pattern xuat hien trong message

if (ptr != NULL) // Substring found */
	{
    pos = ptr - message;
		return pos;
	}
	else // Substring not found */
	{
		return -1;
	}
}

char *decrypt(char *message, char *key) {
  int keylength = strlen(key);  //p
  int messlength = strlen(message);   //p*nrows
  int nrows = ceil(messlength/keylength);

  /* allocation d'un tableau pour stocker le message déchiffré */
  char *tab = malloc((messlength+1)*sizeof(char));

   if (!tab) {
    printf("Erreur d'allocation de mémoire dans encrypt\n");
    exit(-1);
  }

  for (int i = 0; i < keylength; i++) {
    rotate(message+i*nrows, 'm' - key[i], nrows);
  }
  for (int i = 0; i < messlength; i++){
    message[(i % keylength)*nrows+(i/keylength)] = tab[i];
  }

  return tab;
}

char *test_all_key_permutations(char *encmessage, char *pattern, char *key) {
  int lengkey = strlen(key);
  permute(encmessage, pattern, key, 0, lengkey -1);  //permute(char *encmessage, char *pattern, char *str, int l, int r)
  printf(key);
  return NULL;
}

void rotate(char *arr, int d, int n) {
    char *arr_rotate = malloc((n+1)*sizeof(char));
    d = d % n;
    if (d < 0){   // shift right
            d = d + n;
        }
    for (int i = 0; i < n; i ++ ){
        if (i < d){
        arr_rotate[i] = arr[i - d + n];
        }
        else
            arr_rotate[i] = arr[i - d];
        //return arr_rotate;
    }
    arr_rotate[n] = NULL;
arr = arr_rotate;
printf(arr);
printf("\n***\n");
}

// Permutation
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//*str is the string, l is the starting index, r is the ending index
int permute(char *encmessage, char *pattern, char *str, int l, int r)
{
    //char *decmessage = malloc(sizemess * sizeof(char));
    int i;
    if (l == r){
        printf("%s\n", str);
        char *decmessage = decrypt(encmessage, str);     //char *decrypt(char *message, char *key)
        int ind = search_pattern(pattern, decmessage);    //int search_pattern(char *pattern, char *message)
        if(ind) {
          printf("\nFound true key is %s",str );
          printf("\nMessage is %s", decmessage);
         return 0;
        }
    }
        
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((str + l), (str + i));
            permute(encmessage,pattern, str, l + 1, r);
            swap((str + l), (str + i)); //backtrack
        }
    }
}

//void rotate(char *arr, int d, int n) {};
/*
int search_pattern(char *pattern, char *message) {
    int pattlength = strlen(pattern);
    int messlength = strlen(message);
    int compare;
    int i;
    for (i = 0; i < (messlength - pattlength + 1); i ++){
            for (j = 0; j < pattlength; i ++){
                    compare = strcmp(pattern[j],message[i + j]);
                if (!compare) break;
            }
            if (compare == 0)
                return i;   //////////
                else return -1;
    }
  //return -1;
}*/