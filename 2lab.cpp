#include <iostream>
struct coord
{
    double X, Y;
    coord(double X, double Y)
    {
        this->X = X;
        this->Y = Y;
    }
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
    [[nodiscard]] bool belongs(double from, double upto) const
    {
        return X * X + Y * Y <= upto && X * X + Y * Y >= from;
    }
};

int main()
{
    std::cout << "Решение задачи №5" << std::endl << "Введите координаты точки B" << std::endl;
    //Ввод точек координат трапеции
    coord B;
    B.print();
    std::cout << "Введите координаты точки C" << std::endl;
    coord C;
    C.print();
    std::cout << "Введите координаты точки D" << std::endl;
    coord D;
    D.print();
    std::cout << "Введите координаты точки E" << std::endl;
    coord E;
    E.print();
    //Поиск пересечения боковых сторон
    coord k_((B.Y - C.Y) / (B.X - C.X),
             (D.Y - E.Y) / (D.X - E.X));
    coord b_(B.Y - k_.X * B.X,
             D.Y - k_.Y * D.X);
    coord X((b_.Y - b_.X) /
            (k_.X - k_.Y),
            (b_.X * k_.Y - b_.Y * k_.X) / (k_.Y - k_.X));
    std::cout << "Точка пересечения боковых сторон X" << std::endl;
    X.print();
    std::cout << "Решение задачи №59(б) \t Введите координаты точки для проверки принадлежности заштрихованной части плоскости" << std::endl;
    coord Point;
    Point.print();
    //Проверка принадлежности точки заданным координатам и вывод результата
    if (Point.belongs(0.5, 1.0))
        std::cout << "Принадлежит заштрихованной части плоскости." << std::endl;
    else
        std::cout << "Не принадлежит заштрихованной части плоскости." << std::endl;
    return 0;
}
