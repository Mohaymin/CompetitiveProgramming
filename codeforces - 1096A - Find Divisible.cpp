#include<bits/stdc++.h>
using namespace std;

int x, y, l, r;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        cout << l << " " << l*(r/l) << "\n";
    }
    return 0;
}
