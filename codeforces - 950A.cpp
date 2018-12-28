#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l, r, a;
    cin >> l >> r >> a;
    //cout << 2*min(l, r) + 2*min(max(l, r), a) << endl;
    int mx, mn, diff, ans;
    mx = max(l, r);
    mn = min(l, r);
    diff = mx-mn;
    ans = 2*mn + 2*min(diff, a);
    if(a>diff)
    {
        a = a - diff;
        a = a - a%2;
        ans += a;
    }
    cout << ans << endl;
    return 0;
}
