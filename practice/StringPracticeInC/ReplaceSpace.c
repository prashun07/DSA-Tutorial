#include <stdio.h>
void getModifiedString(char*str,char ch){
for(int i=0;str[i]!='\0';i++){
    if(str[i]==' '){
        str[i]=ch;
    }
}
}
void main()
{
    char str[100];
    printf("Enter an String:");
    scanf("%[^\n]%*c", &str);
    char replaceChar;
    printf("Enter the Character to replace:");
    scanf("%c", &replaceChar);
    getModifiedString(str, replaceChar);
    printf("Modified string:%s", str);
}