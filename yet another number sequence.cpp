#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t, a, b, m, n;
ll ans, ai, bi;
ll md;

int main()
{
    //freopen("_in.txt", "r", stdin);
    //freopen("_out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n >> m;
        md = pow(10, m);

        ai = a;
        bi = b;
        n--;

        if(n==0) ans = a;
        else if(n==1) ans = b;

        while(n>0)
        {
            //ans = (ai+bi)%md;
            ans = ai+bi;
            ai = bi;
            bi = ans;
            n--;
        }
        cout << ans%md << "\n";
    }

    return 0;
}
