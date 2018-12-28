#include<stdio.h>
#include<string.h>

int main()
{
    int len = 200;
    char scentence[len];
    char word[len];
    char answer[len];

    gets(scentence);
    gets(word);

    int i, j, k, p;
    int wordFound = 0;

    for(i=0, j=0, p=0; scentence[i]!='\0'; i++)
    {
        if(scentence[i] == word[j])
        {
            wordFound = 1;
            k = i+1;
            j = 1; // because, first character already matches
            while(word[j] != '\0')
            {
                if(word[j] != scentence[k])
                {
                    printf("%c %d\n", word[j], j);
                    wordFound = 0;
                    break;
                }
                k++;
                j++;
            }
            j = 0;
        }
        if(wordFound == 0)
            answer[p++] = scentence[i];
        else
        {
            i = i+strlen(word)-1;
            wordFound = 0;
        }
    }
    answer[p] = '\0';
    puts(answer);
    return 0;
}
