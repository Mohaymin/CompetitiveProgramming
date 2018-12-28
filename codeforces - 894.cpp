#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ch;
    string str;
    int i, j, k,len, c;
    while(cin>>ch)
    {
        if(ch=='Q'||ch=='A')
            str.push_back(ch);
    }
    c=0;
    len=str.size();
    for(i=0; i<len; i++)
    {
        if(str[i]=='Q')
        {
            for(j=i+1; j<len; j++)
            {
                if(str[j]=='A')
                {
                    for(k=j+1; k<len; k++)
                    {
                        if(str[k]=='Q')
                        {
                            c++;
                        }
                    }
                }
            }
        }
    }
    cout<<c<<endl;
    return 0;
}
