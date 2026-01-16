#include "wordle.h"

int word_count[26];

int fileSize(char * filename) {
    FILE * fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("file not found\n");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    int s = ftell(fp);
    fclose(fp);
    return s;
}

void err() {
  printf("errno %d\n", errno);
  printf("%s\n", strerror(errno));
  exit(1);
}

void read_CSV(FILE *csv_file, char ***wordlist, int maxwords){
  char buffer[WORDLEN + 1];

  while (fscanf(csv_file, "%5s", buffer) == 1) {
    for (int i = 0; buffer[i]; i++) {
      buffer[i] = tolower(buffer[i]);
    }

    int col = buffer[0] - 'a';

    if (col >= 0 && col < 26 && word_count[col] < maxwords) {
      strcpy(wordlist[col][word_count[col]], buffer);
      word_count[col]++;
    }
  }
}

void make_list(char *file, char ***wordlist, int maxwords){
  FILE *wordf = fopen(file, "r");
  if (!wordf) {
    perror("Couldn't open words.csv");
    return;
  }

  for (int i = 0; i < 26; i++) {
    word_count[i] = 0;
  }

  read_CSV(wordf, wordlist, maxwords);
  fclose(wordf);
}

char *choose_randword(char ***wordlist){
  int col = rand() % 26;
  while (word_count[col] == 0) {
      col = rand() % 26;
  }

  int i = rand() % word_count[col];
  return wordlist[col][i];
}

void checkword(char *guess, char *targetword) {
  printf("Checking word.. ");
  for (int i = 0; i < WORDLEN; i++) {
    char g = tolower(guess[i]);
    char t = tolower(targetword[i]);

    if (g == t) {
      printf(GREEN "%c " RESET, g);
    } else {
        int found_elsewhere = 0;
        for (int j = 0; j < WORDLEN; j++) {
          if (g == tolower(targetword[j])) {
            found_elsewhere = 1;
            break;
          }
      }

      if (found_elsewhere) {
          printf(YELLOW "%c " RESET, g);;
      } else {
          printf("%c ", g);
      }
    }
  }//for loop
printf("\n");
}

int validword(char *buffer, char ***wordlist) {
  if (strlen(buffer) != WORDLEN) return 0;

  char temp[WORDLEN + 1];
  for (int i = 0; i < WORDLEN; i++) temp[i] = tolower(buffer[i]);
  temp[WORDLEN] = '\0';

  int col = temp[0] - 'a';
  if (col < 0 || col >= 26) return 0;

  for (int i = 0; i < word_count[col]; i++) {
    if (strcmp(wordlist[col][i], temp) == 0) {
      strcpy(buffer, temp);
      return 1;
    }
  }
  return 0;
}

void prompter(char *buffer, int attempt, char ***wordlist) {
  char autoresponses[6][40] = {
    "Please enter a valid 5-letter word: ",
    "Type your second guess: ",
    "Type your third guess: ",
    "Type your fourth guess: ",
    "Type your fifth guess: ",
    "Type your final guess: "
  };

  while (1) {
    if (attempt < 6) {
      printf("%s", autoresponses[attempt]);
    } else {
        printf("Enter a 5-letter word: ");
     }

    if (!fgets(buffer, BUFFERSIZE, stdin)) {
      printf("exiting...");
      return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    if (validword(buffer, wordlist)) {
        break;
    }

    printf("Invalid word, try again.\n");
  }
}
