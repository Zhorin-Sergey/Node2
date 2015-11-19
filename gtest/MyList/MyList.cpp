#include "CNode.h"
#include "MyList.h"
#include "iostream"

using namespace std;
CNode* CreateList(int count, const int* vals) {
  if (count <= 0) return 0;
  CNode *head = new CNode;
  head->val = vals[0];
  CNode *prev = head;
  for (int i = 1; i < count; ++i) {
    CNode *node = new CNode;
    node->val = vals[i];
    prev->next = node;
    prev = node;
  }
  prev->next = 0;
  return head;
}

CNode* check(CNode *a, CNode *b) {
  while (a != 0) {
    CNode *tmp = b;
    if (tmp == a)
      return tmp;
    while (tmp != 0) {
      if (tmp->next == a)
        return tmp->next;
        tmp = tmp->next;
      }
    a = a->next;
  }
  return 0;
}

void print(CNode *r) {
  while (r != 0) {
    cout << r->val << ' ';
    r = r->next;
  }
  cout << endl;
}
