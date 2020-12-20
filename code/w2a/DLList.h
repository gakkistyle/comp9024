//
//  DLList.h
//  code
//
//  Created by 郑淇文 on 2020/1/11.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#ifndef DLList_h
#define DLList_h

#include <stdio.h>
#include "DLList.h"

typedef struct DLListRep *DLList;

DLList newDLList();

void freeDLList(DLList);

void showDLList(DLList);

int DLListCurrent(DLList);

int DLListMove(DLList,int);

int DLListMoveTo(DLList,int);

void DLListBefore(DLList,int);

void DLListAfter(DLList,int);

void DLListDelete(DLList);

int DLListLength(DLList);

#endif /* DLList_h */
