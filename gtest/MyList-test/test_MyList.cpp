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

TEST(MyList, the_common_link_is_somewhere_in_the_middle) {
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

TEST(MyList, can_return_zero_if_nodes_have_not_common_link) {
  const int kListSize = 10;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);
  CNode *head1 = CreateList(kListSize, vals);
  EXPECT_EQ(NULL, check(head1, head));
}

TEST(MyList, the_common_link_is_a_first_elemet_of_second_node) {
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
  EXPECT_EQ(head, check(head, head1));
}

TEST(MyList, the_common_link_is_a_first_elemet_of_second_node_and_sizes_are_not_equal) {
  const int kListSize = 10;
  int n = 1;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);
  for (int i = 0; i < n; ++i)
    vals[i] = i + 10;
  CNode *d = CreateList(n, vals);
  print(head);
  print(d);
  d->next = head;
  print(d);
  EXPECT_EQ(head, check(head, d));
}