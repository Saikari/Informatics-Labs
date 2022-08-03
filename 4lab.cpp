#include <iostream>
#include <vector>
void resize(std::vector<int>* vec)
{
    int size = 0;
    std::cout << "Введите размер вектора" << std::endl;
    std::cin >> size;
    vec->resize(size);
}
void input(std::vector<int>* vec)
{
    std::cout << "Введите элемент вектора" << std::endl;
    for (int &item: *vec)
        std::cin >> item;
}
void print(const std::vector<int>& vec)
{
    std::cout << "Вывод вектора" << std::endl;
    for (const int item: vec)
        std::cout << item << "\t";
    std::cout << std::endl;
}
void change(std::vector<int>* vec)
{
    //Инициализация индекса минимального элемента вектора
    int min = vec->at(0);
    int counter_negative = 0;
    int index = -1;
    int IndexMin = 0;
    //Поиск индекса минимального элемента вектора
    for (int &item: *vec)
    {
        ++index;
        if (item < min)
        {
            min = item;
            IndexMin = index;
        }
    }
    for (size_t ind = IndexMin + 1; ind<vec->size(); ++ind)
    {
        if (counter_negative != 3 && vec->at(ind) < 0)
        {
            counter_negative += 1;
            if (counter_negative == 3)
                vec->at(IndexMin) = vec->at(ind);
        }
    }
    if (counter_negative != 3)
        std::cout << "Нет третьего отрицательного элемента стоящего после минимального элемента" << std::endl;
}
void change2(std::vector<int>* vec)
{
    int index = -1;
    int zeroindex = 0;
    int swapindex = 0;
    //Поиск индекса нулевого элемента
    for (int &item: *vec)
    {
        ++index;
        if (item == 0)
            zeroindex = index;
    }
    //Если нет нулевого элемента в векторе вывести ошибку
    if (vec->at(zeroindex) != 0)
    {
        std::cout << "Нет нулевого элемента в векторе." << std::endl;
    }
        //Иначе найти ближайший элемент вектора к индексу нулевого элемента
    else
    {
        index = -1;
        int difference = abs(vec->at(0) - zeroindex);
        for (int &item: *vec)
        {
            ++index;
            if (difference > abs(item - zeroindex))
            {
                swapindex = index;
                difference = abs(item - zeroindex);
            }
        }
        vec->at(zeroindex) = vec->at(swapindex);
    }
}
int main()
{
    //Решение 1го задания
    std::vector<int> vec{};
    //Установка размера
    resize(&vec);
    if (vec.size() > 1)
    {
        //Ввод
        input(&vec);
        //Вывод
        print(vec);
        change(&vec);
        //Вывод
        print(vec);
    }
    //Решение 2го задания
    resize(&vec);
    if (vec.size() > 1)
    {
        //Ввод
        input(&vec);
        //Вывод
        print(vec);
        change2(&vec);
        //Вывод
        print(vec);
    }
    return 0;
}
