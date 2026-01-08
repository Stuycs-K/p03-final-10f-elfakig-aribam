#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "read.h"
#include "write.h"
#include "errorfile.h"

int main(){
  char allwords[30] = "apple batch berry deter hands";
  char * words[6];
  parse_words(allwords, words);
  for(int x = 0; x < 6; x++){
    printf("/nword #%d is: ", x);
    for(int y = 0; y < 6; y++){
    }
  }
  return 0;
}
