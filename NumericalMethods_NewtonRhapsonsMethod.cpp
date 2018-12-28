/// Newton Rhapson's method
#include<bits/stdc++.h>
using namespace std;
#define prline puts("_____________________________________________________________________________")
#define EPS 0.001
typedef double dd;


void getInput(dd arr[], int deg)
{
    puts("Enter the value of:");

    for(int i=0; i<=deg; i++)
    {
        cout << "a" << deg-i << ": ";
        cin >> arr[i];
    }
}


double useHorner(dd arr[], dd x, dd deg)
{
    dd res = arr[0];
    for(int i=1; i<=deg; i++)
    {
        res = res*x + arr[i];
        //cout << arr[i] << endl;
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
        cout << "Iteration " << ++cnt << ":\t";
        cout << fixed << setprecision(3) << x0 << "\t";
        cout << fixed << setprecision(3) << x1 << "\t";
        cout << fixed << setprecision(3) << f1 << "\t";
        cout << fixed << setprecision(3) << f2 << "\t";
        cout << fixed << setprecision(3) << err << endl;
        x0 = x1;
    }
    while(err >= EPS);
    return x1;
}


int main()
{
    dd mainEq[101];
    dd diffEq[100];

    int deg;

    cout << "Enter highest degree: ";
    cin >> deg;

    getInput(mainEq, deg);

    cout << "Enter highest degree: ";
    cin >> deg;

    getInput(diffEq, deg);

    prline;
    printf("\t\t x0 \t x1 \t f1 \t f2 \t err \n");
    prline;
    dd root = NewtonRhapson(mainEq, diffEq, 0, deg+1);
    prline;
    cout << "Approximate value: " << root << endl;

    return 0;

}
