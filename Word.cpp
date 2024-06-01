#include "Word.h"

Word::Word(std::string _eng, std::vector<std::string> _chs, std::string _pho_symbol)
{
	eng = _eng;
	chs = _chs;
	pho_symbol = _pho_symbol;
}

void Word::show()
{
	std::cout << eng << "\t" << pho_symbol << "\t";
	for (auto element : chs) {
		std::cout << element << "  ";
	}
	std::cout << std::endl;
}

void Word::setDifficulty(int _difficulty) {
	if (_difficulty > difficulty)
		difficulty = _difficulty;
}

bool hasThisChs(std::string _chs, std::vector<std::string> vec)
{
	auto it = std::find_if(vec.begin(), vec.end(), [&](std::string chs) {
		return chs == _chs;
		});
	if (it == vec.end())
		return false;
	else
		return true;
}
std::vector<Word>::iterator checkInSenior(std::string _eng, bool& isFound) {
	std::vector<Word>::iterator it = std::find_if(word_list_senior.begin(), word_list_senior.end(), [&](Word eng) {
		return _eng == eng.eng;
		});
	if (it == word_list_senior.end())
	{
		isFound = false;
		return it;
	}
	else
	{
		std::cout << "FOUND!!!" << it->eng << std::endl;
		isFound = true;
		return it;
	}
}