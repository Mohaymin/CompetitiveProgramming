#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, n;
    cin >> n >> a >> b;
    int ans=0;
    for(int i=1; i<n; i++)
    {
        ans = max(ans, min(a/i, b/(n-i)));
    }
    cout << ans << endl;
    return 0;
}
