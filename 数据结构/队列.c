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

// 入节点操作
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

int isEmpty(Node* Q)
{
  if(Q->data == 0 || Q->next == NULL)
  {
    return 1;
  }else{
    return 0;
  }
}

int deQueue(Node* Q)
{
  if(isEmpty(Q))
  {
    return -1;
  }else{
    Node* node = Q->next;
    int data = node->data;
    Q->next = node->next;
    free(node);
    Q->data--;
    return data;
  }
}

// 打印节点操作
void printQueue(Node* Q)
{
  Node* node = Q->next;
  while (node)
  {
    printf("%d -> ", node->data);
    node = node->next;
  }

  printf("NULL\n");
}






int main()
{

  Node* Q = initQueue();
  enQueue(Q, 1);
  enQueue(Q, 2);
  enQueue(Q, 3);
  enQueue(Q, 4);
  printQueue(Q);
  int data = deQueue(Q);
  printf("data = %d\n", data);
  printQueue(Q);
}