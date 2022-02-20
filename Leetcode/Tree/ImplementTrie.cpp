#include "ImplementTrie.h"
#include <iostream>

Trie::Trie()
{

}

Trie::~Trie()
{
	if (tries.size() > 0)
	{
		// iterate and delete each trie through there pointer and remove from map
		for (auto trie = tries.begin(); trie != tries.end(); )
		{
			delete trie->second;
			trie = tries.erase(trie);
		}
		tries.clear();
	}
}

void Trie::insert(string word) {
	if (word.length() == 0) return;
	
	Trie* currentTrie = this;
	for (auto c : word)
	{
		if (currentTrie->tries[c] != nullptr)		// if already existe , go down one character
		{
			currentTrie = currentTrie->tries[c];
		}
		else
		{
			Trie* trie = new Trie();
			currentTrie->tries[c] = trie;
			currentTrie = trie;
		}
	}
	currentTrie->isWord = true;

	return;
}

bool Trie::search(string word) {
	if (word.length() == 0) return false;
	Trie* currentTrie = this;
	for (auto c : word)
	{
		if (currentTrie->tries[c] != nullptr)		// if already existe , go down one character
		{
			currentTrie = currentTrie->tries[c];
		}
		else
		{
			return false;
		}
	}
	return currentTrie->isWord;
}

bool Trie::startsWith(string prefix) {
	if (prefix.length() == 0) return false;
	Trie* currentTrie = this;
	for (auto c : prefix)
	{
		if (currentTrie->tries[c] != nullptr)		// if already existe , go down one character
		{
			currentTrie = currentTrie->tries[c];
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool Trie::TestSolution(vector<string> func, vector<string> inputs, vector<bool> sol)
{
	if (func.size() != inputs.size() || func.size() != sol.size() || inputs.size() != sol.size())
	{
		return false;
	}

	Trie* trie = new Trie();
	for (int i = 0; i < func.size(); ++i)
	{
		string fn = func[i];
		string in = inputs[i];
		bool sl = sol[i];
		bool rtn = false;

		if (fn.compare("Trie") == 0)
		{
			// do nothing, trie is already created
		}
		if (fn.compare("insert") == 0)
		{
			trie->insert(in);
		}
		if (fn.compare("search") == 0)
		{
			rtn = trie->search(in);
			if (rtn != sl)
			{
				delete trie;
				return false;
			}
		}
		if (fn.compare("startsWith") == 0)
		{
			rtn = trie->startsWith(in);
			if (rtn != sl)
			{
				delete trie;
				return false;
			}
		}
	}
	delete trie;
	return true;
}

bool Trie::TestSolution()
{
	return TestSolution({ "Trie", "insert", "search", "search", "startsWith", "insert", "search" }, { "" ,"apple","apple","app","app","app","app"}, { NULL, NULL, true, false, true, NULL, true });
}
