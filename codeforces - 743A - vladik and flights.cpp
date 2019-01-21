#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, a, b;
    string s;
    int ans;
    cin >> n >> a >> b >> s;
    if(s[a-1]==s[b-1])
    {
        ans = 0;
    }
    else
    {
        ans = 1;
    }
    cout << ans << '\n';
    return 0;
}

