#include <iostream>
#define print_matrix \
{\
    for(int i=0; i<N; ++i){\
        for(int j=0; j<M; ++j)\
            cout << mat[i][j] << ' ';\
        cout << endl;\
    }\
    cout << endl;\
}
using namespace std;

void shiftRight(int n, int N, int M, int m[4][5]);


int main()
{
    const int N=4;
    const int M=5;
    int mat[N][M]=
    {
        { 1, 1, 1, 1, 0 },
        { 2, 2, 2, 2, 0 },
        { 3, 3, 3, 3, 0 },
        { 1, 2, 3, 4, 0 }
    };
    
    print_matrix;
    int n;
    cout << "Enter step-shifting: ";
    cin >> n;
    shiftRight(n,N,M,mat);
    //shift right
    
    print_matrix;
    //shift down
   int*z, x;
    int* e=&mat[N-1][0];
    for(z=&mat[0][0]; z!=&mat[0][M]; ++z, ++e){
        for(int i=0; i<n; ++i)
        {
            x=*e;
            for(int* r=e; r>z; r-=M)
                *r=*(r-M);
            *z=x;
        }
     }    
    print_matrix;
    
    return 0;
}

void shiftRight(int n, int N, int M, int m[4][5])
{
    int*p, t;
    for(p=&m[0][0]; p!=&m[N-1][M]; p+=M)
    {
        for(int i=0; i<n; ++i)
        {
            t = *(p+(M-1));
            for(int* r=p+(M-1); r>p; --r)
                *r=*(r-1);
            *p=t;
        }
    }
}







