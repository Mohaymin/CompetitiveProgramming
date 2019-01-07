#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    int dum;
    long long ans;
    int x, y;
    x = ceil(sqrt(n));
    y = floor(sqrt(n));
    if(x*y>=n)
    {
        ans = x+y;
    }
    else
    {
        ans = x+y+1;
    }
    cout << ans << '\n';
    return 0;
}
