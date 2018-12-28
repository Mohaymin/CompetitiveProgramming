#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int N, in;
    int ans;
    cin >> N;
    while(N--)
    {
        cin >> in;
        s.insert(in);
    }
    ans = s.size();
    set<int>::iterator it = s.begin();
    if(*it == 0) ans--;
    cout << ans << endl;
    return 0;
}
