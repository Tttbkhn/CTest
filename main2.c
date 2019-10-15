#include <stdio.h>
#include <stdlib.h>
#include "devoir2.h"

int main() {

  char truekey[] = "macle";
  char permkey[] = "acelm";
  char pattern[] = "analyse";
  char message[] = "lacryptanalyseestlatechniquequiconsisteadeduireuntexteenclairduntextechiffresanspossederlacledechiffrement";
   
  printf("CHIFFREMENT\n----------\n");
  char *encryptedmess = encrypt(message, truekey);
  printf("Message original:\n%s\n", message);
  printf("Message chiffré:\n%s\n", encryptedmess);

  printf("\nDECHIFFREMENT\n----------\n");
  char *decmessage = decrypt(encryptedmess, truekey);
  printf("Message déchiffré:\n%s\n",decmessage);
  free(decmessage);

  /* generate and test all keys */
  printf("\nCRYPTANALYSE\n----------------\n");
  char *foundkey = test_all_key_permutations(encryptedmess, pattern, permkey);
  if (foundkey) {
    printf("Clé trouvée = %s\n", foundkey);
    char *decmessage = decrypt(encryptedmess, foundkey);
    printf("Message déchiffrés (contenant le pattern %s):\n%s\n", pattern, decmessage);
    free(decmessage);
  } else
    printf("Clé non trouvée\n");

  exit(0);

}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void rotate(char *arr, int d, int n) {
//     char *arr_rotate = malloc((n+1)*sizeof(char));
//     d = d % n;
//     if (d < 0){   // shift right
//             d = d + n;
//         }
//     for (int i = 0; i < n; i ++ ){
//         if (i < d){
//         arr_rotate[i] = arr[i - d + n];
//         }
//         else
//             arr_rotate[i] = arr[i - d];
//         //return arr_rotate;
//     }
// arr = arr_rotate;
// printf("%s\n", arr);
// printf("***\n");
// }

// void copy(char *arr) {
//     char *testarr = malloc(sizeof(char) * 4);
//     strncpy(testarr, arr, 5);
//     printf("%s\n", testarr);
// }

// int main() {
//     char *arr = "aidjc";
//     copy(arr);

    
    
// }
