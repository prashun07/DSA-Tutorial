#include <stdio.h>
#include <string.h>
int isAnagram(char *str, char *s)
{
    int size1 = strlen(str);
    int size2 = strlen(s);
    if(size1!=size2)
     return 0;
    for(int i=0;i<size1-1;i++){
        for(int j=i+1;j<size1;j++){
            if(str[i]>str[j])
            {char temp=str[i];
            str[i]=str[j];
            str[j]=temp;
            }
            if(s[i]>s[j]){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    for(int i=0;i<size1;i++){
        if(str[i]!=s[i])
        return 0;
    }
    return 1;
}
void main()
{
    char str[100];
    char s[100];
    printf("Enter the String 1:");
    scanf("%[^\n]%*c", str);
    printf("Enter the String 2:");
    scanf("%[^\n]%*c", s);
    int anagram = isAnagram(str, s);
    printf("Is the two string an anagram?\n");
    anagram == 1 ? printf("Yes!!") : printf("No!!");
}