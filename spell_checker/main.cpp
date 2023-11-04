#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

struct TrieNode{
    bool endOfWord;
    vector<TrieNode*> children;
    TrieNode(){
        endOfWord = false;
        children = vector<TrieNode *>(26, nullptr);
    }
};

void printRed(const string& word){
    cout << "\033[31m" << word << "\033[0m";
}

void insertWord(TrieNode* root, const string &word){
    TrieNode *currentNode = root;
    for(char c: word){
        int index = tolower(c) - 'a';
        if(currentNode->children[index] == nullptr){
            currentNode->children[index] = new TrieNode();
        }
        currentNode = currentNode->children[index];
    }
    currentNode->endOfWord = true;
}

bool searchWord(TrieNode *root, string &word){
    TrieNode *currentNode = root;
    for(char c: word){
        int index = c - 'a';
        if(currentNode->children[index]==nullptr){
            return false;
        }
        currentNode = currentNode->children[index];
    }
    return currentNode != nullptr && currentNode->endOfWord;
}

vector<string> getSuggestions(TrieNode* root, const string &word){
    vector<string> suggestions;

    for (int i = 0; i < word.length();++i){
        for (char c = 'a'; c <= 'z';c++){
            string modified = word;
            modified[i] = c;
            if(searchWord(root,modified)){
                suggestions.push_back(modified);
            }
        }
    }

    for (int i = 0; i <= word.length();++i){
        for (char c = 'a'; c <= 'z';c++){
            string modified = word;
            modified.insert(i, 1, c);
            if(searchWord(root, modified)){
                suggestions.push_back(modified);
            }
        }
    }

    for (int i = 0; i < word.length();++i){
        string modified = word;
        modified.erase(i, 1);
        if(searchWord(root, modified)){
            suggestions.push_back(modified);
        }
    }

    for (int i = 0; i < word.length()-1;++i){
        string modified = word;
        swap(modified[i], modified[i + 1]);
        if(searchWord(root, modified)){
            suggestions.push_back(modified);
        }
    }

    return suggestions;
}

int main(){
    TrieNode *root = new TrieNode();
    ifstream dictFile("dictionary.txt");
    string word;
    while(getline(dictFile, word)){
        insertWord(root, word);
    }

    dictFile.close();

    string sentence;
    cout << "Enter a sentence ";
    getline(cin, sentence);
    for(char &c: sentence){
        c = tolower(c);
    }

    stringstream ss(sentence);
    bool firstWord = true;
    vector<string> misspelledWords;

    while(ss>>word){
        if(!searchWord(root, word)){
            if(!firstWord){
                cout << " ";
            }
            printRed(word);
            misspelledWords.push_back(word);
        }else{
            if(!firstWord){
                cout << " ";
            }
            cout << word;
        }
        firstWord = false;
    }

    cout << endl;

    for(const string &misspelledWord: misspelledWords){
        vector<string> suggestions = getSuggestions(root, misspelledWord);
        if(!suggestions.empty()){
            cout << "Suggestions for " << misspelledWord << " :";
            for(const string &suggestion: suggestions){
                cout << suggestion << " ";
            }
            cout << endl;
        }
    }

    return 0;
}