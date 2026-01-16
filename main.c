#include "wordle.h"

#define READ 0
#define WRITE 1

void handle_sigint(int sig) {
  (void)sig;
  printf("\nGiving up? Program was interrupted.\n");
  exit(0);
}

void handle_alarm(int sig) {
  (void)sig;
  printf("\n Time's up! Game over.\n");
  exit(0);
}

int main(int argc, char *argv[]){
  signal(SIGINT, handle_sigint); // quit
  signal(SIGALRM, handle_alarm); // timer

  char buffer[BUFFERSIZE];
  srand(time(NULL));

  // ask which language
  char * dict;
  printf("Choose a dictionary - English (e), Spanish (s): ");
  while (fgets(buffer, BUFFERSIZE, stdin)) {
    if (buffer[0] == 'e') {
      printf("You chose English.\n");
      dict = "words.csv";
      break;
    } else if (buffer[0] == 's') {
      printf("You chose Spanish.\n");
      dict = "spanish.csv";
      break;
    } else {
      printf("Please choose English or Spanish.");
    }
  }

  int maxwords = fileSize(dict) / 7;
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
  make_list(dict, wordlist, maxwords);
  char * targetword = choose_randword(wordlist);
  printf("randword is %s\n", targetword);

  // hard mode option - timer
  int hard_mode = 0; // default: no
  char choice;
  printf("Enable hard mode? (y/n): ");
  if (fgets(buffer, BUFFERSIZE, stdin)) {
    if (buffer[0] == 'y') {
      printf("Hard mode enabled. You have 20 secs to type each guess.\n");
      hard_mode = 1;
    }
  }

  for (int i = 0; i < 6; i++) {
    if (hard_mode) alarm(20);

    prompter(buffer, i, wordlist);
    if (hard_mode) alarm(0);
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
