#include<bits/stdc++.h>
using namespace std;

int main()
{
    double T, N, K;
    int cnt;
    unsigned long long ans;
    cin >>  T;
    cnt = 0;
    while(T--)
    {
        cin >> N >> K;
        if(K>N)
        {
            ans = 0;
        }

        else
        {
            ans = 1;
            while(K>0)
            {
                ans = ans * (N*N)/K;
                K--;
                N--;
            }
        }
        printf("Case %d: ", ++cnt);
        cout << ans << endl;
    }
    return 0;
}
