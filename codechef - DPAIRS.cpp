#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    int num;
    vector<pair<int, int> > aset, bset;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> num;
        aset.push_back(make_pair(num, i));
    }
    for(int i=0; i<m; i++)
    {
        cin >> num;
        bset.push_back(make_pair(num, i));
    }
    // input complete;
    sort(aset.begin(), aset.end());
    sort(bset.begin(), bset.end());
    int ind1 = aset[0].second;
    int ind2 = bset[bset.size()-1].second;
    for(int i=0; i<m; i++)
    {
        cout << ind1 << ' ' << i << '\n';
    }
    for(int i=0; i<n; i++)
    {
        if(i!=ind1)
            cout << i << ' ' << ind2 << '\n';
    }
    return 0;
}
