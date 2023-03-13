#pragma once

#include <string>
#include <iostream>
#define ALFABET 26

using std::string;

//zakladam ze sa tylko male litery, jak nie to powinno byc 52

class Trie_Node {

public:
	bool is_word;
	char c;
	Trie_Node* children[ALFABET];

	Trie_Node(char character): c(character){
		is_word = false;
		for (int i = 0; i < ALFABET; i++) {
			children[i] = nullptr;
		}
	}

	bool childrenExist(int index) {
		if (children[index]) return true;
		return false;
	}

	~Trie_Node() {
		for (int i = 0; i < ALFABET; i++) delete children[i];
	}

};

class Trie_Tree
{
	Trie_Node* root;

public:

	Trie_Tree() {
		
		root = new Trie_Node('\0'); // empty character
	}

	void insertWord(string str) {
		Trie_Node* curr = root;

		for (int i = 0; i < str.length(); i++) {
			char c = str[i];
			if (!curr->childrenExist(c - 'a')) curr->children[c - 'a'] = new Trie_Node(c);
			curr = curr->children[c - 'a'];
		}
		curr->is_word = true;
	}

	bool search(const string key) {

		Trie_Node* curr = root;

		for (int i = 0; i < key.length(); i++) {
			char c = key[i];
			if (!curr->childrenExist(c - 'a')) return false;
			curr = curr->children[c - 'a'];
		}

		if (!curr->is_word) this->suggest(curr, key, true);

		return curr->is_word;
	} 

	void suggest(Trie_Node* curr, string currPrefix, bool first = false) {
		if (curr == nullptr) return;

		if(!first)
			currPrefix += curr->c;

		if (curr->is_word)
			std::cout << currPrefix << std::endl;


		for (const auto child : curr->children) {
			if (child != nullptr) {
				suggest(child, currPrefix);
			}
		}
	}

	~Trie_Tree() {
		delete root;
	}
};

