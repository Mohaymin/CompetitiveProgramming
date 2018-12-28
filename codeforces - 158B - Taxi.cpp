#include<bits/stdc++.h>
using namespace std;

int n, in, t1, t2, t3, t4, ttaxi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    while(n--)
    {
        cin >> in;
        if(in==1)
            t1++;
        else if(in==2)
            t2++;
        else if(in==3)
            t3++;
        else if(in==4)
            t4++;
    }

    ttaxi += t4;
    ttaxi += t2/2;
    if(t2%2 == 1)
    {
        ttaxi++;
        if(t1>=2)
            t1 -= 2;
        else if(t1==1)
            t1--;
    }
    ttaxi += t3;
    t1 = t1 - t3;
    if(t1>0)
    {
        ttaxi += t1/4;
    }
    if(t1%4 > 0)
    {
        ttaxi++;
    }
    cout << ttaxi << endl;
    return 0;
}
