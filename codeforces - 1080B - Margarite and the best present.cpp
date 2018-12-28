#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans;
ll q, l, r;
ll oddsum, evensum;
ll fe, fo, le, lo, ne, no;

int main()
{
    //freopen("_in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> l >> r;

        fe = l+(l%2);
        fo = l+1-(l%2);
        le = r-(r%2);
        lo = r-1+(r%2);

//        ne = fabs(le-fe)/2+1;
//        no = fabs(lo-fo)/2+1;
        ne = (le-fe)/2+1;
        no = (lo-fo)/2+1;

        evensum = (fe+le)*ne;
        oddsum = (fo+lo)*no;

        ans = (evensum - oddsum)/2;
        cout << ans << "\n";
    }
    return 0;
}
