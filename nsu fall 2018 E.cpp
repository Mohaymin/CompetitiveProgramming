#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m = 1000000007;

int t, n;
int mid;

ll ans;

ll getans(double n, double r)
{
    double prod = 1;
    for(double i=0; i<r; i++)
    {
        prod *= ((n-i)/(r-i));
    }
    return (ll)(prod)%m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n%2==1)
        {
            cout << 0;
        }
        else
        {
            mid = n/2;
            ans = getans(n, mid);
            cout << ans;
        }
        cout << "\n";
    }
    return 0;
}
