#include <time.h>

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

int isValid(char * word) { // 0 = valid; 1 = invalid
    int v = 0;
    for (int i = 0; word[i]; i++) {
        if (word[i] < 'A' || word[i] > 'z' || (word[i] > 'Z' && word[i] < 'a')) {
            v = 1;
            break;
        }
    }
    return v;
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
    char buff[256];

    while (1) {
        printf("choose a 5-letter word:\n");

        if (fgets(buff, sizeof(buff), stdin) == NULL) {
            printf("exiting...\n");
            break;
        }

        if (strlen(buff) > 6) {
            printf("no more than 5 letters!\n\n");
        } else if (strlen(buff) < 6) {
            printf("at least 5 letters!\n\n");
        } else {
            if (isValid(buff)) {
                printf("characters only!\n\n");
            } else {
                break;
            }
        }
    }

    return 0;
}
