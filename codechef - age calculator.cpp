#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int sz = 10010;

int daysInMonth[sz];

int t, n, db, dc, mb, mc, yb, yc;

ll daysinayear;
ll ans;

int main()
{
    //freopen("_in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        daysinayear = 0;
        for(int i=1; i<=n; i++)
        {
            cin >> daysInMonth[i];
            daysinayear += daysInMonth[i];
        }
        cin >> yb >> mb >> db;
        cin >> yc >> mc >> dc;
        if(yb==yc)
        {
            if(mb==mc)
            {
                ans = dc - db + 1;
            }
            else
            {
                ans = daysInMonth[mb]-db+1;
                for(int i=mb+1; i<mc; i++)
                {
                    ans += daysInMonth[i];
                }
                ans += dc;
            }
        }
        else
        {
            ans = daysInMonth[mb]-db+1;
            for(int i=mb+1; i<=n; i++)
            {
                ans += daysInMonth[i];
            }
            ans += (daysinayear*(yc-yb-1));
            for(int i=1; i<mc; i++)
            {
                ans+=daysInMonth[i];
            }
            ans += dc;
            for(int i=yb; i<yc; i++)
            {
                if(i%4==0)
                {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
