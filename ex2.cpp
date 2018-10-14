#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,A,B,k1,sum,temp;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter range A ";
    cin >> A;
    cout << "\tto B ";
    cin >> B;
    double* mas = new double[n];
    cout << "Enter array: " << endl;
    for (int i=0; i<n; i++)
    {
        cin >> mas[i];
    }
    k1=B-A;
    cout << "number: " << k1 << endl;
    int iMAX=mas[0];
    for (int i=1; i<n; i++)
    {
        if (mas[i]>iMAX)
        {
        iMAX=mas[i];
        sum=0;
        }
        else
        {
            sum+=mas[i];
        }
    }
    cout << "sum after the max element of array: " << sum << endl;
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if (abs(mas[j])<abs(mas[j+1]))
            {
                temp=mas[j];
                mas[j]=mas[j+1];
                mas[j+1]=temp;
            }
        }
    }
    cout << "array sorting descending the elements modules: ";
    for (int i=0; i<n; i++)
    {
        cout << mas[i] << " ";
    }
    delete [] mas;
    return 0;
}
