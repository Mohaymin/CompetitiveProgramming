#include<bits/stdc++.h>
using namespace std;
#define take cin >>
#define print cout <<

const int sz = 110;

int arr[sz][sz];
char ans[sz][sz];

int test;
int totalNodes;
int relation;
int i, j, k;
int cnt;

void prLine()
{
    print "+";
    for(int i=1; i<totalNodes*2; i++)
        print "-";
    print "+\n";
}

int main()
{
    freopen("_in.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    take test;

    while(test--)
    {
        take totalNodes;
        for(i=1; i<=totalNodes; i++)
        {
            for(j=0; j<totalNodes; j++)
            {
                take relation;
                arr[i][j] = arr[i-1][j] + relation;
                ans[i][j] = 'N';
            }
        }
        for(i=totalNodes, j=1; j<totalNodes; j++)
        {
            if(arr[i][j]==1)
            {
                for(k=i-1; arr[k][j]!=0; k--);
                ans[k][j] = 'Y';
            }
            ans[j][j] = 'Y';
        }

        // output
        print "Case ";
        print ++cnt;
        print ":\n";

        prLine();

        print "|";
        for(i=0; i<totalNodes; i++)
            print "Y|";
        print "\n";

        prLine();

        for(i=1; i<totalNodes; i++)
        {
            print "|";
            for(j=0; j<totalNodes; j++)
            {
                print ans[i][j];
                print "|";
            }
            print "\n";

            prLine();
        }
    }
    return 0;
}
