#include <stdio.h>
#include "link-list-header.h"
#include <malloc.h>

LinkedList *createList(){
  LinkedList *list = malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

Node *createNode(int value){
  Node *node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}
void addLast(LinkedList *list, int value)
{
  Node *node = createNode(value);
  if (list->head == NULL)
  { // Kiểm tra coi list có rỗng không
    list->head = node;
    list->tail = node;
    list->size++;
    return;
  }
  list->tail->next = node; // Nối cái node vào cuối danh sách
  list->tail = node;       // Cập nhật lại tail đang trỏ đến node mới tạo
  list->size++;            // Tăng kích thước của danh sách lên 1 đơn vị
}

void printList(LinkedList *list)
{
  Node *current = list->head; // Bắt đầu từ node đầu tiên của danh sách
  while (current != NULL)
  {                                  // Lặp lại cho đến khi current trở thành NULL
    printf("%d ->", current->value); // In ra giá trị của node hiện tại
    current = current->next;         // Di chuyển đến node tiếp theo trong danh sách
  }
  printf("NULL\n"); // In ra NULL để biểu thị kết thúc của danh sách
}

void reverse(LinkedList *list){
  // Nếu rỗng hoặc chỉ có 1 node
  if (list->head == NULL || list->head->next == NULL)
    return;

  Node *prev = NULL;
  Node *current = list->head;
  Node *next = NULL;

  // Tail mới sẽ là head cũ
  list->tail = list->head;

  while (current != NULL)
  {
      next = current->next; // B1: lưu node kế tiếp
      current->next = prev; // B2: đảo chiều con trỏ
      prev = current;       // B3: dời prev lên
      current = next;       // B4: dời current
  }
  list->head = prev; // Cập nhật head mới sau khi đã đảo ngược
}
