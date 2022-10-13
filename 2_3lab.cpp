#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

bool comp1(const wchar_t* a, const wchar_t* b)  //(const void* a, const void* b)
{
    return wcscmp(a, b) < 0;// if case sensitive wcscmp
}

int main() {
    system("chcp 866");
    std::wcout.imbue(std::locale::locale(".866"));
    std::wcin.imbue(std::locale::locale(".866"));
    std::wifstream input_file;
    std::wstring line;
    std::vector<std::wstring> lines;
    input_file.open(L"C:/data.txt");
    if (input_file.is_open())
    {
        while (getline(input_file, line))
        {
            std::wcout << L"Успешно открыли исходный файл!" << std::endl;
            std::wcout << L"Содержимое исходного файла :" << std::endl;

            std::wregex re(L"\\w+");
            std::wsregex_token_iterator
                begin(line.begin(), line.end(), re),
                end;
            std::copy(begin, end, std::back_inserter(lines));
            std::wcout << line << "\t";
        }
        input_file.close();
    }
    std::wofstream output_file;
    output_file.open(L"C:/result.txt");
    if (output_file.is_open())
    {
        std::wcout << std::endl << L"Успешно открыли результативный файл!";
        for (int i = 0; i < lines.size(); ++i)
            for (int j = 0; j < lines.size(); ++j)
                if (comp1(lines[i].c_str(), lines[j].c_str()))
                    std::swap(lines[i], lines[j]);
        std::wcout << std::endl << L"Содержимое результативного файла:" << std::endl;
        for (std::wstring line : lines)
        {
            output_file << line << " ";
            std::wcout << line << "\t";
        }
        output_file.close();
    }
    return 0;
}
