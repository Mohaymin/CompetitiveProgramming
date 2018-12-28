#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cnt=0;
    int i, j, k;
    for(k=n; k>0; k--)
    {
        for(j=k; j>0; j--)
        {
            i=j^k;
            if(i<=j && i+j>k)
            {
                //printf("i: %d  j: %d  k: %d\n", i, j, k);
                cnt++;
                //break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
