#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t, a, b, k;
ll rit, lft;
ll ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> k;
        lft = k/2;
        rit = k-lft;
        ans = rit*a - lft*b;
        cout << ans << "\n";
    }
    return 0;
}
