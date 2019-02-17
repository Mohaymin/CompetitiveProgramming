#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, n, y, z;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int c;
    while(cin >> c)
    {
        if(c==0)
            return 0;
        while(c--)
        {
            cin >> x >> y >> n;
            z = 1;
            while(y > 0)
            {
                if(y&1)
                {
                    z = (z*x)%n;
                }
                x = (x*x)%n;
                y = y>>1;
            }
            cout << z << '\n';
        }
    }
    return 0;
}
