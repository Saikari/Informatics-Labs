#include <iostream>
#include <cmath>

struct coord
{
    double X, Y;
    coord()
    {
        X = Y = 0.0;
        std::cout << "Введите Х" << std::endl;
        std::cin >> X;
        std::cout << "Введите Y" << std::endl;
        std::cin >> Y;

    }
    void print() const
    {
        std::cout << "X = " << X << "\tY = " << Y << std::endl;
    }
};
int main()
{
//Решение 5ой задачи
    std::cout << "Решение задачи №5" << std::endl << "Введите координаты точки A" << std::endl;
    coord A;
    A.print();
    std::cout << "Введите координаты точки B" << std::endl;
    coord B;
    B.print();
    std::cout << "Введите координаты точки C" << std::endl;
    coord C;
    C.print();
    double mA = sqrt(((C.Y+B.Y)/2.0 - A.Y) * ((C.Y+B.Y)/2.0 - A.Y) + ((C.X+B.X)/2.0 - A.X)*((C.X+B.X)/2.0 - A.X));
    double mB = sqrt(((C.Y+A.Y)/2.0 - B.Y)*((C.Y+A.Y)/2.0 - B.Y) + ((C.X+A.X)/2.0 - B.X)*((C.X+A.X)/2.0 - B.X));
    double mC = sqrt(((B.Y+A.Y)/2.0 - C.Y)*((B.Y+A.Y)/2.0 - C.Y) + ((B.X+A.X)/2.0 - C.X)*((B.X+A.X)/2.0 - C.X));
    std::cout << "Медиана A = " << mA << "\tМедиана B = " << mB << "\tМедиана C = " << mC << std::endl;
    //Решение 25ой задачи
    double X, Y;
    std::cout << "Решение задачи №25" << std::endl << "Введите Х" << std::endl;
    std::cin >> X;
    Y = log(X) * log(X) + (X * X * X) / 3.0;
    std::cout << "Y = " << Y;
    return 0;
}
