#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct que{
 int front,rear,size;
 int*array;
};
struct que*create(int size){
    struct que*queue=(struct que*)malloc(sizeof(struct que));
    queue->size=size;
    queue->front=queue->rear=-1;
    queue->array=(int*)malloc(size*sizeof(struct que));
    return queue;
}
int isFull(struct que*queue){
    return (queue->size-1==queue->rear);
}
int isEmpty(struct que*queue){
    return (queue->front==-1);
}
void enqueue(struct que*queue, int val){
    if(isFull(queue))
     return;
     queue->rear=queue->rear+1;
     queue->front=0;
     queue->array[queue->rear]=val;
     printf("Added %i in queue\n",val);
}
void deque(struct que*queue){
    if(isEmpty(queue))
     return;
     if(queue->front>queue->rear)
     return;
     printf("dequeing %i from queue\n",queue->array[queue->front]);
     queue->front=queue->front+1;
}
void show(struct que*queue){
       if(queue->front>=queue->rear && queue->front!=-1)
    printf("queue is empty!!\n");
    for(int i=queue->front;i<=queue->rear;i++){
        printf("Queue data: %i  ",queue->array[i]);
    }
    printf("\n");
 
}
int main(){
    struct que*queue=create(5);
    enqueue(queue,10);
    enqueue(queue,40);
    enqueue(queue,20);
    enqueue(queue,30);
show(queue);
deque(queue);
deque(queue);
deque(queue);
deque(queue);
show(queue);
}