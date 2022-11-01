#include<stdio.h>
#include<string.h>
#define MAX 50
int main()
{ char str[MAX];
fgets(str,MAX,stdin);
printf("String entered is:");
puts(str);
return 0;
}