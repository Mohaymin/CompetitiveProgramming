#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a, s;
    cin>>n>>m;

    vector<vector<int> >r;

    r.assign(m+1, 0);

    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s; j++){
            cin>>a;
            r[a].pop_back();
            r[a].push_back(1);
        }
    }

    for(int i=1; i<=m; i++){
        if(r[i].front() != 1){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}
