// 除法 division
#include "div.h"

float div(float a,float b)
{
    if(b==0){

        printf("please enter again ,your number can't be zero\n");
        return 0.0;
    }
        
    else
        return a/b;
}