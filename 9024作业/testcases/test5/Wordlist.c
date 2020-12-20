//
//  Wordlist.c
//  9024作业
//
//  Created by 郑淇文 on 2020/1/11.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include "Wordlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

wordNode *InitwordNode(){
    wordNode *new;
    new = malloc(sizeof(wordNode));
    strcpy(new->word, " ");
    new->next = NULL;
    new->urlcontains = NULL;
    return new;
}

urlNode *InitNode(){
    urlNode *new ;
    new = malloc(sizeof(urlNode));
    strcpy(new->url, " ");
    new->next = NULL;
    return new;
}

urlNode *MakeurlNode(char *url){
    urlNode *new ;
    new = malloc(sizeof(urlNode));
    strcpy(new->url,url);
    new->next = NULL;
    return new;
}

wordNode *MakewordNode(char *word){
    wordNode *new ;
    new = malloc(sizeof(wordNode));
    strcpy(new->word,word);
    new->next = NULL;
    new->urlcontains = InitNode();
    return new;
}

int urlInList(urlNode *head,char *url){
    urlNode *t = head;
    while(t!=NULL){
        if(strcmp(t->url,url)==0)
            return 1;
        t = t->next;
    }
    return 0;
}

int wordInList(wordNode *head,char *word){
    wordNode *t = head;
    while(t!=NULL){
        if(strcmp(t->word, word)==0)
            return 1;
        t = t->next;
    }
    return 0;
}

void InsertUrlNode(urlNode *head,char *url){
    if(urlInList(head, url))
        return;
    else{
        urlNode *new = MakeurlNode(url);
        urlNode *t = head->next;
        if(t == NULL||strcmp(url, t->url)<0){
            new->next = head->next;
            head->next = new;
            return;
        }
        while(strcmp(url,t->url)>0 && t->next!=NULL&&strcmp(url, t->next->url)>0)
            t = t->next;
        new->next = t->next;
        t->next = new;
        return;
    }
}

void InsertWordNode(wordNode *head,char *word,char *url){
    if(wordInList(head, word)){
        wordNode *t = head;
        while(strcmp(t->word,word)!=0)
            t = t->next;
        InsertUrlNode(t->urlcontains,url);
        return;
    }
    else{
        wordNode *new = MakewordNode(word);
        wordNode *t = head->next;
        if(t==NULL||strcmp(word, t->word)<0){
            new->next = head->next;
            head->next = new;
            urlNode *newurl = MakeurlNode(url);
            newurl->next = new->urlcontains->next;
            new->urlcontains->next = newurl;
            return;
        }
        while(strcmp(word,t->word)>0&&t->next!=NULL&&strcmp(word,t->next->word)>0)
            t = t->next;
        new->next = t->next;
        t->next = new;
        urlNode *newurl = MakeurlNode(url);
        newurl->next = new->urlcontains->next;
        new->urlcontains->next = newurl;
        return;
    }
}

void freeurllist(urlNode *head){
    urlNode *t = head->next;
    while(t!=NULL){
        urlNode *curr = t;
        t = t->next;
        free(curr);
    }
    free(head);
    return;
}

void freewordlist(wordNode *head){
    wordNode *t = head->next;
    while (t!=NULL) {
        wordNode *curr = t;
        t = t->next;
        freeurllist(curr->urlcontains);
        free(curr);
    }
    free(head);
}
