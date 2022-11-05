#include <stdio.h>
#include <string.h>
void getModifiedString(char *str, char ch)
{
    int i, j;
    // int size=strlen(str);
    int size = 0;
    // char *ptr=str;
    // while(*ptr!='\0'){ //calculate size of string using pointer
    //     size++;
    //     ptr++;
    // }

    while (str[size] != '\0') // To calculate size of string without using strlen function and pointer
    {
        size++;
    }

    for (int i = 0; i < size; i++)
    {
        if (str[i] == ch)
        {
            for (int j = i; j < size; j++)
            {
                str[j] = str[j + 1];
            }
            size--;
            i--;
        }
    }
}
int main()
{
    char str[100];
    char ch;
    printf("Enter an String :");
    scanf("%[^\n]%*c", str);
    printf("Enter char to remove:");
    scanf("%c", &ch);
    getModifiedString(str, ch);
    printf("The modified string is %s", str);
    return 0;
}