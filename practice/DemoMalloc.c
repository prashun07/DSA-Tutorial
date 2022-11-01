#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
printf("Enter the size of array:");
int n=0;
scanf("%d",&n);
ptr=(int*)malloc(n*sizeof(int));
// ptr=(int*)calloc(n,sizeof(int));

if(ptr==NULL){;
    printf("Memory not allocated!!");
    exit(0);
}
else{
    for(int i=0;i<n;i++){
        ptr[i]=i+1;
    }
}
free(ptr);
for(int i=0;i<n;i++){
    printf("%d ",ptr[i]);
}
    return 0;
}