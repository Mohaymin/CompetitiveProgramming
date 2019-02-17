#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll m = 1e9+7;

ll binexpo(ll a,  ll b)
{
    ll res = 1;
    while(b>0)
    {
        if(b&1)
        {
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    int rem;
    ll n, ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        rem = n%3;
//        ans = binexpo(3, n/3);
//        if(rem==1 && n!=1)
//        {
//            ans = (ans/3*4)%m;
//        }
//        else if(rem==2)
//        {
//            ans = (ans*2)%m;
//        }
        if(n==1)
        {
            ans = 1;
        }
        else if(rem==0)
        {
            ans = binexpo(3, n/3);
        }
        else if(rem==1)
        {
            ans = (binexpo(3, (n-4)/3)*4)%m;
        }
        else if(rem==2)
        {
            ans = (binexpo(3, n/3)*2)%m;
        }
        cout << ans << '\n';
    }
    return 0;
}
