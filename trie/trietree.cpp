#include <iostream>
#include "trietree.h"
using namespace std;

/*------Implementation of Constructor------*/
Trie::Trie() {

    root = createNode('/' - 'a');
}


/*------ Implementation of createNode member function ------*/
Trie::Trienode* Trie::createNode(int index)
{
    Trienode* newnode = new Trienode;

    newnode->val = 'a' + index;
    newnode->wc = newnode->endsHere = false;

    for (int i = 0; i < 26; ++i) {
        newnode->child[i] = NULL;
    }

    return newnode;
}

/*------ Implementation of insert member function ------*/
void Trie::insert(string word) {

    Trienode* curr = root;
    int index;

    for (int i = 0; word[i] != NULL; i++)
    {
        index = word[i] - 'a';
        if (curr->child[index] == NULL)
            curr->child[index] = createNode(index);
        curr->child[index]->wc += 1;
        curr = curr->child[index];
    }

    curr->endsHere = 1;
}

/* ------ Implementation of search member function ------ */
bool Trie::search(string word) {

    Trienode* curr = root;
    int index;

    for (int i = 0; word[i] != NULL; ++i)
    {
        index = word[i] - 'a';
        if (curr->child[index] == NULL)
            return false;
        curr = curr->child[index];
    }

    return (curr->endsHere > 0);
}

/*------ Implmenetation of startsWith member function ------*/
bool Trie::startsWith(string prefix) {

    Trienode* curr = root;
    int index;

    for (int i = 0; prefix[i] != NULL; ++i)
    {
        index = prefix[i] - 'a';
        if (curr->child[index] == NULL)
            return false;
        curr = curr->child[index];
    }

    return (curr->wc > 0);
}

/*------ Implmenetation of countPrefix member function ------*/
int Trie::countPrefix(string s)
{
    Trienode* curr = root;
    int index;

    for (int i = 0; s[i] != NULL; ++i)
    {
        index = s[i] - 'a';
        if (curr->child[index] == NULL)
            return 0;   //No string with given prefix is present
        curr = curr->child[index];
    }

    return curr->wc;
}

/*------ Implmenetation of displayWord function ------*/
void displayWord(char* str, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << str[i] ;
    }
}

/*------ Implmenetation of displayAllWords function ------*/
void Trie::displayAllWords(Trienode* root, char* wordArray, int pos)
{
    if (root == NULL)
        return;
    if (root->endsHere)
    {
        displayWord(wordArray, pos);
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i] != NULL)
        {
            wordArray[pos] = i + 'a';
            displayAllWords(root->child[i], wordArray, pos + 1);
        }
    }
    
}



/*------ Driver Program ------*/
int main()
{
    Trie trietree;
    int x;
    string word;
    int choice;
    char* wordArray = new char;

    

insertionLoop:
    cout << "Enter the number of total words: " << endl;
    cin >> x;
    string* array = new string[x];
    cout << endl;

    cout << "(please make sure that all words are small characters and no words are repeated)" << endl;
    cout << "Please enter the words one after the other" << endl;
    cout << endl;

    for (int i = 0; i < x; i++) {
        cin >> array[i];
        trietree.insert(array[i]);
    }
    cout << "_______________________________________________________" << endl;

    

    while (1) {
        int pos = 0;
        

        cout << "What operation would you like to do?" << endl;
        cout << "Count Prefix -> 1" << endl;
        cout << "Search       -> 2" << endl;
        cout << "Starts With  -> 3" << endl;
        cout << "Display Tree -> 4" << endl;
        cout << "Add Words    -> 5" << endl;
        cout << "Exit Program -> 6" << endl;

        cout << endl;
        cin >> choice;
        cout << "_______________________________________________________" << endl;

        switch (choice) {

        case 1:
            cout << "What word would you like to count prefixes for?" << endl;

            cin >> word;
            cout << "There exists a total of "<< trietree.countPrefix(word) <<" words that start with the given prefix!"<< endl;
            cout << "_______________________________________________________" << endl;
            break;

        case 2:
            cout << "What word would you like to search for in the tree ?" << endl;
            cin >> word;
            cout << endl;
            if (trietree.search(word)) {
                cout << "Word " << word << " is found in the tree!" << endl;
            }
            else
                cout << "Word " << word << " is not found in the tree!" << endl;
            cout << "_______________________________________________________" << endl;
            break;

        case 3:
            cout << "What prefix would you like to see if it exists in the tree? " << endl;
            cin >> word;
            if (trietree.startsWith(word) == true) {
                cout << "There exist one or more words with the given prefix in the tree!" << endl;
            }
            else
                cout << "No words start with the given prefix in the tree!" << endl;

            cout << "_______________________________________________________" << endl;
            break;
    
        case 4:
            trietree.displayAllWords(trietree.root, wordArray, pos);
            cout << endl;
            cout << endl;
            break;

        case 5:
            goto insertionLoop;
            break;

        case 6:
            return 0;

        }
    }

}

/*------Implementation of Destructor------*/
/*Trie::~Trie() {
    clear(root);
}

/*------Implementation of clear member function------*/
/*void Trie::clear(Trienode* node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        clear(node->child[i]);
    }
    delete node;
}*/