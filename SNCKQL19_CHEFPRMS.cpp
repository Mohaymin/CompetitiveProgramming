#include<bits/stdc++.h>
using namespace std;

const int sz = 201;
int n, t;

int main()
{
    int primes[] =
    {
        2, 3, 5, 7, 11,

        13, 17, 19, 23, 29,

        31, 37, 41, 43, 47,

        53, 59, 61, 67, 71,

        73, 79, 83, 89, 97,

        101, 103, 107, 109, 113,

        127, 131, 137, 139, 149,

        151, 157, 163, 167, 173,

        179, 181, 191, 193, 197,

        199
    }; // total 46

    vector<int> semiPrimes;
    int num;

    for(int i=0; i<46; i++)
    {
        for(int j=i+1; j<46; j++)
        {
            num = primes[i]*primes[j];
            if(num < sz)
            {
                semiPrimes.push_back(num);
            }
            else
            {
                break;
            }
        }
    }
    sort(semiPrimes.begin(), semiPrimes.end());

    bool ans;
    int lim = semiPrimes.size();

    scanf("%d", &t);
    while(t--)
    {
        ans = false;
        scanf("%d", &n);
        for(int i=0; i<lim; i++)
        {
            num = n-semiPrimes[i];
            if(num < 0)
            {
                break;
            }
            if(binary_search(semiPrimes.begin(), semiPrimes.end(), num))
            {
                ans = true;
                break;
            }
        }
        if(ans)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}
