#include "InitialWordList.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
std::vector<Word> word_list_senior;
std::vector<Word> word_list_junior;
std::vector<Word> word_list_primary;
InitialWordList::InitialWordList(std::string file_path, int _difficulty, std::vector<Word>& word_list) {
	if (_difficulty > Primary)
	{
		std::fstream file(file_path, std::ios::in);
		if (file.is_open()) std::cout << file_path << " open successfully!" << std::endl;
		else std::cout << file_path << " opened error" << std::endl;

		std::string line;

		// example: 2. abandon [??b?nd?n]  v.抛弃，舍弃，放弃
		// 49. act [ækt] n. 法令，条例 v. （戏）表演，扮演（角色），演出（戏）；行动，做事
		while (std::getline(file, line)) {
			if (line.length() <= 1) // 换字母了
				continue;

			std::stringstream ss_line(line);
			std::vector<std::string> chs_list;
			std::string num;
			std::string word_eng;
			std::string phonetic_symbol;//音标
			std::string word_type;
			std::string word_chs;

			ss_line >> num >> word_eng >> phonetic_symbol;

			while (!ss_line.eof()) {
				std::stringstream chs_line; // 每次处理前重新创建
				ss_line >> word_type;
				ss_line >> word_chs;

				chs_line << word_type << " " << word_chs;
				if (hasThisChs(chs_line.str(), chs_list)) continue;
				chs_list.push_back(chs_line.str());
				word_chs = "";
			}

			Word tmp(word_eng, chs_list, phonetic_symbol);
			word_list.push_back(tmp);
		}
	}
	else //受限于文件格式，导入小学的另写一个处理。
	{
		std::fstream file(file_path, std::ios::in);
		if (file.is_open()) std::cout << file_path << " open successfully!" << std::endl;
		else std::cout << file_path << " opened error" << std::endl;

		std::string line;
		while (std::getline(file, line)) {
			std::stringstream ss_line(line);
			std::string eng;
			ss_line >> eng;
			bool isFound;
			std::vector<Word>::iterator it= checkInSenior(eng, isFound);
			if (isFound) {
				word_list.push_back(*it);
			}
		}
	}
}