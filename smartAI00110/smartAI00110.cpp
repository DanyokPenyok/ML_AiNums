#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include "neurons10.h"
using namespace std;
//сделать функцию потерь через -sum...  
// C:\\Users\\danya\\OneDrive\\Рабочий стол\\mnist_train.csv 
// setlocale(LC_ALL, "Rus");
// setlocale(LC_NUMERIC, "C");
bool load_mnist_csv(const string& filename, vector<vector<double>>& X, vector<double>& Y) {
    ifstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string value;

        if (getline(ss, value, ',')) {
            Y.push_back(stod(value));
        }

        vector<double> pixels;
        pixels.reserve(784);

        while (getline(ss, value, ',')) {
            pixels.push_back(stod(value));
        }

        X.push_back(pixels);
    }

    file.close();
    return true;
}
