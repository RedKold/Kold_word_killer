#pragma once
#include<fstream>
#include<iostream>
#include"Word.h"
#include<sstream>

class InitialWordList
{
public:
	std::string file_path;
	int difficulty = -1;
	InitialWordList(std::string file_path, int _difficulty, std::vector<Word>& word_list);
};
