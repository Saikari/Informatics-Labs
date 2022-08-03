#include <iostream>
#include <vector>
#include <random>
#include <chrono>
template <typename T>
void print_matrix(const std::vector<std::vector<T>>& vec) {
    for (const auto &row: vec) {
        for (const auto &item: row)
            std::cout << item << "\t";
        std::cout << std::endl;
    }
}

void create_fill_matrix(std::vector<std::vector<int>>& vec, const size_t& size) {
    vec.resize(size);
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(1, 6);
    for (auto & row : vec) {
        row.resize(size);
        for (auto &item: row) {
            item = distribution(generator);
        }
    }
}
template <typename T>
void transpose(std::vector<std::vector<T>>& vec) {
    std::vector<std::vector<T>> vec2 = {};
    vec2.resize(vec[0].size());
    for (auto i = 0; i < vec2.size(); ++i)
        vec2[i].resize(vec.size());
    for (auto i = 0; i < vec[0].size(); ++i)
    {
        for (auto j = 0; j < vec.size(); ++j)
            vec2[i][j] = vec[j][i];
    }
    vec = vec2;
}

int main()
{
    const size_t N = 4;
    std::vector<std::vector<int>> matrix{};
    create_fill_matrix(matrix, N);
    std::cout << "Исходная матрица" << std::endl;
    print_matrix(matrix);
    transpose(matrix);
    std::cout << "Полученная матрица" << std::endl;
    print_matrix(matrix);
    return 0;
}
