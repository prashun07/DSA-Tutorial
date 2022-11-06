// This program takes string of unknown length as input
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    char ch;
    char *s = NULL;
    size_t size = 0;
    int i = 0;
    while (1)
    {
        scanf("%c", &ch);
        size = size + sizeof(char);
        s = (char *)realloc(s, size);
        if (s == NULL)
        { // realloc failed
            free(s);
            printf("Realloc failed!!");
            continue;
        }
        if (ch == '\n')
            break;
        else
        {
            s[i++] = ch;
        }
    }
    s[i] = '\0';
    printf("String entered as input is: %s", s);
    printf("\nSize of String: %d", strlen(s));
}