#include<bits/stdc++.h>
using namespace std;

int arr1[4];
int arr2[4];
int test;
char ch;
bool ans;
int cnt;
stack<int> s;

int main()
{
    //freopen("_in.txt", "r", stdin);
    cin >> test;
    while(test--)
    {
        scanf("%d.%d.%d.%d",
              &arr1[0], &arr1[1],
              &arr1[2], &arr1[3]);
//        printf("%d %d %d %d\n",
//              arr1[0], arr1[1],
//              arr1[2], arr1[3]);
        getchar();
        for(int i=0; i<4; i++)
        {
            arr2[i]=0;
            do
            {
                scanf("%c", &ch);
                if(ch == '\n')
                    break;
                if(ch == '0')
                    arr2[i] = arr2[i] << 1;
                else if(ch=='1')
                {
                    //s.push(0);
                    arr2[i] = arr2[i] << 1;
                    arr2[i] |= 1;
                }
                //cout << arr2[i] << endl;
            } while(ch=='0' || ch=='1');
            //cout << arr2[i] << endl;
            //puts("_________");
        }

        ans = true;
        for(int i=0; i<4; i++)
        {
            if(arr1[i] != arr2[i])
            {
                //printf("%d != %d\n", arr1[i], arr2[i]);
                ans = false;
                break;
            }
        }
        printf("Case %d: ", ++cnt);
        if(ans)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
