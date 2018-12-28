#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s, d;
ll nxtgroup;
ll day, ans, cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while(cin >> s >> d)
    {
        day = s;
        cnt = 0;
        nxtgroup = s+1;

        while(day<d)
        {
            day += nxtgroup;
            nxtgroup++;
            cnt++;
        }
        ans = s+cnt;
        cout << ans << "\n";
    }
    return 0;
}
