#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void main(){
    char str[100];
    printf("Enter the String to check palindrome:");
    gets(str);
    int size=strlen(str);
    for(int i=0;i<strlen(str);i++){
        if(str[i]!=str[size-i-1])
        { printf("Not An palindrome!");
        exit(1);
        }
    }
    printf("Is Palindrome");
}