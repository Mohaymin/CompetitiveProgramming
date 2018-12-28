/// False Position Method
#include<bits/stdc++.h>
using namespace std;
#define nt printf("\t")
#define drawLine printf("___________________________________________________________________________________________________________________\n")
#define E 0.001

///function that returns the value of f(x) for a given value of x
double f(double x)
{
    return x*x - 4*x - 10;
}

///target function that returns root
double getRoot(double x1, double x2, int iteration)
{
    double x0;
    double f1, f2, f0;
    double error = fabs((x2-x1)/x2);

    x0 = x1 - (f(x1)*(x1-x2)/(f(x1)-f(x2)));
    f1 = f(x1);
    f2 = f(x2);
    f0 = f(x0);

    //cout<<iteration<<nt<<x1<<nt<<x2<<nt<<x0<<nt<<f1<<nt<<f2<<nt<<f0<<nt<<error<<endl;
    printf("\t%3d\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n", iteration, x1, x2, x0, f1, f2, f0, error);

    if(f0 == 0)
        return x0;
    if(f1*f0 < 0)
        x2 = x0;
    else
        x1 = x0;

    if(error < E)
        return (x1+x2)/2;
    return getRoot(x1, x2, iteration+1);
}

///the main function
int main()
{
    double x1, x2, root;
    do
    {
        cout << "Enter the value of x1: ";
        cin >> x1;
        cout << "Enter the value of x2: ";
        cin >> x2;
    } while(f(x1)*f(x2) > 0);
    ///receive input till we get a valid range

    drawLine;
    printf("Iteration\tx1\tx2\tx0\tf1\tf2\tf0\terror\n");
    drawLine;

    root = getRoot(x1, x2, 1);

    drawLine;
    cout << "Approximate root: " << root << endl;
    return 0;
}
