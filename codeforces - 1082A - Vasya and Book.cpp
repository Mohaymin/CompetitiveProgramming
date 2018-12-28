#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t, n, x, y, d;
ll ans;
ll diff;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y >> d;
        ans = -1;
        diff = fabs(x-y);
        if(diff%d==0)
        {
            ans = diff/d;
        }
        else
        {
            if((y-1)%d==0)
                ans = ceil((x*1.0)/d) + (y-1)/d;

            if((n-y)%d==0)
                ans = ceil((n-x)*1.0/d) + (n-y)/d;

            if((y-1)%d==0 && (n-y)%d==0)
            {
                ans = min(
                          ceil((x*1.0)/d) + (y-1)/d,
                          ceil((n-x)*1.0/d) + (n-y)/d
                      );
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
