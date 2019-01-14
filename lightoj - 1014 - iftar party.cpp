#include<bits/stdc++.h>
using namespace std;

int t, p, l, q;
int caseno;
int lim;

set<int> v;

int main()
{
    //freopen("_in.txt", "r", stdin);
    //freopen("_out.txt", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> p >> l;
        q = p-l;
        lim = sqrt(q);
        for(int i=1; i<=lim; i++)
        {
            if(q%i==0)
            {
                if(i>l)
                    v.insert(i);
                if(q/i>l)
                    v.insert(q/i);
            }
        }

        cout << "Case " << ++caseno << ":";
        if(v.size()<1)
        {
            cout << " impossible";
        }
        else
        {
            for(set<int>::iterator it = v.begin(); it!=v.end(); it++)
            {
                cout << ' ' << *it;
            }
        }
        cout << '\n';
        v.clear();
    }
    return 0;
}
