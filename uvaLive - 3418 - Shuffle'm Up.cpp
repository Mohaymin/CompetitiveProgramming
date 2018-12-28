#include<bits/stdc++.h>
using namespace std;

string s1, s2, s12, dummy;

int n, c;

int cnt, ans, lim;

bool found;

int main()
{
    //freopen("_in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    while(n--)
    {
        cin >> c >> s1 >> s2 >> s12;
        found = false;
        ans = 0;
        //lim = 1001;
        while(ans < 1001)
        {
            ans++;
            dummy.clear();
            for(int i=0; i<c; i++)
            {
                dummy += s2[i];
                dummy += s1[i];
            }
            if(dummy==s12)
            {
                found = true;
                break;
            }
            s1.clear();
            s2.clear();
            //lim = 2*c;
            lim = c;
            for(int i=0; i<lim; i++)
            {
                //if(i<c)
                    s1 += dummy[i];
                //else
                    s2 += dummy[i+c];
            }
        }
        if(!found)
        {
            ans = -1;
        }
        cout << ++cnt << " " << ans << "\n";
    }
    return 0;
}
