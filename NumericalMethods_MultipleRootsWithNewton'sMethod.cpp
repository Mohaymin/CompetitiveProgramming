/// MULTIPLE ROOTS WITH NEWTON'S METHOD

#include<bits/stdc++.h>
using namespace std;
#define EPS 0.001
typedef double dd;


dd root[100];


void printArray(dd arr[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void getInput(dd arr[], int deg)
{
    puts("Enter the value of:");

    for(int i=0; i<=deg; i++)
    {
        cout << "a" << deg-i << ": ";
        cin >> arr[i];
    }
}


void deflate(dd eqn[], dd root, int newDegree)
{
    dd tmp = 0;
    for(int i=0; i<=newDegree; i++)
    {
        eqn[i] = eqn[i] + root*tmp;
        tmp = eqn[i];
    }
}


dd useHorner(dd arr[], dd x, dd deg)
{
    dd res = arr[0];
    for(int i=1; i<=deg; i++)
    {
        res = res*x + arr[i];
    }
    return res;
}


dd NewtonRhapson(dd mainEq[], dd diffEq[], dd x0, int deg)
{
    int cnt = 0;
    dd f1, f2, x1, err;
    do
    {
        f1 = useHorner(mainEq, x0, deg);
        f2 = useHorner(diffEq, x0, deg-1);
        x1 = x0 - f1/f2;
        err = fabs((x1-x0)/x1);
        x0 = x1;
    }
    while(err >= EPS);
    return x1;
}


void differenciate(dd mainEq[], dd diffEq[], int degree)
{
    int i, n;
    for(i=0, n=degree; n>=0; i++, n--)
    {
        diffEq[i] = mainEq[i] * n;
    }
}


void getRootUsingNewtonsMethod(dd mainEqn[], dd diffEqn[], int degree, dd x0)
{
    dd xr;
    int i = 0;
    while(degree>1)
    {
        differenciate(mainEqn, diffEqn, degree);

        xr = NewtonRhapson(mainEqn, diffEqn, x0, degree);
        root[i++] = xr;

        deflate(mainEqn, xr, --degree);
    }
    root[i] = -(mainEqn[1]/mainEqn[0]);
}


int main()
{
    dd mainEq[101];
    dd diffEq[100];

    int deg;

    cout << "Enter highest degree: ";
    cin >> deg;

    getInput(mainEq, deg);

    getRootUsingNewtonsMethod(mainEq, diffEq, deg, 0);

    puts("\nRoots:");
    printArray(root, deg);

    return 0;

}
