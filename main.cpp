#pragma execution_character_set("utf-8")

#include"InitialWordList.h"
#include"Random.h"
#include<Windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	InitialWordList initial_senior("dictionary//Senior_clean.txt", Senior, word_list_senior);
	InitialWordList initial_junoir("dictionary//Junior_clean.txt", Junior, word_list_junior);
	InitialWordList initial_primary("dictionary//Primary_clean.txt", Primary, word_list_primary);

	std::cout << "¸ß¿¼:\n" << std::endl;
	for (int i = 0; i < 10; i++) {
		random_word(word_list_senior.size()-1,word_list_senior).show();
	}
	std::cout << "ÖÐ¿¼:\n" << std::endl;
	for (int i = 0; i < 10; i++) {
		random_word(word_list_junior.size()-1,word_list_junior).show();
	}
	std::cout << "Ð¡º¢¶ù:\n" << std::endl;
	for (int i = 0; i < 10; i++) {
		random_word(word_list_primary.size()-1,word_list_primary).show();
	}

	return 0;
}