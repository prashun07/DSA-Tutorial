#include<stdio.h>
int main(){
    int n=10;
    int *ptr=&n;
    int *ptr1=&n;
    printf("n pointer:%d-- %p\n",n,ptr);
    printf("m pointer:%d-- %p\n",n,ptr1);
    ptr1=ptr1+3;
    printf("m pointer:%d-- %p\n",n,ptr1);
    printf("difference of pointer:%d",ptr1-ptr);
    // printf("Before Increment: %d\n",ptr);
    // // *(ptr++);
    // ptr++;
    // printf("after ++: %d",*ptr);
    return 0;
}