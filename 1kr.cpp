#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <chrono>
using std::cin, std::cout, std::endl, std::vector, std::size_t;
//Заполнение матрицы случайными целочисленными числами от 1 до 10
void fill(vector<vector<int>>& vec, const size_t& size) {
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(1, 10);
    for (auto &row: vec) {
        for (auto &item: row) {
            item = distribution(generator);
        }
    }
}
//Сортировка пузырьком матрицы
void bubblesort(vector<vector<int>>& x, size_t& size) {
    for (size_t i = 0U; i < size * size; ++i) 
        for (size_t j = i; j < size * size; ++j) 
            if (x[i / size][i % size] > x[j / size][j % size]) 
                std::swap(x[i / size][i % size], x[j / size][j % size]);
}
//Вывод матрицы в консоль
void print(const vector<vector<int>>& data) {
    for (const auto &row: data) {
        for (const auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
}
//Поиск медианы в матрице
void median(int& value, vector<vector<int>>& data, size_t& size) {
    bubblesort(data, size);
    cout << "Отсортированная матрица : " << endl;
    print(data);
    size_t n = data.size() / 2U + data.size() % 2U - 1U;
    value = data[n][n];
    cout << "Медиана = " << value << endl;
}

int main() {
    //1ое задание поиск суммы с заданной точностью
    double  n = 0.0, k = 1.0,
            x = 0.0, sumlast = 0.0, eps = 0.000001;
    cout << "Введите n:" << endl;
    cin >> n;
    cout << "Введите x:" << endl;
    cin >> x;
    cout << "Введите eps:" << endl;
    cin >> eps;
    double sum = -1.0 / tgamma(n + 1.0) * pow(x / 2.0, n + 2.0 * k), slag = 0.0;
    vector<double> vec{};
    vec.emplace_back(sum);
    while (abs(sum) - abs(sumlast) > eps) {
        sumlast = sum;
        slag = pow(-1.0, k) / (tgamma(k + 1.0) * tgamma(k + n + 1.0)) * pow(x / 2.0, n + 2.0 * k);
        sum += slag;
        vec.emplace_back(slag);
        ++k;
    }
    cout << "n =\t" << n << endl;
    cout << "x =\t" << x << endl;
    cout << "k =\t" << k << endl;
    cout << "eps =\t" << eps << endl;
    cout << "слагаемые=\t";
    for (const auto i : vec)
        cout << i << " ";
    cout << endl;
    cout << "sum =\t" << sum << endl;
    //2ое задание поиск медианы в матрице
    size_t m = 0U;
    cout << "Введите m:" << endl;
    cin >> m;
    vector<vector<int>> matrix {};
    size_t dim = 2U * m + 1U;
    matrix.resize(dim, vector<int>(dim));
    fill(matrix, dim);
    print(matrix);
    int med = 0;
    median(med, matrix, dim);
}
