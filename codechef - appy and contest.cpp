#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    int64_t n, a, b, k, lcm, ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b >> k;
        lcm = (a*b)/__gcd(a, b);
        ans = n/a + n/b - 2*(n/lcm);
        if(ans >= k)
        {
            cout << "Win";
        }
        else
        {
            cout << "Lose";
        }
        cout << '\n';
    }
    return 0;
}
