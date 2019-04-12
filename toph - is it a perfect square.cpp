#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
bool nonprime[110];

void sieve()
{
    int sz = 110;
    for(int i=4; i<110; i+=2)
    {
        nonprime[i] = true;
    }
    for(int i=3; i<20; i+=2)
    {
        if(!nonprime[i])
        {
            for(int j=i*i; j<110; j=j+i+i)
            {
                nonprime[j] = true;
            }
        }
    }
    for(int i=2; i<110; i++)
    {
        if(!nonprime[i])
        {
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, n, ai;
    map<int, int> foundprimes;
    bool ans;
    sieve();
    cin >> t;
    while(t--)
    {
        cin >> n;
        while(n--)
        {
            cin >> ai;
            for(int x: primes)
            {
                if(ai<=1)
                {
                    break;
                }
                while(ai%x==0)
                {
                    ai /= x;
                    foundprimes[x]++;
                }
            }
        }
        ans = true;
        for(pair<int,int> x: foundprimes)
        {
            if(x.second%2==1)
            {
                ans = false;
                break;
            }
        }
        if(ans)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << '\n';
        foundprimes.clear();
    }
    return 0;
}
