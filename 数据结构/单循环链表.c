#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
  /* data */
} Node;

Node* initList()
{
  Node* list = (Node*)malloc(sizeof(Node));
  list -> data = 0;
  list -> next = list;
  return list;
}

void headInsert(Node* list, int data)
{
  Node* node = (Node*) malloc(sizeof(Node));
  node -> data = data;
  node -> next = list -> next;
  list -> next = node;
  list -> data++;
}

void printList(Node* list)
{
  Node* node = list -> next;
  while (node != list)
  {
    printf("%d->", node -> data);
    node = node -> next;
  }
  printf("NULL\n");
}

void tailInsert(Node* list, int data)
{
  Node* n = list;
  Node* node = (Node*)malloc(sizeof(Node));
  node -> data = data;
  node -> next = list;
  while(n -> next != list)
  {
    n = n -> next;
  }
  n -> next = node;
  list -> data ++;
}


void delete(Node* list, int data)
{
  Node* current = list -> next;
  Node* pre = list;
  while(current != list)
  {
    // printf("find %d", current -> data);
    if(current -> data == data)
    {
      printf("find");
      pre -> next = current -> next;
      free(current);
      break;
    }
    else
    {
      pre = current;
      current = current -> next;
    }
  }
  list -> data--;

}


int main()
{
  Node* list = initList();
  headInsert(list, 1);
  headInsert(list, 2);
  tailInsert(list, 35);
  tailInsert(list, 96);

  delete(list, 36);

  printList(list);

}
