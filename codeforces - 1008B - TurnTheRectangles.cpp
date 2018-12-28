#include<bits/stdc++.h>
using namespace std;
#define sz 100010

typedef pair<int, int> mypair;

mypair arr[sz];
mypair input;
int n;
bool ans;

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &input.first, &input.second);
        if(input.first > input.second)
        {
            swap(input.first, input.second);
        }
        arr[i] = input;
    }
    if(arr[0].first > arr[0].second)
    {
        swap(arr[0].first, arr[0].second);
    }
    ans = true;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i].second < arr[i+1].second)
        {
            if(arr[i].second < arr[i+1].first)
            {
                ans = false;
                break;
            }
            else
            {
                swap(arr[i+1].first, arr[i+1].second);
            }
        }
    }
    if(ans)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}
