#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define WORDLEN 5
#define MAX_WORDS 100


int parse_words(char *line, char wordlist[MAX_WORDS][WORDLEN + 1]) {
  int count = 0;
  char *tok;

  while ((tok = strsep(&line, " ")) != NULL && count < MAX_WORDS) {
    if (*tok == '\0') continue;
    if (strlen(tok) != WORDLEN) continue;

    strncpy(wordlist[count], tok, WORDLEN);
    wordlist[count][WORDLEN] = '\0';
    count++;
  }

  return count;
}

// the purpose of this function is to write all the words to words.txt
// we're going to find the words from a list online
void writeToFile(char * string) {

}
