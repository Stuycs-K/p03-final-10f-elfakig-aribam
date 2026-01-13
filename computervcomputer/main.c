#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include "wordle.h"
#define READ 0
#define WRITE 1

int main(int argc, char *argv[]){
  srand(time(NULL));
  make_list("words.csv");
  /*for(int a = 0; a < 1; a++){
    for(int i = 0; i < word_count[a]; i++){
      printf("wordlist[%d][%d][6] = %s\n", a, i, wordlist[a][i]);
    }
  }*/
  char * targetword = choose_randword();
  printf("randword is %s\n", targetword);

  char buffer[BUFFERSIZE];

  char fifoName[] = "childpipe";
  mkfifo(fifoName, 0666);

  int ptoc[2];

    if (pid == 0) { // child
    }else{}

  for (int i = 0; i < 5; i++) {
    prompter(buffer, i);
    checkword(buffer, targetword);

    if (strcmp(buffer, targetword) == 0) {
      printf("Yay! The word was guessed correctly!\n");
      break;
    }

    if (i == 4) {
      printf("Sorry, the word was: %s\n", targetword);
    }
  }
  return 0;
}

//1. pick a random word
//2. have computer pick another random word
//3. check the similairty between the two.
//4. remove words from the list based on this

/* main.c, reads stuff from terminal and calls relevent functiosn
*/

/* wordle.c
    - makes lsit
    - handles list logic, i.e parse args, remove args ect

*/
