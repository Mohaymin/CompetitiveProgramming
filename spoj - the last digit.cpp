#include<bits/stdc++.h>
using namespace std;

int binpow(int a, long long b)
{
    int res = 1;
    while(b>0)
    {
        if(b&1)
        {
            res = (res*a)%10;
        }
        a = (a*a)%10;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, a;
    long long b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        cout << binpow(a, b) << "\n";
    }
    return 0;
}
