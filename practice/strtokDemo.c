#include<stdio.h>
#include<string.h>
int main(){
    char str[60]="Prashun/is my First name &kumar ' is my last name.";
    for(char*word=strtok(str,"'/.& ");word!=NULL;word=strtok(NULL,"'/.& "))
    {
        printf("%s\n",word);
    }
    return 0;
}