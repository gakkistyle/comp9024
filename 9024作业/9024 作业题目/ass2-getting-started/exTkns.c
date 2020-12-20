/*
 Sample code to illustrate usage of "strtok", written by Ashesh Mahidadia Jan 2020.
 You may need to modify the following implementation and test it properly before using it  
 in your program.
*/


#include <string.h>
#include <stdio.h>

#define MAXSTRING 1000


int main () {

   char delim[2] = " ";
   char *token;
   char line[MAXSTRING] ;
   FILE *f;

   if ((f = fopen ("sample1.txt", "r")) == NULL) {
      printf("Error!\n");
      return (0);
   }

	
  int lnCount = 0;
  while(fgets(line, MAXSTRING, f) != NULL)  {

      printf( "> line %d] \n", ++lnCount);

      /* first token */
      token = strtok(line, delim);

      int count = 0;
      /* iterate over the rest of the tokens */
      while( token != NULL ) {
         printf( "      token %d) %s\n", ++count, token );
    
         token = strtok(NULL, delim);
      }

  }
   
   return(0);
}


