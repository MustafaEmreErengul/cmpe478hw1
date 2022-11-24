#include <bits/stdc++.h>
using namespace std;

vector<string> readFile(string fileName) {
    
    ifstream file(fileName);
    string str;
    vector<string> content;
    while (getline(file, str))
    {
        content.push_back(str);
    }
    return content;
}

int main() {

    // content holds the list of lines
    vector<string> content = readFile("fool.txt");
    // create a map named map
    map<string, vector<string>> map;
    // we will split the lines into words, 2nd value will be the key, 1st value will be the value in the map, if the key is not in the map, we will add it, if it is in the map, we will update it
    for (int i = 0; i < content.size(); i++) {
        string line = content[i];
        vector<string> words;
        string word = "";
        for (auto x : line) {
            if (x == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word = word + x;
            }
        }
        words.push_back(word);
        //cout << words[0] << " " << words[1] << endl;
        if (map.find(words[1]) == map.end()) {
            map[words[1]] =  {words[0]};
        }
        else {
            map[words[1]].push_back(words[0]);
        }
    }
    // Now we have the map with 2nd value as key and 1st value as vector of values
    return 0;
}