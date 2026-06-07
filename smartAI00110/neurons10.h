#pragma once
#include <vector>
#include <cmath>
#include <random>
using namespace std;
class neurons10
{
private:
	vector<vector<double>> w;
	vector<double> b;
	double learning_rate;
	vector<double> softmax(vector<double>& Z);
public:
	neurons10(int size, int nums, double lr);//размер колвоцифер learningrate
	vector<double> Z(vector<double> & X);
	void Learn(vector<double>& X, int Y_Real, vector<double>& Y_Teor);
};

