#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>


std::vector<std::wstring> resplit(const std::wstring& s, const std::wregex& sep_regex = std::wregex{ L"\\s+" }) {
	std::wsregex_token_iterator iter(s.begin(), s.end(), sep_regex, -1);
	std::wsregex_token_iterator end;
	return { iter, end };
}

int main() {
	system("chcp 866");
	std::wcout.imbue(std::locale::locale(".866"));
	std::wcin.imbue(std::locale::locale(".866"));
	const std::vector<wchar_t> shipyashie {L'ж', L'ч', L'ш', L'щ'};
	const std::map<std::wstring, std::wstring> excep
	{
		{L"реб енок",L"дети" },
		{L"бес енок", L"бесенята"},
		{L"оп енок",L"опята"},
		{L"зв онок",L"звонки"},
		{L"позв онок",L"позвонки"},
		{L"под онок",L"подонки"},
		{L"кол онок",L"колонки"},
		{L"жавор онок",L"подонок"},
		{L"боч онок",L"бочонки"}
	};
	std::wstring s;
	std::wcout << L"Введите существительное " << std::endl;
	getline(std::wcin, s);
	std::wcout << L"Исходное слово в единственном числе " << s << std::endl;
	if (excep.find(s) == excep.end())
	{
		auto words = resplit(s);
		std::wstring ss = std::find(shipyashie.cbegin(), 
			shipyashie.cend(), 
			words[0][words[0].size() - 1]) != shipyashie.cend() ?
			L"ата" : L"ята";
		std::wcout << L"Полученное слово во множественном числе " << words[0] << ss;
	}
	else
	{
		std::wcout << std::endl << L"Исключение " << excep.at(s);
	}
	return 0;
}
