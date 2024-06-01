#include "random.h"

Word random_word(const int word_amount,std::vector<Word> word_list)
{
	std::random_device rd;
	unsigned int seed = rd();
	std::default_random_engine e;
	e.seed(seed);
	std::uniform_int_distribution<unsigned> u(0, word_amount);
	Sleep(5);
	return word_list[u(e)];
}