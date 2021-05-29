#pragma once
#include <iostream>
using namespace std;

class Trie {
public:

    //------ Trienode CLASS ------//
    class Trienode
    {
    public:
        char val;               //The value of the character in the node
        int wc;                 //Word count up until this node
        bool endsHere;          //Signifies end of a word
        Trienode* child[26];    //The array of all possible letters

     
    };

    //------ Trie DATA MEMBERS ------//

    Trienode* root;

    //------ Trie Operations ------//


    Trienode* createNode(int index);
    /*--------------------------------------------------------------------
     Creates an empty Trie node
     Precondition:  Needs an index (index is calculated by subtracting the value of the node - 'a')
     Postcondition: A Trie node is created with a value of index-'a' and sets the value of the array
                    of 26 children to NULL
     ---------------------------------------------------------------------*/

    Trie();
    /*--------------------------------------------------------------------
     Default constructor: builds an empty Trie tree
     Precondition:  None
     Postcondition: root = '/' (unimportant value)
     ---------------------------------------------------------------------*/
    
    //~Trie();
    /*--------------------------------------------------------------------
     Default Destructor: Deletes the Trie tree
     Precondition: None
     Postcondition: The tree is deleted from the memory
     ---------------------------------------------------------------------*/

    void clear(Trienode* node);
    /*--------------------------------------------------------------------
     A helper function for the destructor
     Precondition:  None
     Postcondition: Deletes the node given to it as a parameter
     ---------------------------------------------------------------------*/

    void insert(string word);
    /*--------------------------------------------------------------------
     Inserts a given word (string) into the trie tree
     Precondition:  A trie tree is already created
     Postcondition: Creates nodes with values equal to the individual characters of the word inserted
     ---------------------------------------------------------------------*/

    bool search(string word);
    /*--------------------------------------------------------------------
     Searches for a given word
     Precondition:  None
     Postcondition: Returns true if the word is found and false if it isn't found
     ---------------------------------------------------------------------*/

    bool startsWith(string prefix);
    /*--------------------------------------------------------------------
     Checks to see if a word in the trie starts with a given prefix
     Precondition:  None
     Postcondition: Returns true if a word starts with the given prefix and false if no word does
     ---------------------------------------------------------------------*/

    void displayAllWords(Trienode* root, char* wordArray, int pos);
    /*--------------------------------------------------------------------
     Displays the Trie tree in alphabetical order from smallest to biggest 
     Precondition:  There exists at least one node in the tree
     Postcondition: The tree is printed in the console
     ---------------------------------------------------------------------*/

    int countPrefix(string s);
    /*--------------------------------------------------------------------
     Counts how many words in the trie tree start with a given prefix
     Precondition:  None
     Postcondition: Returns the number of words that start with the given prefix
     ---------------------------------------------------------------------*/

};//End of Trie class