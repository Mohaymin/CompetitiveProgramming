#include<bits/stdc++.h>
using namespace std;
#define sza 120010
#define szb 1000000010
#define szc 31
typedef long long ll;

bitset<szb> isChecked;
ll arr[sza];
ll powerOfTwo[szc];
int n;
int cnt;
bool found;

void initialize()
{
    for(int i=0; i<szc; i++)
    {
        powerOfTwo[i] = 1<<i;
        //cout << i << ": " << powerOfTwo[i] << endl;
    }
}

bool isPowerOfTwo(int pos1, int pos2, ll num)
{
    if(pos1 <= pos2)
    {
        int midPos;
        ll midElement;
        midPos = (pos1+pos2)/2;
        midElement = powerOfTwo[midPos];
        //printf("LO: %d    HI: %d\n", pos1, pos2);
        //cout << "midElement " << midElement << endl;
        //
        //cout << "NUM: " << num << endl;
        //cout << "LOW: " << pos1 << endl;
        //cout << "HIGH: " << pos2 << endl;
        //cout << endl;
        //
        if(num == midElement)
        {
            //printf("FOUND FOR %lld\n\n\n", num);
            return true;
        }
        else if(num > midElement)
        {
            return isPowerOfTwo(midPos+1, pos2, num);
        }
        else // num < midElement
        {
            return isPowerOfTwo(pos1, midPos-1, num);
        }
    }
    else
    {
        //printf("NOT FOUND FOR %lld\n\n\n", num);
        return false;
    }
}

int main()
{
    initialize();
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(isChecked[arr[i]]==0)
        {
            //puts("if");
            found = false;
            for(int j=i+1; j<n; j++)
            {
                //printf("_______CHECKING FOR %lld %lld\n", arr[i], arr[j]);
                if(isPowerOfTwo(0, szc, arr[i]+arr[j]))
                {
                    found = true;
                    isChecked[arr[j]] = 1;
                    cnt++;
                    printf("TRUE FOR %lld %lld \n\n", arr[i], arr[j]);
                    //break;
                }
            }
            if(found)
            {
                cnt++;
            }
            isChecked[arr[i]] = 1;
        }
    }
    cout << n-cnt << endl;
    return 0;
}
