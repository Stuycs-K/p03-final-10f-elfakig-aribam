# Dev Log:

This document must be updated daily every time you finish a work session.

## Moontaha Ariba

### 2026-01-06 - Brief description
* 3 minutes - created initial files
* 10 minutes - finalized plan; changed from computer vs. computer to changed computer vs. human

### 2026-01-07
* 5 mins - fixed merge conflicts
* 10 mins - figured out logic for reading/writing to words.txt; began write.txt
* 5 mins - change of plans: delete write.txt; use a words.csv file; use a library-like structure
* 4 mins - wrote networking.h
* 3 mins - fixed merge and branch issues
* 2 mins - added words.csv

### 2026-01-08
* 5 mins - seperated work from Ginwan's; I'm working on the wordle game itself being played by a human
* 5 mins - calculating file size function
* 10 mins - worked on choosing a word function
* 5 mins - organized files
* 20 mins - chooseWord: returns a random word from the csv file. returns blank some times, returns a random word sometimes.

### 2026-01-09
* 5 mins - tested existing code, found bugs in chooseWord (works, but chooses the same word twice in a row almost always)
* 10 mins - worked on main logic to check for validity of word
* 10 mins - made new function called isValid that checks if word is only characters
* 5 mins - checked for null or exit commands
* 5 mins - refined printed messages
* 5 mins - organized files

### 2026-01-12
* 5 mins - organized files, removed unnecessary files, moved info into diff files
* 10 mins - fixed isValid to check if word is in the list, updated main accordingly
* 15 mins - fleshed out looping logic for guessing
* 7 mins - fixed chooseWord to ensure a blank/error never occurs
* 15 mins - tried to fix number of guesses logic; problem: input's validity is no longer being checked; succeeded in checking if the word itself matches the secret word
* 5 mins - began checking the status of each letter (color); this is incomplete; I need to loop through each letter of the user's word and the program's word to ensure they match (green), are in the word (yellow), or are not in the word (blue).

### 2026-01-13
* 10 mins - updated printColor and isValid; attempt to make isValid a part of the asking process
* 5 mins - continued working on wordle.c, failed to loop to ask user for guesses in a coherent manner
* 10 mins - integrated Ginwan's working wordle.c with mine (+ moved, copied files)
* 10 mins - added colors (green for correct position, yellow for misplaced letter) to the terminal using ANSI escape sequences
* 10 mins - fixed some bugs: Ctrl-D exits, removed error-causing code
* 5 mins - organized libraries and files

### 2026-01-14
* 5 mins - tested
* 5 mins - discussion on what to add to project
* 10 mins - figuring out logic: calculate fileSize -> calculate number of words, change randomization/search to use the number of lines/words
* 10 mins - updated file organization, added different language libraries
