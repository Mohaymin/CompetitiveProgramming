#include<bits/stdc++.h>
using namespace std;

const int MXSIZE = 110;

int a[MXSIZE], d[MXSIZE];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, n;
    int ans;
    cin >> t;
    while(t--)
    {
        ans = -1;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        for(int i=0; i<n; i++)
        {
            cin >> d[i];
        }
        for(int i=0; i<n; i++)
        {
            if(d[i]-a[(i+1)%n]-a[(n+i-1)%n] > 0)
            {
                ans = max(ans, d[i]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
