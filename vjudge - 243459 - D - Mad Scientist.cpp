#include<bits/stdc++.h>
using namespace std;

int k;
int p[30];
int previous075, pres, diff;
bool firstPrintDone;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>k)
    {
        if(k==0)
            return 0;
        for(int i=0; i<k; i++)
        {
            cin >> p[i];
        }
        previous075 = 0;
        firstPrintDone = false;
        for(int i=1; i<=k; i++)
        {
            pres = p[i-1];
            if(previous075==pres)
                continue;
            diff = pres-previous075;
            previous075 = pres;
            if(firstPrintDone)
            {
                cout << " ";
            }
            firstPrintDone = true;
            cout << i;
            while(--diff)
            {
                cout << " " << i;
            }
        }
        cout << "\n";
    }
}
