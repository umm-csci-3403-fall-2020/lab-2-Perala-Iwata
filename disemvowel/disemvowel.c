#include <stdlib.h>

#include "disemvowel.h"

char *disemvowel(char *str) {

  // Declaring variable for the string length.
  // This length will also be used to allocate space in the array.
  int len, i;
  // Used to hold the original string to parse through looking for vowels.
  char *strHolder;
  // Where the altered string will be placed to return at the end.
  char *result;

  // Current length of the str input.
  len = strlen(str);

  // Array to hold the original str input for parsing.
  strHolder = (char*) calloc(len + 1, sizeof(char));

  // Iterating through the original str input to count any present vowels.
  // This will then de-increment the len variable so we can allocate an
  // Appropriate amount of space in the array for the new string.
  // Incrementing the i variable using prefix might cause issues, use postfix?
  for (i = 0; i < len; ++i) {

	// Disgusting if statement to check for uppercase or lowercase
	// vowels and index i.
	// This might be better achieved with a vector but I am not super
	// familiar with that structure in this language.
  	if (strHolder[i] == 'a' 
             | strHolder[i] == 'e' 
	     | strHolder[i] == 'i'  
	     | strHolder[i] == 'o' 
	     | strHolder[i] == 'u' 
	     | strHolder[i] == 'A' 
	     | strHolder[i] == 'E' 
	     | strHolder[i] == 'I' 
	     | strHolder[i] == 'O' 
	     | strHolder[i] == 'U'
				  ){
	--len;
	}
  }
  
  // Freeing the array used to hold the initial str input.
  // Actually probably need this later but I can come back to it.
  free(strHolder);

  // Setting up the result array with an amount of space appropriate for after
  // the original str input has been disemvoweled.
  result = (char*) calloc(len + 1, sizeof(char));

  for(i = 0; i < len; ++i) {
  	
  }

  return result;
}
