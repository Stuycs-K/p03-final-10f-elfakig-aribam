#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


char *parse_words(char *line, char **arg_ary) {
  int i = 0;
  char *tok;

  while ((tok = strsep(&line, " ")) != NULL && i < 5) {
    if (*tok != '\0') {
      arg_ary[i++] = tok;
    }
  }
  arg_ary[i] = NULL;
  return arg_ary[0];
}

// the purpose of this function is to write all the words to words.txt
// we're going to find the words from a list online
void writeToFile(char * string) {

}
