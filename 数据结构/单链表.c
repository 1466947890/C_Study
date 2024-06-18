#include <stdio.h>
#include <stdlib.h>
// 创建链表节点

typedef struct Node
{
  int data;
  struct Node* next;

  /* data */
} Node;

Node *initList()
{
  Node *list = (Node *)malloc(sizeof(Node));
  list->data = 0;
  list->next = NULL;
  return list;
}
/**
 * 在头节点的下一位插入
 */
void headInsert(Node *list, int data)
{
  // 创建一个Node节点
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  // 节点的下一位连接链表的下一位
  node->next = list->next;
  // 链表的下一位连接节点
  list->next = node;
  // 链表的长度要自增
  list->data++;
}

/**
 * 从最后面插入
 */
void tailInsert(Node *list, int data)
{
  Node *head = list;
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  // 要移动指针到最后一位
  while (list->next)
  {
    list = list->next;
  }

  list->next = node;
  head->data++;
}

void delete(Node *list, int data)
{
  // 保存前一个节点
  Node *pre = list;
  Node *current = list->next;
  while (current)
  {
    if (current->data == data)
    {
      pre->next = current->next;
      free(current);
      break;
    }
    else
    {
      pre = current;
      current = current->next;
    }
  }
  list -> data --;
}

void printList(Node* list)
{
    list = list -> next;
    while(list)
    {
      printf("%d ", list -> data);
      list = list -> next;
    }
    printf("\n");
}

int main()
{
  Node* list = initList();
  headInsert(list, 1);
  headInsert(list, 2);
  headInsert(list, 3);
  headInsert(list, 4);
  headInsert(list, 5);

  tailInsert(list, 6);
  tailInsert(list, 7);
  tailInsert(list, 8);
  tailInsert(list, 9);
  tailInsert(list, 10);

  delete(list, 5);
  delete(list, 6);
  delete(list, 7);

  printList(list);

  return 0;
}