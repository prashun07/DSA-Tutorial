#include <cstring>
#include <iostream>
using namespace std;
char*my_strncpy(char*dest,const char*src,unsigned int n){
    if((dest==NULL) || (src==NULL))
     return NULL;
     char *head=dest;
     while(*src && n--){
        *dest=*src;
        src++;
        dest++;
     }
     *dest='\0';
     return head;
}
int main()
{
    // char dest[50] = "This is an";
    // char src[50] = " example";
    // strcat(dest, src);
    // cout << dest;
    // string s="prashun";
    // string s1="prashun";
    string s2="Prashun";
    char s[10]="prashun";
    char s1[20]="kumar";
    // cout<<strcmp(s,s1);
    cout<<strncpy(s1,s,10)<<endl;
    cout<<my_strncpy(s1,s,7)<<endl;
    // s2.append(s1);
    // cout<<strlen(s)<<endl;
    // cout<<s<<endl;
    // cout<<s2<<endl;
    return 0;
}