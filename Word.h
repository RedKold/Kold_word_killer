#pragma once
#include<string>
#include<vector>
#include<iostream>
const int Senior = 3;
const int Junior = 2;
const int Primary = 1;
class Word
{
public:
	Word(std::string eng, std::vector<std::string> chs, std::string _pho_symbol);
	void show();
	void setDifficulty(int _difficulty);
	friend std::vector<Word>::iterator checkInSenior(std::string _eng, bool& isFound);
protected:
	std::string eng;
	std::vector<std::string> chs;
	std::string pho_symbol;//“Ù±Í
	int difficulty = -1;
};
extern std::vector<Word> word_list_senior;
extern std::vector<Word> word_list_junior;
extern std::vector<Word> word_list_primary;
bool hasThisChs(std::string, std::vector<std::string>);
std::vector<Word>::iterator checkInSenior(std::string _eng, bool& isFound);
