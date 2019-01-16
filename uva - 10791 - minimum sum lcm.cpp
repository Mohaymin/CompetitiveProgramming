#include<bits/stdc++.h>
using namespace std;

const int N = 1<<16;
typedef long long ll;

vector<int> prime;
bool notPrime[N+10];

void sieve()
{
    for(int i=4; i<N; i+=2)
    {
        notPrime[i] = true;
    }
    for(int i=3; i*i<=N; i+=2)
    {
        if(notPrime[i]==false)
        {
            for(int j=i*i; j<N; j=j+i+i)
            {
                notPrime[j] = true;
            }
        }
    }
    prime.push_back(2);
    for(int i=3; i<N; i++)
    {
        if(notPrime[i]==false)
        {
            prime.push_back(i);
        }
    }
}

int main()
{
    //freopen("_in.txt", "r", stdin);
    //freopen("_out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    sieve();

    ll tcase, totalFactor, dummy;

    ll n, answer, factor, totalPrimes;

    tcase = 0;
    totalPrimes = prime.size();
    while(cin>>n && n!=0)
    {
        if(n==1)
        {
            answer = 2;
        }
        else
        {
            dummy = n;
            answer = totalFactor = 0;
            for(int i=0; i<totalPrimes && dummy!=1; i++)
            {
                if(dummy%prime[i]==0)
                {
                    factor = 1;
                    totalFactor++;
                    while(dummy%prime[i]==0)
                    {
                        dummy /= prime[i];
                        factor *= prime[i];// similar to p^x
                    }
                    answer += factor;
                }
            }
            if(totalFactor==0)
            {
                answer = n+1;
            }
            else if(totalFactor==1 && dummy==1)
            {
                answer = n+1;
            }
            else if(dummy>1)
            {
                answer += dummy;
            }

        }
        cout << "Case " << ++tcase << ": " << answer << '\n';
    }
    return 0;
}
