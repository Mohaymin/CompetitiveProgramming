#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, r;
    int pow, day;
    string s, ans;
    cin >> n >> m;
    pow = day = 0;
    while(m--)
    {
        cin >> s >> r;
        if(r>=pow)
        {
            ans = s;
            pow = r;
        }
        cout << "Day " << ++day << ": ";
        cout << ans << "\n";
    }
    return 0;
}
