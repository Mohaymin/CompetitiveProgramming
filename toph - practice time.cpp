#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, m, hh, mm, hh2, mm2;
    int totmin;
    vector<pii> v;
    cin >> n;
    totmin = 0;
    while(n--)
    {
        cin >> m;
        while(m--)
        {
            scanf("%d:%d", &hh, &mm);
            scanf("%d:%d", &hh2, &mm2);
            v.push_back(make_pair(hh2*60+mm2, hh*60+mm));
        }
        sort(v.begin(), v.end());
        for(int i=1; i<v.size(); i++)
        {
            totmin = totmin+v[i].second-v[i-1].first;
        }
        v.clear();
    }
    printf("%02d:%02d\n", totmin/60, totmin%60);
    return 0;
}
