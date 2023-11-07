#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<string> words = { "BlockDMask", "banana", "code", "program" };
    int len = static_cast<int>(words.size());

    ifstream readFromFile("words.txt");

    if (readFromFile.is_open()) {
        words.clear();.
        string tmp;
        while (getline(readFromFile, tmp)) {
            words.push_back(tmp);
        }
        readFromFile.close();
    }
    else {
        ofstream writeToFile("words.txt");
        for (int i = 0; i < len; ++i) {
            string tmp = words[i];
            if (i != len - 1) {
                tmp += "\n";
            }
            writeToFile << tmp;
        }
        writeToFile.close();
    }

    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}
