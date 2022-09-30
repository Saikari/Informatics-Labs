#include <iostream>
#include <string>
#include <chrono>
#include <random>
void fillstring(const size_t* size, std::string* s)
{
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(40, 45);
	for (size_t index = 0; index < *size; ++index)
		*s += (char)distribution(generator);
}
void fillstring(const size_t* size, char* s)
{
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(40, 45);
	for (size_t index = 0; index < *size; ++index)
		s[index] = (char)distribution(generator);
	s[*size] = '\0';
}
bool checkstring(const size_t* size, const std::string* s)
{
	for (size_t index = 0; index < *size - 1; ++index)
		if ((*s)[index] == ',' && (*s)[index + 1] == '-')
			return true;
	return false;
}
bool checkstring(const size_t* size, const char* s)
{
	for (size_t index = 0; index < *size - 1; ++index)
		if (s[index] == ',' && s[index + 1] == '-')
			return true;
	return false;
}
int main() {
	size_t n, a, b, buf1, buf2;
	std::cout << "Введите размерность строки" << std::endl;
	std::cin >> n;
	std::string s;
	char s2[n + 1];
	fillstring(&n, &s);
	fillstring(&n, s2);
	std::cout << s2 << std::endl <<
		(checkstring(&n, &s) ?
			"В строке присутствует Si \",\" и Si+1 \"-\"." :
			"В строке не присутствует Si \",\" и Si+1 \"-\".") << std::endl;
	std::cout << s << std::endl <<
		(checkstring(&n, &s) ?
			"В строке присутствует Si \",\" и Si+1 \"-\"." :
			"В строке не присутствует Si \",\" и Si+1 \"-\".") << std::endl;
	std::vector<std::wstring> pole =
	{ L"00000000", L"00000000", L"00000000", L"00000000",
	  L"00000000", L"00000000", L"00000000", L"00000000" };
	std::cout << "Введите номер вертикали ферзя от 1 до 8" << std::endl;
	std::cin >> a;
	std::cout << "Введите номер горизонтали ферзя от 1 до 8" << std::endl;
	std::cin >> b;
	buf1 = a - 1, buf2 = b - 1;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (i == buf1)
				pole[i][j] = '*';
			if (j == buf2)
				pole[i][j] = '*';
		}
	}
	pole[buf1][buf2] = L'F';
	while (buf1 < 7 && buf2 < 7)
		pole[++buf1][++buf2] = '*'; // \ диагональ право-нижняя
	buf1 = a - 1, buf2 = b - 1;
	while (buf1 > 0 && buf2 > 0)
		pole[--buf1][--buf2] = '*'; // \ диагональ лево-верхняя
	buf1 = a - 1, buf2 = b - 1;
	while (buf1 > 0 && buf2 < 7)
		pole[--buf1][++buf2] = '*'; // \ диагональ лево-нижняя
	buf1 = a - 1, buf2 = b - 1;
	while (buf1 < 7 && buf2 > 0)
		pole[++buf1][--buf2] = '*'; // \ диагональ право-верхняя
	for (const auto& row : pole)
	{
		std::wcout << row << std::endl;
	}
	std::vector<std::wstring> pole2 =
	{ L"00000000", L"00000000", L"00000000", L"00000000",
	  L"00000000", L"00000000", L"00000000", L"00000000" };
	std::cout << "Введите номер вертикали коня от 1 до 8" << std::endl;
	std::cin >> a;
	std::cout << "Введите номер горизонтали коня от 1 до 8" << std::endl;
	std::cin >> b;
	buf1 = a - 1, buf2 = b - 1;
	int horse_ways[8][2] = { {-2,1},{-1,2},{1, 2},{2, 1},{2,-1},{1,-2},{-1,-2}, {-2,-1} };
	int hy = buf2, hx = buf1; // позиция коня
	for (int i = 0, wy, wx; i < 8; ++i) {
		wy = hy + horse_ways[i][0];
		wx = hx + horse_ways[i][1];
		if (wy >= 0 && wy < 8 && wx >= 0 && wx < 8) // проверим не вышли ли за границы поля
			pole2[wy][wx] = '*';
	}
	pole2[buf1][buf2] = L'K';
	for (const auto& row : pole2)
	{
		std::wcout << row << std::endl;
	}
	return 0;
}
