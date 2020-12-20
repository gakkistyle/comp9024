//
//  Wordlist.h
//  9024作业
//
//  Created by 郑淇文 on 2020/1/11.
//  Copyright © 2020 郑淇文. All rights reserved.
//
#define Wordmax 30
typedef struct urlNode{
    char url[10];
    struct urlNode* next;
}urlNode;
//Node->url = malloc(sizeof(MAX))
typedef struct wordNode{
    char word[Wordmax];
    struct urlNode *urlcontains;
    struct wordNode *next;
}wordNode;

wordNode *InitwordNode();
urlNode *InitNode();

wordNode *MakewordNode(char *);
urlNode *MakeurlNode(char *);


int urlInList(urlNode*,char*);
int wordInList(wordNode*,char*);

void InsertUrlNode(urlNode*,char*);
void InsertWordNode(wordNode*,char*,char*);

void freewordlist(wordNode*);
void freeurllist(urlNode*);
