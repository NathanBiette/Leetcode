#include "ImplementTrie.h"
#include <iostream>

Trie::Trie() {

}

Trie::~Trie()
{
	for (auto trie : tries)
	{
		delete trie.second;
		tries.erase(trie.first);
	}
}

void Trie::insert(string word) {
	if (word.length() == 0) return;
	if (word.length() == 1)
	{
		//c = word.front();
		isWord = true;
		return;
	}
	else
	{
		if (tries[word.front()] != nullptr)
		{
			tries[word.front()]->insert(word.substr(1, word.length() - 1));
		}
		else
		{
			Trie* trie = new Trie();
			tries[word.front()] = trie;
			tries[word.front()]->insert(word.substr(1, word.length() - 1));
		}
	}
	return;
}

bool Trie::search(string word) {
	if (word.length() == 0) return false;
	if (word.length() == 1)
	{
		return isWord;
	}
	else
	{
		return tries[word.front()] != nullptr ? tries[word.front()]->search(word.substr(1, word.length() - 1)) : false;
	}
}

bool Trie::startsWith(string prefix) {
	if (prefix.length() == 0) return false;
	if (prefix.length() == 1)
	{
		return true;
	}
	else
	{
		return tries[prefix.front()] != nullptr ? tries[prefix.front()]->startsWith(prefix.substr(1, prefix.length() - 1)) : false;
	}
}
