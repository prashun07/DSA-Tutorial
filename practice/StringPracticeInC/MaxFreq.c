#include<stdio.h>
#include<string.h>
#include<limits.h>
void main(){
    char str[100];
    int freq[256]={0};
    printf("Enter a String:");
    scanf("%[^\n]%*c",str);
    for(int i=0;i<strlen(str);i++){
        freq[str[i]-'0']++;
    }
    int maxVal=INT_MIN;
    char answer;
    for(int i=0;i<strlen(str);i++){
        if(freq[str[i]-'0']>=maxVal){
            maxVal=freq[str[i]-'0'];
            answer=str[i];
        }
    }
    printf("Max Occurrence of Char %c is %d",answer,maxVal);
}