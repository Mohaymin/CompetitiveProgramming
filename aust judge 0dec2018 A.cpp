#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    long ans = 0;
    for(int i=1; n/i > (i-1); i++)
    {
        ans += ((n/i)-(i-1));
    }
    cout << ans << "\n";
    return 0;
}
