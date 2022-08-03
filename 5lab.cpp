#include <iostream>
#include <vector>
#include <random>
#include <chrono>
void create_fill(std::vector<std::vector<int>>& vec, const unsigned& size) {
    vec.resize(size, std::vector<int>(size));
    for (auto row = 0; row < size; ++row)
        for (auto col = 0; col < size; ++col) {
            std::cout << "Введите элемент квадратной матрицы [" << row << "][" << col << "]\t";
            std::cin >> vec[row][col];
            std::cout << std::endl;
        }
}
void print_vector(const std::vector<int>& vec) {
    for (const auto &item: vec)
        std::cout << item << " ";
    std::cout << std::endl;
}
void print_matrix(const std::vector<std::vector<int>>& vec) {
    for (const auto &row: vec) {
        for (const auto &item: row)
            std::cout << item << "\t";
        std::cout << std::endl;
    }
}
void fix_matrix(std::vector<std::vector<int>>& vec, const unsigned& size) {
    for (auto row = 0; row < size; ++row)
        for (auto col = 0; col < size; ++col)
            if (!(row == col || row == size - col - 1))
                vec[row][col] = 0;
}
void create_fill_vec(std::vector<int>& vec, const unsigned& size) {
    vec.resize(size * size);
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(1, 6);
    for (auto row = 0; row < size * size; ++row)
        vec[row] = distribution(generator);
}
void direction_matrix(std::vector<int>& vec, const int& size, std::vector<std::vector<int>>& res) {
    res.resize(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((i + j) < size) {
                res[i][j] = vec[(int)(0.5 * (i + j + 1) * (i + j + 2) + ((i + j) % 2 == 0 ? -i : -j) )- 1];
            } else {
                int p = size - i - 1, q = size - j - 1;
                res[i][j] = vec[(int)(size * size + 1 - (0.5 * (p + q + 1) * (p + q + 2) + ((p + q) % 2 == 0 ? -p : -q))) - 1];
            }
        }
    }
}
int main()
{
    const unsigned N = 4;
    std::vector<std::vector<int>> matrix{};
    create_fill(matrix, N);
    std::cout << "Исходная матрица" << std::endl;
    print_matrix(matrix);
    fix_matrix(matrix, N);
    std::cout << "Главная и побочная диагональ остались без изменения, остальные равны 0" << std::endl;
    print_matrix(matrix);
    const int N2 = 8;
    std::vector<int> vector{};
    create_fill_vec(vector, N2);
    std::cout << "Исходный вектор" << std::endl;
    print_vector(vector);
    std::vector<std::vector<int>> matrix2{};
    direction_matrix(vector, N2, matrix2);
    std::cout << "Полученная матрица" << std::endl;
    print_matrix(matrix2);
    return 0;
}
