/// Secant Method
#include<bits/stdc++.h>
using namespace std;

#define EPS 0.001

typedef double dd;

dd coeff[101];
int deg;

void getInput()
{
    puts("Enter the value of:");

    for(int i=0; i<=deg; i++)
    {
        cout << "a" << deg-i << ": ";
        cin >> coeff[i];
    }
}

dd getValueFor(dd x)
{
    dd res = coeff[0];
    for(int i=1; i<=deg; i++)
    {
        res = res*x + coeff[i];
    }
    return res;
}
dd getRootUsingSecant(dd x1, dd x2)
{
    dd x3, err, f1, f2;
    int iteration = 0;
    err = 100;
    while(err >= EPS)
    {
        f1 = getValueFor(x1);
        f2 = getValueFor(x2);
        x3 = (f2*x1 - f1*x2) / (f2 - f1);
        err = fabs((x3-x2)/x3);

        printf("Iteration %d:\t", ++iteration);
        cout << fixed << setprecision(3) << x1 << "\t";
        cout << fixed << setprecision(3) << x2 << "\t";
        cout << fixed << setprecision(3) << x3 << "\t";
        cout << fixed << setprecision(3) << f1 << "\t";
        cout << fixed << setprecision(3) << f2 << "\n";
        //cout << err << endl;

        x1 = x2;
        x2 = x3;
    }
    return x3;
}

int main()
{
    cout << "Enter highest degree: ";
    cin >> deg;
    getInput();
    dd x1, x2;
    cout << "Enter the values of x1: ";
    cin >> x1;
    cout << "Enter the values of x2: ";
    cin >> x2;
    prline;
    printf("\t\t x1 \t x2 \t x3 \t f1 \t f2 \n");
    prline;
    dd root = getRootUsingSecant(x1, x2);
    prline;
    cout << "Approximate value: " << root << endl;
    return 0;
}
