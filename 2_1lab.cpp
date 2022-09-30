#include <iostream>
#include <vector>
#include <random>
#include <chrono>
void fillvec(std::vector<int>& vec, const unsigned size)
{
  std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count()); // Инициализация генератора случайных чисел
    std::uniform_int_distribution<int> distribution(-10, 10); // Инициализация распределителя генерации чисел от -10 до 10
    for (size_t i =0; i < size; ++i)
      vec.push_back(distribution(generator)); // Заполнение вектора случайными числами от -10 до 10
}
void printvec(const std::vector<int>& vec)
{
  for (int i : vec)  // Итерация по элементам вектора 
    std::cout << i << "\t"; // Вывод вектора и символа табуляции
  std::cout << std::endl; // Вывод символа конца строки после вывода вектора
}
void get_elems(const std::vector<int>& vec,  std::vector<int>& res)
{
  bool isodd = false; // Проверочная переменная стоит ли чётное число после нечётного
  for (size_t i = 0; i < vec.size(); ++i)
    if (vec[i] % 1 == 0 && vec[i + 1] % 2 == 0) 
      isodd = true; // Если стоит чётное число после нечётного
  if (isodd)
  {
    for (unsigned i = vec.size(); i-- > 0; ) // Итерация от последнего до 1го элемента вектора
        if (vec[i] > 0) // Заполнение вектора положительные элементами
          res.push_back(vec[i]);
  }
Else // Иначи если не стоит чётное число после нечётного
  {
    for (unsigned i = vec.size(); i-- > 0; )
        if (vec[i] < 0) // Заполнение вектора отрицательными элементами
          res.push_back(vec[i]);
  }
}
int main() {
  std::vector<int> vec = {}, res = {}; // Инициализация исходного и результативного вектора
  unsigned size = 3; // Инициализация размерности исходного вектора
  fillvec(vec, size); // Заполнение вектора случайными числами от -10 до 10
  printvec(vec); // Вывод исходного вектора
  get_elems(vec, res); // Заполнение результативного вектора
  printvec(res);  // Вывод результативного вектора
}
