#include <iostream>
#define print_matrix \
{\
    for(int i=0; i<N; ++i){\
        for(int j=0; j<M; ++j)\
            cout << m[i][j] << ' ';\
        cout << endl;\
    }\
    cout << endl;\
}
using namespace std;

int main()
{
    int M,N;
    cout << "Введите размер матрицы \n";
    cout << "строк - ";
    cin >> N ;
    cout << "столбцов - ";
    cin >> M;
    int **m = new int*[N];
    for (int i=0; i<N; i++)
      {
          m[i]= new int[M];
      }
    
    cout << "Заполните матрицу \n" ;
    for (int i=0; i<N; i++)
      {
      	for (int j=0; j<M; j++) 
      	  {
      	  	cout << " matr[" << i << ";" << j << "] = ";
      	  	cin >> m[i][j];
      	  }  
      }
      
    print_matrix;
    int n;
    cout << "Enter step-shifting: ";
    cin >> n;
    //shift right
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
    print_matrix;
    //shift down
    int* e=&m[N-1][0];
    for(p=&m[0][0]; p!=&m[0][M]; ++p, ++e){
        for(int i=0; i<n; ++i)
        {
            t=*e;
            for(int* r=e; r>p; r-=M)
                *r=*(r-M);
            *p=t;
        }
    }
    print_matrix;
    return 0;
}