#include<bits/stdc++.h>
using namespace std;

int t, a1, a2, a3;
int d, n;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> a1 >> a2 >> a3;
        d = a2-a1;
        n = (a3-a1)/d + 1;
        //cout << "D: " << d << "\tN: " << n << endl;
        ans = (a1+a3)*n/2;
        cout << ans << "\n";
    }
    return 0;
}
