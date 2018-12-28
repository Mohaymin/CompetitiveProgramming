#include<bits/stdc++.h>
using namespace std;

const int len = 5;

int N;
int lim;

bool n, s, u, p;

string input;

int cnt[len];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N >> input;
    n = s = u = p = true;
    lim = input.size();
    for(int i=0; i<lim; i++)
    {
        if(n &&input[i]=='N')
        {
            cnt[0]++;
        }
        else if(s && input[i]=='S')
        {
            cnt[1]++;
        }
        else if(u && input[i]=='U')
        {
            cnt[2]++;
            n = s = false;
        }
        else if(p && input[i]=='P')
        {
            cnt[3]++;
            n = s = u = false;
        }
        else if(!s && input[i]=='S')
        {
            cnt[4]++;
            n = s = u =  p = false;
        }
    }
    long ans = 1;
    for(int i=0; i<len; i++)
    {
        ans *= cnt[i];
    }
    cout << ans << "\n";
    return 0;
}
