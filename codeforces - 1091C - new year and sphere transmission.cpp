#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sumOf(ll n, ll d)
{
    //ll a = 1;
    n = 1+(n-1)/d;
    return n * (2+(n-1)*d) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, lim;
    cin >> n;
    set<ll> v;
    for(int i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            v.insert(sumOf(n, i));
            v.insert(sumOf(n, n/i));
        }
    }
    v.insert(1);
    set<ll>::iterator it;
    for(it=v.begin(); it!=v.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}
