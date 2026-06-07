#include "neurons10.h"
#include <cmath>  
#include <random>
neurons10::neurons10(int size, int nums, double lr) { 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-0.5, 0.5);

    w.resize(nums, vector<double>(size));
    b.resize(nums, 0.0);
    learning_rate = lr;
    for (size_t i = 0; i < nums; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            w[i][j] = dist(gen);
        }
    }
}

vector<double> neurons10::softmax(vector<double>& Z) { //Ќјƒќ ќѕ“»ћ»«»–ќ¬ј“№!!!!!!!!!!!!!!!!!!!!!!!!!!! —Ћќ∆Ќќ—“№ ON2
    vector<double> softmax(b.size(), 0.0);
    double maxz = Z[0];
    for (size_t i = 0; i < Z.size(); i++) // чтоб не выбить че нибудь
    {
        if (Z[i] > maxz){
            maxz = Z[i];
        }
    }
    
    for (size_t i = 0; i < Z.size(); i++)
    {
        double sum = 0.0;
        double zi = exp(Z[i] - maxz);
        for (size_t j = 0; j < Z.size(); j++)
        {
            sum +=(exp(Z[j] - maxz));
        }
        softmax[i] = zi / sum;
    }
    
    return softmax;
}

vector<double> neurons10::Z(vector<double>& X) {
    vector<double> Z(b.size(), 0.0);
    for (size_t i = 0; i < b.size(); i++)
    {
        double sum = 0.0;
        for (size_t j = 0; j < X.size(); j++)
        {
            sum += X[j] * w[i][j];
        }
        Z[i] = sum + b[i];
    }
    return softmax(Z);
}

void neurons10::Learn(vector<double>& X, int Y_Real, vector<double>& Y_Teor) {
    int wnums = w.size();//размер 10 * 784... ¬ывод 10!
    vector<double>Y_One(w.size(), 0.0);
    Y_One[Y_Real] = 1.0;
    for (size_t i = 0; i < wnums; i++)
    {
        double error = Y_Teor[i] - Y_One[i];
        for (size_t j = 0; j < X.size(); j++)
        {
            w[i][j] = w[i][j] - learning_rate * error * X[j];
        }
        b[i] = b[i] - (learning_rate * error);
    }
}