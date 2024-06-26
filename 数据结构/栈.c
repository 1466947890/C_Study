#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
  /* data */
} Node;

Node* initStack()
{
  Node* S = (Node*)malloc(sizeof(Node));
  S->data = 0;
  S->next = NULL;
  return S;
}

int isEmpty(Node* S)
{
  if(S->data == 0 || S->next == NULL)
  {
    return 1;
  }else{
    return 0;
  }
}

int getTop(Node* S)
{
  if(isEmpty(S)){
    return -1;
  }else{
    return S->next->data;
  }
}


void push(Node* S, int data)
{
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->next = S->next;
  S->next = node;
  S->data++;
}

int pop(Node* S)
{
  if(isEmpty(S))
  {
    return -1;
  }else{
    Node* node = S->next;
    S -> next = node->next;
    int data = node->data;
    S->data--;
    free(node);
    return data;
  }
}


void printStack(Node* S)
{
  Node* node = S->next;
  while (node)
  {
    printf("%d ->", node->data);
    node = node->next;
  }
  printf("NULL\n");
  
}



int main()
{

  Node* S = initStack();
  push(S, 1);
  push(S, 2);
  push(S, 3);
  push(S, 4);
  push(S, 5);
  push(S, 6);
  printStack(S);
  int i = pop(S);
  printf("%d\n", i);
  pop(S);
  printStack(S);
  return 0;

}