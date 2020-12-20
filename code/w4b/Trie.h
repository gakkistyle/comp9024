//
//  Trie.h
//  code
//
//  Created by 郑淇文 on 2020/2/3.
//  Copyright © 2020 郑淇文. All rights reserved.
//


typedef int Item;
typedef char *Key;

typedef struct Node *Trie;

Trie newTrie();
void freeTrie(Trie);
void showTrie(Trie);

Trie TrieInsert(Trie,Key,Item);


