#include<bits/stdc++.h>
using namespace std;

const int sz = 2000010;

int v[sz];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int ans;
    int m, n;
    int dummy, in;
    cin >> m;
    while(m--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> v[i];
        }
        ans = 0;
        dummy = v[0]+20;
        for(int i=0; i<n; i++)
        {
            while(i<n && v[i]<=dummy)
            {
                i++;
            }
            if(i<n)
            {
                dummy = v[i]+20;
                i--;
            }
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}
