#include<bits/stdc++.h>
using namespace std;

const int sz = 1010;

int t, n, m, q;
int firstplayer, secondplayer, cnt;

int parentof[sz];

void init()
{
    for(int i=1; i<=n; i++)
    {
        parentof[i] = i;
    }
}

int getparentof(int i)
{
    if(parentof[i]==i)
        return i;
    return getparentof(parentof[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> q;
        init();
        for(int i=0; i<m; i++)
        {
            cin >> firstplayer >> secondplayer;
            if(getparentof(firstplayer)!=getparentof(secondplayer))
            {
                parentof[getparentof(firstplayer)] = getparentof(secondplayer);
            }
        }
        cout << "Case " << ++cnt << ":\n";
        for(int i=0; i<q; i++)
        {
            cin >> firstplayer >> secondplayer;
            if(getparentof(firstplayer)==getparentof(secondplayer))
            {
                cout << "Chicken dinner coming soon!";
            }
            else
            {
                cout << "Eat vegetables!";
            }
            cout << "\n";
        }
    }
    return 0;
}
