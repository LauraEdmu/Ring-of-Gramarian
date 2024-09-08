#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <stdlib.h>

using namespace std;

void generateWords(string word, int x, int pos, vector<string>& result) {
    if (x == 0) {
        result.push_back(word);
        return;
    }
    for (int i = pos; i < word.size(); ++i) {
        char original_char = word[i];
        for (char c = 'a'; c <= 'z'; ++c) {
            if (c != original_char) {
                word[i] = c;
                generateWords(word, x - 1, i + 1, result);
            }
        }
        word[i] = original_char;
    }
}

unordered_set<string> loadDictionary(string path) {
    unordered_set<string> dictionary;
    ifstream file(path);
    string line;
    while (getline(file, line)) {
        dictionary.insert(line);
    }
    return dictionary;
}

int main() {
    unordered_set<string> dictionary = loadDictionary("dictionary.txt");

    cout << "Version 1.1" << endl << "Credits: Laura (IcedPhoenix)" << endl;

    while (true) {
        string word;
        cout << "Enter a word (or 'exit' to quit): ";
        cin >> word;

        if (word == "exit") {
            break;
        } else if (word == "clear") {
            system("cls");
            continue;
        }

        int x;
        cout << "Enter number of different letters: ";
        cin >> x;

        vector<string> generatedWords;
        generateWords(word, x, 0, generatedWords);

        for (auto& w : generatedWords) {
            if (dictionary.find(w) != dictionary.end()) {
                cout << w << endl;
            }
        }
    }

    return 0;
}
