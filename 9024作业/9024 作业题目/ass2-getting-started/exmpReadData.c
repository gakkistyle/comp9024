#include <string.h>
#include <stdio.h>

#include "Graph.h"
#include "InvertedIdx.h"


/*
  A possible way to read data ... 

*/


void readSection1(char *urlname, Graph g){

/*
   let's say urlname is "url31"
   Open "url31.txt"
   read Section-1 
	(How?, a simple approach ... 
	 skip lines until first two tokens are "#start" and  "Section-1"
	 read lines (tokens) and add the required links in graph g
	 stop reading when first two tokens are "#end" and  "Section-1"
	)
*/


}


void readSection2(char *filename, InvertedIdx idx){

/*
   let's say filename is "url31.txt"
   Open "url31.txt"
   read Section-2 
	(How?, a simple approach ... 
	 skip lines until first two tokens are "#start" and  "Section-2"
	 read lines (tokens) and add  words (normalised) in inverted index ADT idx
	 stop reading when first two tokens are "#end" and  "Section-2"
	)
*/

}



