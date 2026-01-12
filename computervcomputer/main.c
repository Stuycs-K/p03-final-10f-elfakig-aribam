#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "wordle.h"

//1. pick a random word
//2. have computer pick another random word
//3. check the similairty between the two.
//4. remove words from the list based on this

int main(){
  char wordlist[100][27];
  makelist(wordlist);
  return 0;
}
