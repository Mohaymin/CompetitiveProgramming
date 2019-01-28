#include<bits/stdc++.h>
using namespace std;

const int sz = 2e5+10;

int arr[sz];
int a, b, n, t, ai;

int lcm, alicecount, bobcount, lcmcount;

bool bobwins;

int getLcm(int a, int b)
{
    int gcd = __gcd(a, b);
    return a*b/gcd;
}

int main()
{
    //freopen("_in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b;
        lcm = getLcm(a, b);
        alicecount = bobcount = lcmcount = 0;
        for(int i=0; i<n; i++)
        {
            cin >> ai;
            if(ai%a==0) bobcount++;
            else if(ai%b==0) alicecount++;
//            if(ai%lcm==0)
//            {
//                lcmcount++;
//            }
//            else if(ai%a==0)
//            {
//                bobcount++;
//            }
//            else if(ai%b==0)
//            {
//                alicecount++;
//            }
        }

        //bobcount += (lcmcount%2);

        if(bobcount>alicecount)
        {
            bobwins = true;
        }
        else
        {
            bobwins = false;
        }

        if(bobwins)
        {
            cout << "BOB";
        }
        else
        {
            cout << "ALICE";
        }
        cout << "\n";
    }
    return 0;
}
