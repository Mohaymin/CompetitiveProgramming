#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int x, y, n;
ll sx, sy;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=0; i<2*n; i++)
    {
        cin >> x >> y;
        sx += x;
        sy += y;
    }
    cout << sx/n << " " << sy/n;
    return 0;
}
