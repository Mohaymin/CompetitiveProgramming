#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s)
{
    int len = s.size();
    int lim = len/2;
    for(int i=0; i<=lim; i++)
    {
        if(s[i]!=s[len-i-1])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s;
    int64_t k;
    cin >> s >> k;
    if(ispalindrome(s))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
