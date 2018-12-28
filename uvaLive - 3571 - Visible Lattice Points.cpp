#include<bits/stdc++.h>
using namespace std;

const int sz = 1010;

typedef long long ll;

ll ansFor[sz];

void init()
{
    ll sum = 3;
    ansFor[1] = sum;
    int dummy;
    int gcd;
    for(int i=2; i<sz; i++)
    {
        dummy = i-1;
        for(int j=2; j<i; j++)
        {
            gcd = __gcd(i, j);
            if(gcd > 1)
            {
                dummy--;
            }
        }
        sum += (dummy<<1);
        ansFor[i] = sum;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    init();
    int c, n;
    cin >> c;
    for(int i=1; i<=c; i++)
    {
        cin >> n;
        cout << i << " " << n << " " << ansFor[n] << "\n";
    }
    return 0;
}
