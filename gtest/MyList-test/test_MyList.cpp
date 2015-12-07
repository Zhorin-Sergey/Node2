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

TEST(MyList, can_sort_node_with_2_elements) {
  int a[2] = { 5, 3 };
  int b[2] = { 3, 5 };
  CNode *head = CreateList(2, a);
  CNode *head1 = CreateList(2, b);
  sort(&head);
  EXPECT_EQ(true, comp(head, head1));
}

TEST(MyList, can_sort_node_with_3_elements) {
  int a[3] = { 5, 3, 1 };
  int b[3] = { 1, 3, 5 };
  CNode *head = CreateList(3, a);
  CNode *head1 = CreateList(3, b);
  sort(&head);
  EXPECT_EQ(true, comp(head, head1));
}

TEST(MyList, can_sort_node_with_1_elements) {
  int a[1] = { 3 };
  int b[1] = { 3 };
  CNode *head = CreateList(1, a);
  CNode *head1 = CreateList(1, b);
  sort(&head);
  EXPECT_EQ(true, comp(head, head1));
}

TEST(MyList, cant_sort_node_with_0_elements) {
  CNode *head = CreateList(0, 0);
  ASSERT_ANY_THROW(sort(&head));
}

TEST(MyList, can_sort_node_with_10_elements) {
  int a[10] = { 3, 10, 6, 11, 5, 2, 2, -1, 15, 8 };
  int b[10] = { -1, 2, 2, 3, 5, 6, 8, 10, 11, 15 };
  CNode *head = CreateList(10, a);
  CNode *head1 = CreateList(10, b);
  sort(&head);
  EXPECT_EQ(true, comp(head, head1));
}
