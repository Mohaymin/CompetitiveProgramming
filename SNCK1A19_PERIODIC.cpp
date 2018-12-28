#include<bits/stdc++.h>
using namespace std;
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int sz = 100010;

bool isImpossible;

int mx;
int i, j;
int t, n;
int arr[sz];

int main()
{
    FASTER;
    cin >> t;
    while(t--)
    {
        isImpossible = false;
        cin >> n;
        for(i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        mx = -100;
        for(int i=0; i<n; i++)
        {
            if(arr[i] > 0 && (i+1)%arr[i] != 0)
            {
                isImpossible = true;
                break;
            }
            mx = max(mx, arr[i]);
        }
        // isImpossible ==  true  ---> impossible
        // mx == -1 ---> inf
        // otherwise ---> mx or something else?
    }
}
