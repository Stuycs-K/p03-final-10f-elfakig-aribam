#ifndef read_h
#define read_h
#define WORDLEN 5
#define MAX_WORDS 5
char *parse_args(int argc, char *argv[]);
read_CSV(char wordlist[MAX_WORDS][WORDLEN + 1]);
int load_csv_words(const char *filename, char wordlist[MAX_WORDS][WORDLEN + 1]);
#endif
