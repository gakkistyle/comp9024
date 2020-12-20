//
//  Wordlist.h
//  9024作业
//
//  Created by 郑淇文 on 2020/1/11.
//  Copyright © 2020 郑淇文. All rights reserved.
//
#define Wordmax 40
#define urllength 20
//urlNode for recording the url's name and the sequence of urls.
typedef struct urlNode{
    char url[urllength];
    struct urlNode* next;
}urlNode;

//wordNode for recording the sequence of words and every url which have the word.
typedef struct wordNode{
    char word[Wordmax];
    struct urlNode *urlcontains;
    struct wordNode *next;
}wordNode;

//initialize the urls and words;
wordNode *InitwordNode();
urlNode *InitNode();

//make the new word and url
wordNode *MakewordNode(char *);
urlNode *MakeurlNode(char *);

//check if an url or word in the list.
int urlInList(urlNode*,char*);
int wordInList(wordNode*,char*);

//insert the url or word to the right place(already sorted after each inserting)
void InsertUrlNode(urlNode*,char*);
void InsertWordNode(wordNode*,char*,char*);

//free the url and the word list.
void freewordlist(wordNode*);
void freeurllist(urlNode*);
