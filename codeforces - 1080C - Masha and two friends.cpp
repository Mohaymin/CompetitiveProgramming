#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> mypair;

int t;
int n, m;
int x, y;

ll totalsq, whitesq, blacksq;

mypair p1, p2, p3, p4;

bool isBlack(mypair p)
{
    if(p.first%2 != p.second%2)
        return true;
    return false;
}

bool doesOverlap(mypair p3, mypair p2)
{
    if(p3.first<=p2.first)
    {
        if(p3.)
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cin >> x >> y;
        p1 = make_pair(x, y);
        cin >> x >> y;
        p2 = make_pair(x, y);
        cin >> x >> y;
        p2 = make_pair(x, y);
        cin >> x >> y;
        p4 = make_pair(x, y);

        if(p2.first<p1.first)
            swap(p1, p2);
        if(p4.first<p3.first)
            swap(p3, p4);

        totalsq = m*n;
        whitesq = (totalsq+1)/2;
        blacksq = totalsq-whitesq;
    }
}
