#include<bits/stdc++.h>
using namespace std;

const int sz = 110;

struct ingredient
{
    int x;
    int y;
    int sm;
    int pm;
    int sv;
    int pv;
    int shortage;
    int reqexpenditure;
};
typedef struct ingredient ingredient;

bool compare(ingredient a, ingredient b)
{
    return a.reqexpenditure < b.reqexpenditure;
}

ingredient arr[sz];

int ans;
int a, b;
int n, m;
int mncost;
int lim1, lim2;

double getRatio(double a, double b)
{
    return a/b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i].x;
        cin >> arr[i].y;
        cin >> arr[i].sm;
        cin >> arr[i].pm;
        cin >> arr[i].sv;
        cin >> arr[i].pv;
        if(arr[i].y >= arr[i].x)
            arr[i].shortage = 0;
        else
            arr[i].shortage = arr[i].x-arr[i].y;
        arr[i].reqexpenditure = numeric_limits<int>::max();
        a = arr[i].sv;
        b = arr[i].sm;
        lim1 = arr[i].shortage/a;
        lim2 = arr[i].shortage/b;
        mncost = arr[i].reqexpenditure;
        for(int x=0, y=0; x<=lim1; x++)
        {
            if(a*x >= arr[i].shortage)
            {
                if(arr[i].pv*x <= m)
                {
                    mncost = min(mncost, arr[i].pv*x);
                }
                //break;
            }
            else
            {
                y = ceil(getRatio(arr[i].shortage-a*x, b));
                if(arr[i].pm*y <= m)
                {
                    mncost = min(mncost, arr[i].pv*x+arr[i].pm*y);
                }
            }
        }
        arr[i].reqexpenditure = mncost;
    }
    sort(arr, arr+n, compare);
    for(int i=0; i<n && m>0; i++)
    {
        if(arr[i].shortage==0)
        {
            ans++;
            continue;
        }
        /////
        if(arr[i].reqexpenditure <= m)
        {
            m -= mncost;
            ans++;
        }
        else
        {
            //break;
        }
    }
    cout << ans << "\n";
    return 0;
}
