#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double xBeg, xEnd, a, b, c, F, step;
    cout << "Enter xBeg: ";
    cin >> xBeg;
    cout << "Enter xEnd: ";
    cin >> xEnd;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << "Enter step: ";
    cin >> step;
    cout << "x" << "\t" << "F" << "\n";
    for (double x=xBeg; x!=xEnd; x+=step)
    {
        if (x-1<0 and b-x!=0)
            F=a*pow(x,2)+b;
        else if (x-1>0 and b+x==0)
            F=(x-a)/a;
        else
            F=x/c;
        cout << x << "\t" << F << "\n";
    }
    return 0;
}
