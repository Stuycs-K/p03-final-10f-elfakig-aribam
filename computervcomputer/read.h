#ifndef read_h
#define read_h
char *parse_args(int argc, char *argv[]);
int load_csv_words(const char *filename, char wordlist[MAX_WORDS][WORD_LEN + 1]);
#endif
