#include<bits/stdc++.h>
using namespace std;
#define sz 1000006
bitset<sz> b;
typedef long long ll;

void sieve()
{
    int lim = sqrt(sz);
    for(int i=4; i<sz; i+=2)
    {
        b[i] = 1;
    }
    for(int i=3; i<=lim; i+=2)
    {
        if(b[i]==0)
        {
            for(int j=i*i; j<sz; j=j+i+i)
            {
                b[j] = 1;
            }
        }
    }
}

// 0 -> prime
// 1 -> not prime


bool isPrime(ll x)
{
    if(b[x]==0)
        return true;
    return false;
}


int main()
{
    sieve();
    int n;
    cin >> n;
    ll data;
    bool ans;
    double d;
    for(int i=0; i<n; i++)
    {
        //cin >> data;
        scanf("%I64d", &data);
        if(data%2==0)
        {
            if(data==4)
                ans=true;
            else
                ans=false;
        }
        else
        {
            d = sqrt(data);
            if(data == 1)
                ans = false;
            else if(ceil(d) == floor(d))
            {
                if(isPrime(d))
                ans = true;
                else
                ans = false;
            }
            else
                ans = false;
        }
        if(ans)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
