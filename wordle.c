#include <time.h>
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
    w[0] = '\0';
    // compute the number of lines in the file
    int numWords = 2309; //fileSize() / 7;

    // choose a random line
    int l = rand() % numWords + 1;

    // loop through to get
    FILE * f = fopen("words.csv", "r");
    if (f == NULL) {
        perror("error opening file.");
        return;
    }
    char word[7];
    int line = 0;

    while (fgets(word, sizeof(word), f)) {
        line++;
        if (line == l) {
            word[strcspn(word, "\n")] = '\0'; // remove newline
            strcpy(w, word);
            break;
        }
    }
    if (w[0] == '\0') {
        strcpy(w, "error");
    }
    fclose(f);
}

int main(int argc, char *argv[]){
    srand(time(NULL));
    char w[6];
    chooseWord(w);

    char buff[6];
    printf("choose a 5-letter word:\n");
    fgets(buff, sizeof(buff),stdin);
    if (sizeof(buff) > 5) {
        printf("no more than 5 letters!");
    } else if (sizeof(buff) < 5) {
        printf("at least 5 letters!");
    }

    return 0;
}
