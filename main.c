#include "wordle.h"

#define READ 0
#define WRITE 1

void handle_sigint(int sig) {
  (void)sig;
  printf("\nGiving up? Program was interrupted.\n");
  exit(0);
}

int main(int argc, char *argv[]){
  signal(SIGINT, handle_sigint);

  int maxwords = fileSize("words.csv") / 7;
  char ***wordlist = calloc(26, sizeof(char **));
  if (!wordlist) err();
  // allocate the wordlist's inner arrays
  for (int i = 0; i < 26; i++) {
    wordlist[i] = calloc(maxwords, sizeof(char *));
    if (!wordlist[i]) err();

    for (int j = 0; j < maxwords; j++) {
      wordlist[i][j] = calloc(WORDLEN + 1, sizeof(char));
      if (!wordlist[i][j]) err();
    }
  }

  srand(time(NULL));
  make_list("words.csv", wordlist, maxwords);
  char * targetword = choose_randword(wordlist);
  printf("randword is %s\n", targetword);

  char buffer[BUFFERSIZE];

  for (int i = 0; i < 6; i++) {
    prompter(buffer, i, wordlist);
    checkword(buffer, targetword);

    if (strcmp(buffer, targetword) == 0) {
      printf("Yay! The word was guessed correctly!\n");
      break;
    }

    if (i == 5) {
      printf("Sorry, the word was: %s\n", targetword);
    }
  }

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < maxwords; j++) {
      free(wordlist[i][j]);
    }
    free(wordlist[i]);
  }
  free(wordlist);
  return 0;
}
