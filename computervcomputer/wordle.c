#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "read.h"

void makelist(list[MAX_WORDS][WORDLEN + 1]){
  for (int x = 1; x < 27; x++) {
    wordlist[0][x - 1] = 96 + x;
    printf("wordlist[0][%d] = %c\n", x - 1, wordlist[0][x - 1]);
  }
  wordlist[0][26] = '\0';
  readCSV();
  /*
  strcpy(wordlist[1], "apple");
  printf("wordlist[1] = %s\n", wordlist[1]);
  */
}
