#include "wordle.h"
#define BOLD_GREEN          "\033[1;32m"

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

int isValid(char * word) { // 0 = invalid; 1 = valid
    int v = 0;

    // check if the word exists
    FILE * f = fopen("words.csv", "r");
    if (f == NULL) {
        printf("file not found\n");
        return -1;
    }
    char line[6];

    while (fgets(line, sizeof(line), f)) {
        if (strncmp(word, line, 5) == 0) {
            v = 1;
            break;
        }
    }
    fclose(f);
    return v;
}

// int isValid(char * word) { // 0 = invalid; 1 = valid
//     int v = 0;
//
//     // length check
//     if (strlen(word) > 6) {
//         printf("no more than 5 letters!\n\n");
//     } else if (strlen(word) < 6) {
//         printf("at least 5 letters!\n\n");
//     } else {
//         // check if the word exists
//         FILE * f = fopen("words.csv", "r");
//         if (f == NULL) {
//             printf("file not found\n");
//             return -1;
//         }
//         char line[6];
//
//         while (fgets(line, sizeof(line), f)) {
//             if (strncmp(word, line, 5) == 0) {
//                 v = 1;
//                 break;
//             }
//         }
//         fclose(f);
//     }
//     return v;
// }

void chooseWord(char * w) {
    // compute the number of lines in the file
    int numWords = fileSize() / 7;

    // choose a random line
    int l = rand() % (numWords + 1);

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
    if (word[0] == '\0') {
        strcpy(w, "error");
    }
    fclose(f);
}

void printColor(char * ans, char * input) {
    // green - matches
    for (int i = 0; i < 6; i++) {
        if (ans[i] == input[i]) {
            printf("\033[1;32m%c\033[1;32m", ans[i]);
        }
    }
}

int main(int argc, char *argv[]){
    // let the user know we're choosing a word
    printf("choosing a word...\n");
    srand(time(NULL));
    char w[7];
    chooseWord(w);
    while (strcmp("error", w) == 0) {
        chooseWord(w);
    }
    sleep(1);
    printf("word chosen: %s\n", w);

    char buff[256];
    while (1) {
        printf("guess the 5-letter word.\n");

        if (fgets(buff, sizeof(buff), stdin) == NULL) {
           printf("exiting...\n");
           break;
        }

        if (strlen(buff) > 6) {
            printf("no more than 5 letters!\n\n");
        } else if (strlen(buff) < 6) {
            printf("at least 5 letters!\n\n");
        } else {
            if (!isValid(buff)) {
                printf("I don't know this word. Try again.\n\n");
            } else {
                break;
            }
        }
    }

    printColor(w, buff);

    // for (int guess = 1; guess < 7; guess++) {
    //     if (strncmp(w, buff, 5) != 0) {
    //         printf("Guess #%d: %s", guess, buff);
    //         fgets(buff, sizeof(buff), stdin);
    //     } else {
    //         printf("correct!\n");
    //     }
    // }

    return 0;
}
