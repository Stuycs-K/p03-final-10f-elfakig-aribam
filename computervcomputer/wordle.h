#ifndef WORDLE_H
#define WORDLE_H
#define BUFFERSIZE 32
#define WORDLEN 5
#define MAXWORDS 264
char wordlist[26][MAXWORDS][WORDLEN + 1];
int word_count[26];

char *choose_randword(void);
void err();
void make_list(char *file);
void checkword(char *guess, char *target);
int validword(char * buffer);
void prompter(char *buffer, int attempt);
#endif
