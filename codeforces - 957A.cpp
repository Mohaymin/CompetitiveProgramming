#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    char ch;
    bool flag;
    string str;

    cin >> N;

    str.push_back('?');
    for(int i=0; i<N; i++)
    {
        cin>>ch;
        str.push_back(ch);
    }
    str.push_back('?');

    flag = false;
    for(int i=1; i<=N; i++)
    {
        if(str[i]=='?')
        {
            if(str[i-1]==str[i+1] || str[i-1]=='?' || str[i+1]=='?')
            {
                flag = true;
            }
        }
        else if(str[i]==str[i+1])
        {
            puts("No");
            return 0;
        }
    }
    if(!flag)
    {
        puts("No");
    }
    else
    {
        puts("Yes");
    }
    return 0;
}
/*M?YC?MY??
5
CY??Y

5
C?C?Y

5
?CYC?

5
C??MM

3
MMY

100
YCY?CMCMCYMYMYC?YMYMYMY?CMC?MCMYCMYMYCM?CMCM?CMYMYCYCMCMCMCMCMYM?CYCYCMCM?CY?MYCYCMYM?CYCYCYMY?CYCYC
*/
