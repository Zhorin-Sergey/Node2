#include "MyList.h"
#include <gtest.h>
#include "iostream"
using namespace std;
TEST(MyList, CreateEmptyList) {
  CNode *head = CreateList(0, 0);
  CNode *expected_head = 0;
  EXPECT_EQ(expected_head, head);
}

TEST(MyList, CreateList) {
  const int kListSize = 10;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);

  int k = 0;
  while (head != 0) {
    EXPECT_EQ(vals[k], head->val);
    head = head->next;
    ++k;
  }
  EXPECT_EQ(kListSize, k);
}

TEST(MyList, FunctionCheck1) {
  const int kListSize = 10;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);
  CNode *head1 = CreateList(kListSize, vals);
  CNode *d = head1;
  for(int i = 0; i<2; i++) {
    d = d->next;
  }
  CNode *d1 = head;
  for (int i = 0; i<4; i++) {
    d1 = d1->next;
  }
  d1->next = d;
  EXPECT_EQ(d, check(head1, head));
}

TEST(MyList, FunctionCheck2) {
  const int kListSize = 10;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);
  CNode *head1 = CreateList(kListSize, vals);
  EXPECT_EQ(NULL, check(head1, head));
}

TEST(MyList, FunctionCheck3) {
  const int kListSize = 10;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);
  CNode *head1 = CreateList(kListSize, vals);
  CNode *d = head1;
  while (d->next->next->next!=0) {
    d = d->next;
  }
  print(head);
  print(head1);
  d->next = head;
  print(head1);
  EXPECT_EQ(head, check(head1, head));
}

TEST(MyList, FunctionCheck4) {
  const int kListSize = 10;
  int n = 1;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);
  for (int i = 0; i < n; ++i)
    vals[i] = i + 10;
  CNode *d = CreateList(n, vals);
  CNode *head1 = head->next;
  print(head);
  print(d);
  head = d;
  head->next = head1;
  print(head);
  EXPECT_EQ(d, check(head, d));
}