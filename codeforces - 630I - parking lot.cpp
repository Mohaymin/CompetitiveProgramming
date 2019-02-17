#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getpow(ll a, ll b)
{
    long long res = 1;
    while(b>0)
    {
        if(b&1)
        {
            res = res * a;
        }
        a = a*a;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cout << (24+9*(n-3))*getpow(4, n-3);
    return 0;
}
