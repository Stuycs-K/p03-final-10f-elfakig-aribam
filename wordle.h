#ifndef WORDLE_H
#define WORDLE_H

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
#define RESET "\033[0;37m"
#define BUFFERSIZE 32
#define WORDLEN 5

int fileSize(char * filename);
void err(void);

char *choose_randword(char ***wordlist);
void make_list(char *file, char ***wordlist, int maxwords);
void checkword(char *guess, char *target);
int validword(char * buffer, char ***wordlist);
void prompter(char *buffer, int attempt, char***);
#endif
