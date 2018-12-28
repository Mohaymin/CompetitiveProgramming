#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int i, n, m, p, q;
    char ch1, ch2;
    cin>>m>>n;
    cin>>str;
    while(n--)
    {
        cin>>p>>q>>ch1>>ch2;
        //getchar();
        for(i=p-1; i<q; i++)
        {
            if(str[i]==ch1)
                str[i]=ch2;
        }
        //cout<<str<<endl;
    }
    cout<<str<<endl;
}
