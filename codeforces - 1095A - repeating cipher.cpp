#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string str;
    int n;
    cin >> n;
    cin >> str;
    int j = 0;
    for(int i=0; i<n; i+=j)
    {
        cout << str[i];
        j++;
    }
    return 0;
}
