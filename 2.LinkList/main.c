#include <stdio.h>
#include "link-list-header.h"
// Đảo ngược Linked List
int main(int argc, char const *argv[])
{
  LinkedList *list = createList();
  // 1. Thêm node vào list
  addLast(list, 10);
  addLast(list, 20);
  addLast(list, 30);
  addLast(list, 40);
  // 2. In ra list
  printf("List: ");
  printList(list);
  // 3. Đảo ngược list
  printf("Before reverse: ");
  printList(list);
  reverse(list);
  printf("After reverse: ");
  printList(list);
  return 0;
}
