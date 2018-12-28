#include<bits/stdc++.h>
using namespace std;
#define sz 10000010

typedef long long ll;

int t;
ll f, gcd;
ll dummy;
vector<ll> primes;
bitset<sz> b;
ll ans;

void sieve()
{
    for(ll i=4; i<=sz; i++)
    {
        b[i] = 1;
    }
    primes.push_back(2);
    dummy = sqrt(sz);
    for(ll i=3; i<=dummy; i++)
    {
        if(b[i]==0)
        {
            primes.push_back(i);
            for(ll j=i*i; j<=sz; j+= i+i)
            {
                b[j] = 1;
            }
        }
    }
}

int getLevel(ll num)
{
    if(b[num]==0)
        return 0;
    int lim = sqrt(num);
    for(int i=0; i<=lim; i++)
    {
        if(num%primes[i]==0)
        {
            return 1+getLevel(num/primes[i]);
        }
    }
    return 0;
}

int main()
{
    sieve();
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> f >> gcd;
        ans = getLevel(f*gcd);
        if(ans==0)
        {
            ans = 1;
        }
        else
        {
            ans = 2*ans;
        }
        cout << ans << "\n";
    }
    return 0;
}

