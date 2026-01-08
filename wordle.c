#include "networking.h"

int fileSize() {
    FILE * fp = fopen("words.csv", "r");
    if (fp == NULL) {
        printf("file not found\n");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    int s = ftell(fp);
    fclose(fp);
    return s;
}

void chooseWord(char * w) {
    // compute the number of lines in the file
    int numWords = fileSize() / 6;

    // choose a random line
    FILE * f = fopen("words.csv", "r");
    fgets(w, 5, f);
    char * line = w;
    w = "hi";
}

int main(int argc, int *argv[]){
  char allwords[64] = "berry";
  char words[64];
  char w[5];

  printf("%d\n", fileSize());

  return 0;
}
