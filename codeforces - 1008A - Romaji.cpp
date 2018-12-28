#include<bits/stdc++.h>
using namespace std;


string str;
bool ans;

bool isVowel(char c)
{
    switch(c)
    {
    case 'a':
        return true;
    case 'e':
        return true;
    case 'i':
        return true;
    case 'o':
        return true;
    case 'u':
        return true;
    }
    return false;
}

int main()
{
    cin >> str;
    int len = str.size();
    if(str[len-1]!='n' && !isVowel(str[len-1]))
    {
        ans = false;
    }
    else
    {
        ans = true;
        for(int i=0; i<len-1; i++)
        {
            if(str[i]=='n')
            {
                continue;
            }
            if(!isVowel(str[i]) && !isVowel(str[i+1]))
            {
                ans = false;
                break;
            }
        }
    }
    if(ans)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}
