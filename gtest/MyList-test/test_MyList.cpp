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

TEST(MyList, FunctionCheck) {
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
