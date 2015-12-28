#ifndef GTEST_MYLIST_MYLIST_H
#define GTEST_MYLIST_MYLIST_H

#include "CNode.h"

CNode* CreateList(int count, const int* vals);
CNode* check(CNode *a, CNode *b);
void print(CNode *r);
void sort(CNode **a);
bool comp(CNode *a, CNode *b);

class List {
  public:
    double* data;
    int* pos;
    int curr;
    List(int n);
    void MoveNext();
    void Add(double k);
    void Del();
    void print();
    ~List();
  private:
    void Del_Node(int t);
    void Add_Node(int, int);
};
#endif  // GTEST_MYLIST_MYLIST_H
