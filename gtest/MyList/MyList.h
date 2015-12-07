#ifndef GTEST_MYLIST_MYLIST_H
#define GTEST_MYLIST_MYLIST_H

#include "CNode.h"

CNode* CreateList(int count, const int* vals);
CNode* check(CNode *a, CNode *b);
void print(CNode *r);
void sort(CNode **a);
bool comp(CNode *a, CNode *b);
#endif  // GTEST_MYLIST_MYLIST_H
