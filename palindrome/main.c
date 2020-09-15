#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char *argv[]) {
  char *line;
  int size;
  char *output;
  
  size = 100;
  line = (char*) calloc (size + 1, sizeof(char));

  // fgets reads a line from stdin (usually the keyboard)
  // and returns it in the buffer passed as the first argument
  // (line here). If there's no more input to read from, it
  // returns NULL.
  while (fgets(line, size, stdin) != NULL) {
    // This crazy line removes the '\n' at the end of the input line.
    // Without it, nothing will ever be a palindrome, unless it happens
    // to somehow start with a '\n'.
    line[strcspn(line, "\n")] = '\0';
    //
    // We need this here in order to free the variable because
    // if we have it in the print statement it called palindrome 
    // every time with no way to free it.
    //
    output = palindrome(line);
    //
    // Replaced the palindrome method call with the new variable.
    //
    printf("Is the string <%s> a palindrome? %s\n", line, output);
    //
    // Freeing the new variable
    //
    free(output); 
  }

  free(line);
}
