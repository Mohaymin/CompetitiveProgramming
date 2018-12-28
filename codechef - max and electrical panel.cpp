#include<bits/stdc++.h>
using namespace std;

int broken;
int N, x, y, c;
int totalcoin = 1e3;

int lstbroken, lstunbroken;

void firstoperation(int n)
{
    cout << 1 << " " << n << "\n";
    cin >> broken;
}

void tersearch(int lo, int hi)
{
    if(lo>hi)
        return;
    if(totalcoin<=0)
        return;
    //int y1, y2;

    //y1 = lo + (hi-lo)/3;
    //y2 = hi - (hi-lo)/3;

    y = lo + (hi-lo)/3;
    firstoperation(y);

    if(broken==1)
    {
        lstbroken = y;
        tersearch(lo, y-1);
    }
    else if(broken==0)
    {
        lstunbroken = y;
        y = hi - (hi-lo)/3;
        firstoperation(y);
        if(broken==1)
        {
            lstbroken = y;
            tersearch(lo + ((hi-lo)/3)+1, y-1);
        }
        else if(broken==0)
        {
            lstunbroken = y;
            tersearch(y+1, hi);
        }
    }
}

int main()
{
    cin >> N >> c;
    tersearch(1, N);
    if(lstbroken==lstunbroken+1)
    {
        x = lstbroken;
    }
    cout << 3 << " " << x;
    return 0;
}
