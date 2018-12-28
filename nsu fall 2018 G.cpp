#include<bits/stdc++.h>
using namespace std;

int t, ans;
int lim, cnt;
string input;

stack<char> s;


void clearstack()
{
    while(s.empty()!=true)
    {
        s.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> input;
        cnt = ans = 0;
        lim = input.size();
        for(int i=0; i<lim; i++)
        {
            if(input[i]=='(')
            {
                s.push('(');
            }
            else
            {
                if(s.empty())
                    continue;
                cnt = 0;
                while(i<lim && input[i]!='(')
                {
                    if(s.size()>0)
                    {
                        s.pop();
                        cnt++;
                        ans = max(ans, cnt);
                    }
                    else
                    {
                        break;
                    }
                    i++;
                }
                clearstack();
                i--;
            }
        }
        cout << ans*2 << "\n";
        clearstack();
    }
    return 0;
}
