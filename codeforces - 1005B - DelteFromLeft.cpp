#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int lenS1, lenS2, lenMin;
int cnt;

int main()
{
    cin >> s1 >> s2;

    lenS1 = s1.size(),
    lenS2 = s2.size();

    lenMin = min(lenS1, lenS2);

    for(int i=1; i<=lenMin; i++)
    {
        if(s1[lenS1-i] != s2[lenS2-i])
        {
            break;
        }
        cnt++;
    }
    cout << lenS1+lenS2-2*cnt << endl;
}
