#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <ctype.h>

#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"

#ifndef WORDLE_H
#define WORDLE_H

#define BUFFERSIZE 32
#define WORDLEN 5
#define MAXWORDS 264



char *choose_randword(void);
void err();
void make_list(char *file);
void checkword(char *guess, char *target);
int validword(char * buffer);
void prompter(char *buffer, int attempt);
#endif