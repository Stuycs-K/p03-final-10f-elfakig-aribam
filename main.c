#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "write.c"

int main(){
  char wordlists[] = "apple cattle berry";
  char *words[4];

  parse_words(wordlists, words);
  for (int i = 0; words[i] != NULL; i++) {
    printf("Word %d: %s\n", i, words[i]);
    for (int j = 0; words[i][j] != '\0'; j++) {
      printf("  Letter %d: %c\n", j, words[i][j]);
    }
  }

  return 0;
}
