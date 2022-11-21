#include<stdio.h>
#include<stdlib.h>
void main(){
    char *s="ABCDEF";
    int size=0;
    while(s[size]!='\0'){
        // s[size]='a';
        size++;
    }
    int i=size;
    char *t=NULL;
    printf("%d",size);
    size=size+sizeof(char);
    t=realloc(s,size);
    if(t==NULL)
    { 
        printf("Failed");
        free(s);
        return;
    }
    s=t;
    s[i++]='1';
    s[i]='\0';
    for(int i=0;s[i]!='\0';i++){
        printf("%c",s[i]);
    }
}