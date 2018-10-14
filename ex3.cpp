#include <iostream>
#define print_matrix \
{\
    for(int i = 0; i < N; ++i){\
        for(int j = 0; j < M; ++j)\
            std::cout << m[i][j] << ' ';\
        std::cout << std::endl;\
    }\
    std::cout << std::endl;\
}

int main()
{
    const int N=4;
    const int M=5;
    int m[N][M]=
    {
        { 1, 1, 1, 1, 0 },
        { 2, 2, 2, 2, 0 },
        { 3, 3, 3, 3, 0 },
        { 1, 2, 3, 4, 0 }
    };
    print_matrix;
    int n;
    std::cout << "Enter step-shifting: ";
    std::cin >> n;
    //shift right
    int* p, t;
    for(p = &m[0][0]; p != &m[N - 1][M]; p += M){
        for(int i = 0; i < n; ++i){
            t = *(p + (M - 1));
            for(int* r = p + (M - 1); r > p; --r)
                *r = *(r - 1);
            *p = t;
        }
    }
    print_matrix;
    //shift down
    int* e = &m[N - 1][0];
    for(p = &m[0][0]; p != &m[0][M]; ++p, ++e){
        for(int i = 0; i < n; ++i){
            t = *e;
            for(int* r = e; r > p; r -= M)
                *r = *(r - M);
            *p = t;
        }
    }
    print_matrix;
    return 0;
}
