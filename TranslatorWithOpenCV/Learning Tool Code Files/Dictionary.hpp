#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP






#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include<ctime>


struct WordItem
{
	std::string word;
	std::string englishTranslation;

	WordItem* right;
	WordItem* Left;
};


class Dictionary
{
private:
	WordItem* root;
	bool last = false;
public:
	Dictionary();
	~Dictionary();

	
	bool isLast();
	int read();
	WordItem *translate(std::string word);

	WordItem *randWord();

	void addNode(std::string Word, std::string EndlighTranslation);
	void addleafRecursivly(std::string spanishWord, std::string EndlighTranslation, WordItem *ptr);

	WordItem *search(std::string word);
	WordItem *searchE(std::string e);
	void printer();
}; 

#endif // !DICTIONAT_HPP