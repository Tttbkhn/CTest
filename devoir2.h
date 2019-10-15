#ifndef _devoir2_H
#define _devoir2_H

char *encrypt(char *message, char *key);
char *decrypt(char *message, char *key);
int search_pattern(char *pattern, char *message);
void rotate(char *arr, int d, int n);
char *test_all_key_permutations(char *encmessage, char *pattern, char *key);

#endif
