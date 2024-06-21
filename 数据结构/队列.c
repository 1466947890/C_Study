#include <stdio.h>
#include <stdlib.h>

typedef struct  Node
{
  int data;
  struct NOde* next;
  /* data */
} Node;

Node* initQueue()
{
  Node* Q = (Node*)malloc(sizeof(Node));
  Q->data = 0;
  Q->next = NULL;
  return Q;
}

void enQueue(Node* Q, int data)
{
  Node* q = Q;
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  for(int i = 0; i<Q->data; i++)
  {
    q = q->next;
  }
  node->next = q->next;
  q->next = node;
  Q->data ++;
}



int main()
{


}