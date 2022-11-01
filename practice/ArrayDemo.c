#include<stdio.h>
void fun(int *arr){
    for(int i=0;i<5;i++){
        printf("%i\n",*(arr+i)); // *(arr+i) is equals to arr[i]
    }
}
int main(){
  int arr[5]={2,5,6,9,1};
  fun(arr);

    return 0;
}