#include<bits/stdc++.h>
using namespace std;

typedef double dd;

int n, k;
dd red, green, blue;
dd required;
long long ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    red = n*2;
    green = n*5;
    blue = n*8;
    required = ceil(red/k) + ceil(green/k) + ceil(blue/k);
    ans = required;
    cout << ans << "\n";
    return 0;
}
