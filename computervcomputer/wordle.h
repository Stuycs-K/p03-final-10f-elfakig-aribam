#ifndef WORDLE_H
#define WORDLE_H
#define WORDLEN 5
#define MAX_WORDS 5

void makelist(char list[MAX_WORDS][WORDLEN + 1]);
/*
int load_csv_words(const char *filename, char wordlist[MAX_WORDS][WORD_LEN + 1]);
char *parse_args(int argc, char *argv[]);
void print_words(char wordlist[MAX_WORDS][WORD_LEN + 1], int count);
*/
#endif
