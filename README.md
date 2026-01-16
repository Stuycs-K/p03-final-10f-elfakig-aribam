[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/QfAIDTGi)
# Wordle
 
### Vowels

Ginwan Elfaki and Moontaha Ariba
       
### Project Description:

We recreating the game Wordle on the terminal. The user is prompted to first choose a language from which the program chooses a random word as the secret word. Then, the user is prompted to type a 5-letter word that exists within the dictionary chosen. The letters are updated based on whether it's correctly placed (green), misplaced but in the word (yellow), or not in the secret word at all (white/gray). After the sixth incorrect guess, the secret word is revealed.

Here's a link to our presentation: https://drive.google.com/file/d/1-X98fXOAyHy3Tl_HickqVfH8_aKHau4p/view?usp=sharing 

#### Features: 

* Hard mode: The user may choose to play in hard mode, where there is a time-constraint of 20 seconds per guess. If the user fails to type a valid guess within that time, the program exits.
* Languages: Our wordle game can be played in Arabic, Bengali, Dutch, English, French, Italian, Spanish, Tagalog, and Vietnamese.

#### Files
##### main.c --> handles signals, prompts the user in a loop, and initializes arrays
##### wordle.c --> calculates the file size to calculate the maximum number of words in each file, error handling, readsCSV, fills the list of valid words, chooses the random word, checks if the guess is valid, checks the status of each letter in the guessed word, function for automated prompting
##### wordle.h --> contains all libraries, definitions, and function headers

### Instructions:

The game can be played by compiling and running it on a terminal. using "make compile" and "make run" is one way. The user must type in a character for the first two prompts, then type in 5-letter words for the next 6 guesses.

### Resources/ References:

* Methods of implementing a timer: https://www.oreateai.com/blog/summary-of-various-methods-to-implement-timers-in-linux/ff40e962ff0fa5ca7cea5d774c9cea47
* How to use SIGALRM: https://stackoverflow.com/questions/21542077/c-sigalrm-alarm-to-display-message-every-second