#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if((a+b)%2==(c+d)%2)
    {
        cout << "black";
    }
    else
    {
        cout << "white";
    }
    return 0;
}
