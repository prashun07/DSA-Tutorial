#include<stdio.h>
#include<stdlib.h>
struct stackk{
 unsigned size;
 int top;
 int*array;
};
struct stackk* createStack(unsigned size){
    struct stackk* stack=(struct stackk*)malloc(sizeof(struct stackk));
  stack->size=size;
  stack->top=-1;
  stack->array=(int *)malloc(sizeof(int)*size);
  return stack;
}
int isFull(struct stackk*stack){
    return (stack->top==stack->size-1);
}
int isEmpty(struct stackk* stack){
    return(stack->top==-1);
}
void push(struct stackk*stack,int val){
    if(isFull(stack))
    return;
    stack->array[++stack->top]=val;
}
int pop(struct stackk*stack){
    if(isEmpty(stack))
    return-1;
    return stack->array[stack->top--];
}
int peek(struct stackk*stack){
    if(isEmpty(stack))
       return -1000000;
       return stack->array[stack->top];
}
int main(){
    struct stackk*stack=createStack(3);
    push(stack,10);
    push(stack,20);
    push(stack,30);
printf("Top of stack:%i\n",stack->top);
printf("Size of Stack:%i\n",stack->size);
for(int i=0;i<stack->size;i++){
    printf("Elements:%i\n",peek(stack));
    printf("poped element of stack:%i\n",pop(stack));
}
printf("is stack empty?:%i",isEmpty(stack));
    return 0;
}