#include "Dictionary.hpp"
void printerRecursive(WordItem *ptr);
void destroyTree(WordItem *ptr)
{
	if (ptr == NULL)return;
	destroyTree(ptr->Left);
	destroyTree(ptr->right);
	delete ptr;
	return;
}


Dictionary::Dictionary()
{
	root = NULL;
	read();
}

Dictionary::~Dictionary()
{
	destroyTree(root);
	return;
}

WordItem *Dictionary::translate(std::string word)
{
	WordItem *Node = search(word);
	if (Node == NULL)
	{
		return NULL;
	}
	return Node;
}

int Dictionary::read()
{
	std::string Word;
	std::string Word2;
	std::string Word3;
	std::string englishTranslate;
	std::ifstream spanish("spanish.txt");
	std::ifstream english("English.txt");

	if (spanish.fail() || english.fail())
	{
		std::cout << "Files didn't open properly" << std::endl;
		return -1;
	}

	while (getline(spanish, Word))
	{
		getline(english, englishTranslate);

		addNode(Word, englishTranslate);
		//std::cout << spanishWord << std::endl;
	}
	spanish.close();
	english.close();

}

void Dictionary::addNode(std::string word, std::string translation)
{
	if (root == NULL)
	{
		WordItem *newNode = new WordItem;
		newNode->word = word;  newNode->englishTranslation = translation;
		newNode->Left = NULL; newNode->right = NULL;
		root = newNode;
		return;
	}
	else
	{
		addleafRecursivly(word, translation, root);
	}
	return;
}

void Dictionary::addleafRecursivly(std::string word, std::string translation, WordItem *ptr)
{
	if (word < ptr->word)
	{
		if (ptr->Left != NULL)
		{
			addleafRecursivly(word, translation, ptr->Left);
		}
		else
		{
			WordItem *newNode = new WordItem;
			newNode->word = word; newNode->englishTranslation = translation;
			newNode->Left = NULL; newNode->right = NULL;
			ptr->Left = newNode;
			return;
		}
	}
	if (word > ptr->word)
	{
		if (ptr->right != NULL)
		{
			addleafRecursivly(word, translation, ptr->right);
		}
		else
		{
			WordItem *newNode = new WordItem;
			newNode->word = word; newNode->englishTranslation = translation;
			newNode->Left = NULL; newNode->right = NULL;
			ptr->right = newNode;
			return;
		}
	}
	return;
}

WordItem *Dictionary::search(std::string word)
{
	WordItem *node = root;
	while (node != NULL)
	{
		if (word == node->word) return node;

		if (word < node->word)
		{
			node = node->Left;
		}
		else if (word > node->word)
		{
			node = node->right;
		}
	}
	return NULL;
}

WordItem *Dictionary::searchE(std::string is)
{
	std::ifstream english;
	std::ifstream spanish;
	std::string s, e;
	english.open("english.txt");
	spanish.open("spanish.txt");
	if (is == "area") {
		last = true;
	}
	else
		last = false;
	

	if (english.is_open() && spanish.is_open()) {
		while (getline(english, e)) {
			getline(spanish, s);
			if (is == e) 
				break;
				
			
		}
	}

	WordItem* w;
	
	
	w = search(s);
	return w;
	
	
}

void Dictionary::printer()
{
	printerRecursive(root);
}

void printerRecursive(WordItem *ptr)
{
	if (ptr == NULL) return;
	printerRecursive(ptr->Left);
	std::cout << ptr->word << std::endl;
	printerRecursive(ptr->right);
	return;
}

WordItem *Dictionary::randWord() {
	WordItem *r;
	std::ifstream i;
	std::string s;
	int n = 0;
	int stop = 0;

	 
	stop = std::rand() % 3000;

	i.open("spanish.txt");
	if (i.is_open()) {
		while (getline(i, s)) {
			if (n == stop)
				break;
			n++;
		}
	}

	r = search(s);

	return r;
}

bool Dictionary::isLast() {
	return last;
}