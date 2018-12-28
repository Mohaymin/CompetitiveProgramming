#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, c, k, w;
    cin >> t;
    while(t--)
    {
        cin >> c >> k >> w;
        if(c*w <= k)
            cout << "yes";
        else
            cout << "no";
        cout << "\n";
    }
    return 0;
}
