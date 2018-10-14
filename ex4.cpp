#include <complex>
#include <functional>
#include <iostream>
#include <set>
using namespace std;
typedef double                 T_coord;
typedef complex<T_coord>  T_point;
struct T_less_for_points : public binary_function<T_point, T_point, bool>
{
    bool operator() (T_point A, T_point B)
    {
        return A.real() == B.real() ? A.imag() < B.imag() : A.real() < B.real();
    }
};
typedef set<T_point, T_less_for_points>  T_points;
T_point  vect(T_point  A, T_point  B)
{
    return B - A;
}
struct T_circle
{
    T_point  center_;
    T_coord  radius_;
    T_circle
        (
            T_point  center = 0,
            T_coord  radius = 0
        ) : center_(center), radius_(radius)
    {}
    bool  intersects_line(T_point  A, T_point  B) const
    {
        T_point  AB = vect(A, B);
        T_point  AC = vect(A, center_);
        //Окружность пересекает прямую AB, если в треугольнике ABC, где C - центр окружности,
        //длина h высоты , опущенной на сторону AB, не больше радиуса данной окружности.
        //h найдем, разделив удвоенную площадь треугольника ABC на длину отрезка AB.
        //Удвоенную площадь треугольника ABC найдем как модуль определителя векторов AB и AC.
        //Итак, пересекает, если h <= R, т.е.
        //2 * S / abs(AB) <= R
        return  abs(AB.real() * AC.imag() - AB.imag() * AC.real()) / abs(AB) <= radius_;
    }
};
struct T_less_for_circles : public binary_function<T_circle, T_circle, bool>
{
    bool operator() (T_circle A, T_circle B)
    {
        return A.center_ == B.center_
                   ? A.radius_ < B.radius_
                   : T_less_for_points().operator () (A.center_, B.center_);
    }
};
typedef set<T_circle, T_less_for_circles>  T_circles;
T_circles  input_circles()
{
    cout << endl;
    int  n;
    do
    {
        cout << "Введите количество окружностей >= 1: ";
        cin >> n;
    }while(n < 1);
    cout << "Введите координаты центра и радиусы "
              << n
              << " окружностей:"
              << endl;
    T_circles  circles;
    do
    {
        cout << endl
                  << endl
                  << "X"
                  << circles.size() + 1
                  << " = ";
        T_coord x = 0;
        cin >> x;
        cout << "Y"
                  << circles.size() + 1
                  << " = ";
        T_coord y = 0;
        cin >> y;
        cout << endl
                  << "R"
                  << circles.size() + 1
                  << " = ";
        T_coord r = 0;
        cin >> r;
        circles.insert(T_circle(T_point(x, y), r));
    }while(circles.size() < n);
    return  circles;
}
T_points  input_points()
{
    cout << endl;
    int  n;
    do
    {
        cout << "Введите количество точек >= 2: ";
        cin >> n;
    }
    while(n < 2);

    cout << "Введите координаты "
              << n
              << " точек:"
              << endl;
    T_points  points;
    do
    {
        cout << endl
                  << endl
                  << "X"
                  << points.size() + 1
                  << " = ";
        T_coord x = 0;
        cin >> x;
        cout << "Y"
                  << points.size() + 1
                  << " = ";
        T_coord y = 0;
        cin >> y;
        points.insert(T_point(x, y));
    }while(points.size() < n);
    return  points;
}
void  get_line_intersected_max_circles
    (
        const T_circles&  circles,
        const T_points&   points,
        T_point&          A,
        T_point&          B,
        int&              circles_count_max
    )
{
    circles_count_max = 0;
    //Перебираем все пары множества точек.
    for(T_points::const_iterator  point_it_A = points.begin(); point_it_A != points.end();
        ++ point_it_A)
    {
        for(T_points::const_iterator  point_it_B = point_it_A; point_it_B != points.end();
            ++ point_it_B)
        {
            if(point_it_B == point_it_A)
            {
                continue;
            }
            int circles_count_cur = 0;
            //Перебираем все окружности, и подсчитываем сколько из них пересекает
            //прямая, проходящая через точки *point_it_A и *point_it_B.
            for(T_circles::const_iterator  circle_it = circles.begin();
                circle_it != circles.end(); ++circle_it)
            {
                if(circle_it->intersects_line(*point_it_A, *point_it_B))
                {
                    ++circles_count_cur;
                }
            }
            if(circles_count_max == 0
               || circles_count_cur > circles_count_max)
            {
                circles_count_max = circles_count_cur;
                A = *point_it_A;
                B = *point_it_B;
            }
        }
    }
}
int main()
{
    locale::global(locale(""));
    T_circles  circles  = input_circles  ();
    T_points   points   = input_points   ();
    T_point  A;
    T_point  B;
    int circles_count_max = 0;
    get_line_intersected_max_circles(circles, points, A, B, circles_count_max);
    cout << "Прямая, проведенная через точки "
              << A
              << " и "
              << B
              << endl
              << " пересекает максимально возможное количество окружностей: "
              << circles_count_max
              << endl;
    return 0;
}
