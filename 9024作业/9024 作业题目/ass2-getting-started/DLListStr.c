/*
 Implementation of doubly-linked list ADT for string values.
 Written by Ashesh Mahidadia Jan 2020, based on code writted by John Shepherd 2015.
 You may need to modify the following implementation and test it properly before using 
 in your program.
*/


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "DLListStr.h"

// data structures representing DLListStr

typedef struct DLListNode {
	char   value[100];  // value of this list item (string)
	struct DLListNode *prev;
	               // pointer previous node in list
	struct DLListNode *next;
	               // pointer to next node in list
} DLListNode;

typedef struct DLListRep {
	int  nitems;      // count of items in list
	DLListNode *first; // first node in list
	DLListNode *curr;  // current node in list
	DLListNode *last;  // last node in list
} DLListRep;

// create a new DLListNode (private function)
static DLListNode *newDLListNode(char *val)
{
        DLListNode *new;
        new = malloc(sizeof(DLListNode));
        assert(new != NULL);

        strcpy(new->value, val);  // for int, new->value = it;
	
        new->prev = new->next = NULL;
        return new;
}

// create a new empty DLListStr
DLListStr newDLListStr()
{
	struct DLListRep *L;

	L = malloc(sizeof (struct DLListRep));
	assert (L != NULL);
	L->nitems = 0;
	L->first = NULL;
	L->last = NULL;
	L->curr = NULL;
	return L;
}


/* 
   pre-reqisite: L is ordered (increasing) with no duplicates
   post-condition: val is inserted in L, L is ordered (increasing) with no duplicates
*/
void insertSetOrd(DLListStr L, char *val){

	/* 
	   implement this function to
	   insert val in L  (in order), no duplicates (set)

	*/

}



// display items from a DLListStr, comma separated
void showDLListStr(DLListStr L)
{
	assert(L != NULL);
	DLListNode *curr;
	int count = 0;
	for (curr = L->first; curr != NULL; curr = curr->next){
		count++;
		if(count > 1) {
			fprintf(stdout,", ");
		}
		fprintf(stdout,"%s",curr->value);
	}
	fprintf(stdout,"\n");
}


// free up all space associated with list
void freeDLListStr(DLListStr L)
{
	assert(L != NULL);
	DLListNode *curr, *prev;
	curr = L->first;
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(L);
}


