#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll q, n, a, b, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n >> a >> b;
        ans = min(a*n, (n>>1)*b+(n&1)*a);
        cout << ans << '\n';
    }
    return 0;
}
