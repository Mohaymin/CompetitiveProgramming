#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char strA[100];
    char strB[100];
    char strC[100];

    gets(strA);

    int i, j, k;

    for(i=0, j=0; strA[i] != '\0'; i++)
    {
        if(strA[i] >= 'A' && strA[i] <= 'Z')
        {
            strB[j] = strA[i]-'A'+'a';
            j++;
        }
        else if(strA[i] >= 'a' && strA[i] <= 'z')
        {
            strB[j] = strA[i];
            j++;
        }
    }
    strB[j] = '\0';
    strC[0] = '\0';
    strcpy(strC, strB);
    strrev(strB);
    if(strcmp(strC, strB) == 0)
    {
        puts("Palindrome.");
    }
    else
    {
        puts("Not palindrome.");
    }
    return 0;
}
