#pragma once
#include <iostream>
#include <string>
using namespace std;

// Trie Node Definition
class TrieNode {
public:
    TrieNode* children[26]; // Assuming only lowercase letters
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
// Trie Class Definition
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string key) {
        TrieNode* node = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }
    bool search(string key) {
        TrieNode* node = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEndOfWord;
    }
};