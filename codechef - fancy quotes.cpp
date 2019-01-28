#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s;
    int t, l;
    cin >> t;
    bool realfancy;
    getline(cin, s);
    while(t--)
    {
        realfancy = false;
        getline(cin, s);
        l = s.size()-2;
        for(int i=0; i<l; i++)
        {
            if(s[i]=='n'&&s[i+1]=='o'&&s[i+2]=='t')
            {
                if((i-1<0 || s[i-1]==' ') && (i+3>=s.size() || s[i+3]==' '))
                realfancy = true;
                break;
            }
        }
        if(realfancy)
        {
            cout << "Real Fancy";
        }
        else
        {
            cout << "regularly fancy";
        }
        cout << '\n';
    }
    return 0;
}
