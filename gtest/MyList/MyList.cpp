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

void sort(CNode **a) {
  if (*a == 0)
    throw exception("Empty node");
  if ((*a)->next == 0)
    return;
  if ((*a)->next->next == 0) {
    if ((*a)->val > (*a)->next->val) {
      CNode *tmp = (*a)->next;
      (*a)->next->next = (*a);
      (*a)->next = 0;
      (*a) = tmp;
    }
    return;
  }
  CNode *curr;
  int flag = 0;
  while (flag == 0) {
    flag = 1;
    curr = (*a);
    if (curr->val > curr->next->val) {
      flag = 0; 
      CNode *second_element = (*a)->next;
      CNode *third_element = (*a)->next->next;
      (*a)->next->next = (*a);
      (*a)->next = third_element;
      (*a) = second_element;
    }
    while (curr->next->next != 0) {
      if (curr->next->val > curr->next->next->val) {
        CNode *first_element, *second_element, *third_element;
        flag = 0;
        first_element = curr->next; 
        second_element = curr->next->next; 
        third_element = curr->next->next->next;
        second_element->next = first_element;
        first_element->next = third_element;
        curr->next = second_element;
      }
      curr = curr->next;
    }
  }
}

bool comp(CNode *a, CNode *b) {
  while (a->next != 0) {
    if (a->val != b->val)
      return false;
    a = a->next;
    b = b->next;
  }
  return true;
}

List::List(int n) {
  if (n <= 0)
    throw exception("Wrong Size");
  data = new double[n + 2];
  pos = new int[n + 2];
  pos[0] = 0;
  for (int i = 1; i < n + 1; i++)
    pos[i] = i + 1;
  pos[n + 1] = 1;
  curr = 0;
}

void List::MoveNext() {
  curr = pos[curr];
}

void List::Add(double k) {
  if (pos[1] == 1)
    throw exception("Full List");
  int obj = pos[1];
  this->Del_Node(1);
  this->Add_Node(curr, obj);
  data[obj] = k;
}

void List::Del_Node(int t) {
  int curre = pos[t];
  pos[t] = pos[curre];
  pos[curre] = -1;
}

void List::Add_Node(int place, int object) {
  int next = pos[place];
  pos[place] = object;
  pos[object] = next;
}

void List::Del() {
  if (pos[0] == 0)
    throw exception("Empty List");
  if (pos[curr] == 0)
    this->MoveNext();
  int obj = pos[curr];
  this->Del_Node(curr);
  this->Add_Node(1, obj);
}

void List::print() {
  int i = pos[0];
  while (i != 0) {
    cout << data[i] << endl;
    i = pos[i];
  }
}

List::~List() {
  delete []data;
  delete []pos;
}