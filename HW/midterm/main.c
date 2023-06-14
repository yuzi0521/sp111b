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