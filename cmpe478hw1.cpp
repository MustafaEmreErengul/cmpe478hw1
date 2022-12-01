#include <bits/stdc++.h>
using namespace std;

#define epsilon 0.000001 // 10^-6
#define alfa 0.2



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


double sumOfpagerankDifference(vector<vector<double>> iterations, int mapSize) {
    double sum = 0;
    for(int i = 1; i < iterations.size(); i++){
        for(int j = 0; j < mapSize; j++){
            sum += fabs(iterations[i][j] - iterations[i-1][j]);
        }
    }
    return sum;
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
    // Now we will implement Google's PageRank Algorithm using the map we have acquired.
    // r = a double array that contains the page ranks of the pages, r[0] = unit matrix containing n values of 1
    // there are as many pages as there are keys in the map, call this number n
    // P = probability matrix
    // c = unit matrix containing n values of 1
    // r[1]  = alfa * P * r[0] + (1 - alfa) * c
    // r[2]  = alfa * P * r[1] + (1 - alfa) * c
    // we will write a while loop that will stop when the difference between r[i] and r[i-1] is less than epsilon
    // we have the map, we have the number of pages, we have the unit matrix, we have the probability matrix, we have the alfa and epsilon values

    // create a 1 column matrix that contains n values of 1
    int n = map.size();
    vector<double> c;
    for (int i = 0; i < n; i++) {
        c.push_back(1);
    }
    cout << n << endl;
    vector<vector<double>> iterations;
    double P[n][n];
    //iterations holds the values of r[i], r[0] is the unit matrix, fill iterations[0] with 1's

    vector<double> r0;
    for (int i = 0; i < n; i++) {
        r0.push_back(1);
    }
    iterations.push_back(r0);
    
    int i = 0;
    double cTemp[n];
    for (int j = 0; j < n; j++) {
        cout << "CANCERs" << endl;
        cTemp[j] = (1 - alfa) * c[j];
    }
    vector<vector<double>> iterationsTemp;

    // sumOfpagerankDifference(iterations, n)
    while(1 > epsilon){ // while the difference between r[i] and r[i-1] is greater than epsilon
        
        cout << "CANCER6" << endl;
        //print the values of iterations
        for (int j = 0; j < iterations.size(); j++) {
            for (int k = 0; k < iterations[j].size(); k++) {
                cout << iterations[j][k] << " ";
            }
            cout << endl;
        }

        // multiply all the values in iterations[i] with alfa and assign it to a temporary variable iterationsTemp
        vector<double> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(alfa * iterations[i][j]); //iterations i'nin j. elemanı olmak zorunda çünkü aşşağıda doldurmuş olmalıyız.
        }
        iterationsTemp.push_back(temp);

        // create the probability matrix and fill it with 0's
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                P[j][k] = 0;
            }
        }
        cout << "CANCER7" << endl;
        
        // if there is no link from page j to page k, then P[j][k] = 0
        // we will use the map to fill the probability matrix

        // create a vector that contains the keys of the map
        vector<string> keys;
        for (auto x : map) {
            keys.push_back(x.first);
        }
        // create a vector that contains the values of the map
        vector<vector<string>> values;
        for (auto x : map) {
            values.push_back(x.second);
        }
        // fill the probability matrix, if there is a link from page j to page k, then P[j][k] = 1 / number of links in page j
        // number of values in the map with the key of keys[i] is the number of links in page i
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < values[j].size(); l++) {
                    if (keys[k] == values[j][l]) {
                        P[j][k] = 1 / values[j].size();
                    }
                }
            }
        }


        cout << "CANCER8" << endl;
        // multiply the probability matrix with the iterationsTemp, and assign it to PTemp
        double PTemp[n][n];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                PTemp[j][k] = 0;
            }
        }
        cout << "CANCERDE" << endl;



        //WRONG 
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    PTemp[j][k] += P[j][l] * iterationsTemp[i][l];
                }
            }
        }
        //WRONG




        cout << "CANCER9" << endl; 
        // add the values in PTemp and cTemp and assign it to iterations[i+1]
        for (int j = 0; j < n; j++) {
            iterations[i+1].push_back(PTemp[i][j] + cTemp[j]);
        }
        cout << "CANCER10" << endl;
        
        i++;
    }

    return 0;
}