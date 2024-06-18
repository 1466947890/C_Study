#include <stdio.h>
#include <string.h>

typedef union MoneyType
{
  int moneyi;
  double moneyd;
  char moneystr[100];
} MT;

int main()
{
  /*
    需求：
      金融项目中，钱有可能是整数，小数，字符串，
      请定义对应的共同体

  */

// 定义
MT money;
// 赋值
// 每次只能一个值
// money.moneyi = 9999;
money.moneyd = 111111.12345;

strcpy(money.moneystr, "100万");

// printf("%d\n", money.moneyi);
// printf("%f\n", money.moneyd);
printf("%s\n", money.moneystr);

 
}