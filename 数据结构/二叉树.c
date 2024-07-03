/**
 * 树 是一个有n个结点的有限集，如果n=0时，那么称之为空树
 * ：
 * 1、树的定义是递归的，树的定义中又用到了自身
 * 2、树
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  char data;
  struct TreeNode *lchild;
  struct TreeNode *rchild;
} TreeNode;

void createTree(TreeNode **T, char *data, int *index)
{
  char ch;
  ch = data[*index];
  *index += 1;
  if (ch == '#')
  {
    *T = NULL;
  }
  else
  {
    *T = (TreeNode *)malloc(sizeof(TreeNode));
    (*T)->data = ch;
    // 创建左子树。逻辑一致。进行递归
    createTree(&((*T)->lchild), data, index);
    // 创建右子树，逻辑一致，进行递归
    createTree(&((*T)->rchild), data, index);
  }
}

void preOrder(TreeNode *T)
{
  if (T == NULL)
  {
    return;
  }
  else
  {
    // 先办事
    printf("%c", T->data);
    // 处理左孩子
    preOrder(T->lchild);
    // 处理右孩子
    preOrder(T->rchild);
  }
}

void inOrder(TreeNode *T)
{
  if (T == NULL)
  {
    return;
  }
  else
  {
    // 处理左孩子
    inOrder(T->lchild);
    // 办事
    printf("%c", T->data);
    // 处理右孩子
    inOrder(T->rchild);
  }
}

void postOrder(TreeNode *T)
{
  if (T == NULL)
  {
    return;
  }
  else
  {
    // 处理左孩子
    postOrder(T->lchild);
    // 处理右孩子
    postOrder(T->rchild);
    // 办事
    printf("%c", T->data);
  }
}

int main(int argc, char *argv[])
{
  TreeNode *T;
  int index = 0;
  createTree(&T, argv[1], &index);
  preOrder(T);
  printf("\n");
  inOrder(T);
  printf("\n");
  postOrder(T);
  return 0;
}