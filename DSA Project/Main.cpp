#include <iostream>
#include "RedBlackTree.h"
#include "Trie.h"
using namespace std;


int main() {
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(60);
    rbt.insert(20);
    rbt.insert(40);
    rbt.insert(50);
    rbt.insert(30);

    cout << endl << "Inorder traversal of Red-Black Tree: ";
    rbt.printTree();
    cout << endl << endl;

    Trie trie;
    trie.insert("hello");
    trie.insert("helloen");
    trie.insert("hellown");
    cout << "Searching for 'hello' in Trie: " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'hello' in Trie: " << (trie.search("helloen") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'hello' in Trie: " << (trie.search("hellown") ? "Found" : "Not Found") << endl;

    return 0;
}