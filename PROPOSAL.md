# Final Project Proposal

## Group Members:

Moontaha Ariba, Ginwan Elfaki
       
# Intentions:

We are attempting to create a Wordle game using multiple clients connecting to one server. The goal is to see which player completes the game first.

# Intended usage:

The users will connect to the server as clients. Then, they can begin guessing the secret word (which is randomly chosen from a list of words) until they run out of guesses.

# Technical Details:

* allocating memory - we will store user input in buffers
* working with files - the list of words will be on a file, we will have to access (to check) and manipulate (if the computer is playing)
* processes - child processes must be forked to have multiple clients connect to a server
* pipes/sockets - to allow client-server connections
  
    
# Intended pacing:

Jan 6 - 7: files and libraries
Jan 7 - 9: create client-server connections
Jan 12 - 14: ensure gameplay
Jan 15: user interface Jan 16: testing
