#include<bits/stdc++.h>
using namespace std;

int status;
int N, x, y, c;
int totalcoin = 1e3;

void binsearch(int lo, int hi)
{
    if(lo>hi)
        return;
    if(totalcoin<=0)
        return;
    y = (lo+hi)/2;
    cout << 1 << " " << y << "\n";
    cin >> status;
    if(status==1)
    {
        totalcoin -= (c+1);
        cout << 2 << "\n";
        binsearch(lo, y-1);
    }
    else if(status==0)
    {
        totalcoin--;
        binsearch(y+1, hi);
    }
}

int main()
{
    cin >> N >> c;
    binsearch(1, N);
    //x = y+1;
    //x = y;
    cout << 1 << " " << y << "\n";
    cin >> status;
    if(status!=1)
    {
        x = y+1;
    }
    else
    {
        x = y;
    }
    cout << 3 << " " << x;
    return 0;
}
