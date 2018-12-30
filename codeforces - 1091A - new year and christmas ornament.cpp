#include<bits/stdc++.h>
using namespace std;


int main()
{
    int ans, y, b, r;
    cin >> y >> b >> r;
    ans = min(y, min(b-1, r-2));
    cout << 3*(ans+1) << "\n";
    return 0;
}
