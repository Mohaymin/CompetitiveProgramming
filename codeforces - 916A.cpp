#include<bits/stdc++.h>
using namespace std;

bool isLucky(int n)
{
    if(n%10==7 || n/10==7)
        return true;
    return false;
}

int main()
{
    int X, HH, MM;
    int cnt=0;
    bool shouldContinue=true;
    cin >> X >> HH >> MM;
    int i, j;
    i=HH, j=MM;
    while(!isLucky(i)&&shouldContinue)
    {
        while(j>=0)
        {
            if(isLucky(j))
            {
                shouldContinue=false;
                break;
            }
            j=j-X;
            cnt++;
        }
        j=60+j;//value of j has to be negetive if no lucky found
        i=(23+i)%24;//i=(24+i-1)%24;
    }
    cout << cnt << endl;
    return 0;
}
