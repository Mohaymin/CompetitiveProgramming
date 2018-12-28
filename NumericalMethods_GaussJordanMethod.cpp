/// GAUSS JORDAN METHOD
#include<bits/stdc++.h>
using namespace std;

typedef double dd;


int main()
{
    freopen("_in.txt", "r", stdin);

    int totalEq;
    printf("ENTER NUMBER OF EQUATIONS = ");
    cin >> totalEq;

    int k;
    dd tmp;
    dd pivot;
    dd matrixA[totalEq][totalEq+1];
    dd root[totalEq];
    dd matrixB[totalEq];

    cout << "ENTER COEFFICIENTS OF EQUATIONS = ";
    puts("");

    for(int i=0; i<totalEq; i++)
    {
        for(int j=0; j<=totalEq; j++)
        {
            cin >> matrixA[i][j];
        }
    }
    ///input done


    /////////////////////GAUSS-JORDAN
    for(int i=0; i<totalEq; i++)
    {
        pivot = matrixA[i][i];
        for(int j=0; j<=totalEq; j++)
        {
            matrixA[i][j] /= pivot;
        }///i-th equation normalized

        for(int k=(i+1)%totalEq; k!=i; k=(k+1)%totalEq)
        {
            tmp = matrixA[k][i];
            for(int j=0; j<=totalEq; j++)
            {
                matrixA[k][j] -= tmp*matrixA[i][j];
            }
        }
        for(int p=0; p<totalEq; p++)
        {
            for(int q=0; q<=totalEq; q++)
            {
                cout << fixed << setprecision(1) << matrixA[p][q] << "   ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Required roots: ";
    for(int i=0; i<totalEq; i++)
    {
        cout << matrixA[i][totalEq] << " ";
    }
    return 0;
}
