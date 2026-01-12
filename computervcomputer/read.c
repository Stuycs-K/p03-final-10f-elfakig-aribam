#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "wordle.h"
#include "errorfile.h"

void readCSV(char wordlist[MAX_WORDS][WORDLEN + 1]){
  FILE *csv_file = NULL;
  char buffer[80];

  csv_file = fopen("words.csv", "r");
  if (csv_file == NULL){ err(); }
  while(fgets(buffer, 80, csv_file)){
    //printf("%s", buffer);
  }

  for(int i = 0; i < MAX_WORDS;){
    for(int y = 1; ;y++){
      if(strncmp(buffer[i]), 1){

      }
    }
  }
  //strncmp

/*
  buffer = read(csv_file, &buffer, sizeof(char));
  if(buffer != sizeof(char)){
    if(buffer == 0){
      printf("nothing");
    } else{
        err();
     }
  }
  printf("buffer read %d chars, which are %c", buffer, &buffer);
*/

}
