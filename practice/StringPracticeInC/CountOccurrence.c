#include<stdio.h>
int getCount(char*s,char ch){
    int count=0;
    for(int i=0;s[i]!='\0';i++){
      if(s[i]==ch)
       count++;
    }
    return count;
}
void main(){
    char str[100];
    char toRemove;
    printf("Enter an String:");
    gets(str);
    printf("Enter an char to count:");
    scanf("%c",&toRemove);
    int Answer=getCount(str,toRemove);
    printf("String is %s and char is %c",str,toRemove);
    printf("\nNumber of Occurrences of %c is:%d",toRemove,Answer);

}