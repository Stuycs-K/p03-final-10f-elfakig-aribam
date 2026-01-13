#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
/*
void readCSV(){
  int csv_file;
  int buffer;

  csv_file = open("words.txt", O_RDONLY, 0611);
  if (csv_file == -1){ err(); }

  buffer = read(r_file, &buffer, sizeof(int));
  if(buffer != sizeof(int)){
    if(buffer == 0){
      printf("nothing");
    } else{
        err();
     }
  }
  printf("buffer = %s", buffer):

}

/*
int readf(){
  int r_file;
  int buffer;

  r_file = open("words.txt", O_RDONLY, 0611);
  if(r_file == -1){
    printf("r_file: %u\n", r_file);
    err();
  }


  buffer = read(r_file, &x, sizeof(int));
  if(buff != sizeof(int)){
    if(buff == 0){
      printf("nothing");
    } else{
        err();
     }
  }
  buff = read(r_file, &y, sizeof(int));
  if(buff != sizeof(int)){
    if(buff == 0){
      printf("nothing");
    } else{
        err();
      }
  }
  buff = read(r_file, arr, sizeof(int)*8);
  if(buff != sizeof(int) * 8){
    if(buff == 0){
      printf("nothing");
    } else{
        err();
      }
  }

  printf("Reading numbers from file..\n");
  printf("x : %d = %c\n", x, x);
  printf("y : %d = %c\n", y, y);
  for(int i = 0; i < 8; i++){
    printf("arr[%d] : %d = %c\n", i, arr[i], arr[i]);
  }


  return 0;
}*/
