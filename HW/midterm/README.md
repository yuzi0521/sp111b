## 此為製作加減乘除的函式庫

## 來源聲明

    此專案由同學的sum函式庫專案參考學習並加以延伸的，
    除去sum部分其餘 div、mult、sub 均為延伸原創的

## 運作原理(以sum為例)
### 創建sum.h

此主要為定義函式庫
```c
#ifndef SUM_H_INCLUDED // 條件預處理指令，判斷SUM_H_INCLUDED是否被定義
#define SUM_H_INCLUDED // 定義SUM_H_INCLUDED，並防止頭文件的内容被重復包含

#include <stdio.h> //告訴编譯器編譯過程中將stdio.h頭文件的内容包含在當前文件中

int sum(int a ,int b); //函數聲明

#endif //條件預處理指令的结束標記
```
### 創建sum.c

寫其功能(就是function)
```c
//加法
#include "sum.h"

int sum(int a,int b)
{
    return a+b;
}
```
### 創建Makefile

- 用於構建並指定了如何编譯和運行這個程式,將main.c、sum.c、sub.c、mult.c、div.c進行連結並輸出成main
- 執行main
```Makefile
output: main.c
	@gcc -o main main.c sum.c sub.c mult.c div.c 
	@./main
```
## demo
### 測試程式碼

``` C
#include "sum.h"
#include "sub.h"
#include "mult.h"
#include "div.h"

int main(void)
{
    int a=20;
    int b=17;
    printf("%d\n",sum(a,b));
    printf("%d\n",sub(a,b));
    printf("%d\n",mult(a,b));
    printf("%.2f\n",div(a,b));

    printf("========test 0========\n");

    int c=20;
    int d=0;
    printf("%d\n",sum(c,d));
    printf("%d\n",sub(c,d));
    printf("%d\n",mult(c,d));
    printf("%.2f\n",div(c,d));
}
```
### 執行結果
```
yuzi@LAPTOP-BL9QSBJ6:/mnt/c/Users/user/Desktop/網頁設計/yuzi/sp111b/HW/midterm$ gcc -o main main.c sum.c sub.c mult.c div.c
yuzi@LAPTOP-BL9QSBJ6:/mnt/c/Users/user/Desktop/網頁設計/yuzi/sp111b/HW/midterm$ ./main
37
3
340
1.18
========test 0========
20
20
0
please enter again ,your number can't be zero
0.00
```