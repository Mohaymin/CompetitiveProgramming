#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    long long ans;
    while(cin >> n)
    {
        if(n==0)
            return 0;
        ans = 0;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                ans += __gcd(j, i);
            }
        }
        cout << ans << '\n';
    }
}
