Name: Prayanshu Narayan S# 101144277

Description of program:
This program is meant for the Carleton University Ghost hunting society. It
prompts the user for pairwise data which represents data collected during a ghost hunt
and prints this data in a nice way. 

Files and purpose;
README.md: this file. 
init.c: File to intialize the evidence array, and type. Also holds the load evidence functio
defs.h: header file
main.c: main file
evidence.c: handles all the functions involing evidence types and array. 


Instructions for compiling the program:
type " gcc -Wall -Wextra -o a3 main.c init.c evidence.c -std=c11"

Instructions for running the program:
type "./a3"
Then follow the prompts in the terminal

MAIN MENU
  (1) Add evidence
  (2) Delete evidence
  (3) Print evidence
  (0) Exit

Can also use a txt file for input and output like this:
type: "./a3 < testcases.txt > testout.txt"




Instructions for how to use the program once it is running:
Enter Room ID and EMF value until "-1 -1" are entered. 
