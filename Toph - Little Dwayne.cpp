#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, D, K;
    int mails;
    int ans;
    int tmp;
    cin >> T;
    while(T--)
    {
        ans = 0;
        cin >> D >> K;
        for(int i=0; i<D; i++)
        {
            cin >> mails;
            tmp = mails-K;
            if(tmp > 0)
            {
                ans += tmp;
            }
        }
        cout << ans << endl;
    }
}
