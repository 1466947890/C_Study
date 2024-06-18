#include <stdio.h>
#include <stdlib.h>

int main()
{
  // 利用malloc函数申请连续空间
  // 需求：申请一片空间，要存储100个int类型的整数
  // int* p = malloc(100 * sizeof(int);

  int* p = calloc(10, sizeof(int));

  printf("%p\n", p);

  // for(int i = 0; i < 100; i++)
  // {
  //   // 第一种赋值
  //   // *(p+i) = (i + 1) * 10;
  //   // 第二种赋值
  //   p[i] = (i + 1) * 10;
  // }

  for(int i = 0; i < 10; i ++)
  {
    printf("%d ", *(p + 1));
  }
}