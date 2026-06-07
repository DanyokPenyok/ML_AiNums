#pragma once
#include <vector>
#include <cmath>
#include <random>
using namespace std;
class neuron {
private:
	vector<double> w; //веса рандом
	double b; //cмещение рандом
	double a; //шаг обучения

	double sigmoid(double z) {
		return 1.0 / (1.0 + exp(-z));
	}
public:
	neuron(int input_size, double lr = 0.1) {
		a = lr;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dist(-1.0, 1.0);
		for (int i = 0; i < input_size; i++)
		{
			w.push_back(dist(gen));
		}
		b = dist(gen);
	}
	double Z(vector<double>& x) {
		double Z = 0;
		for (int i = 0; i < x.size(); i++)
		{
			Z += x[i] * w[i];
		}
		Z += b;
		return sigmoid(Z);
	}
	void backward(vector<double>& x, double Y_true, double Y_hat) {
		double error = Y_true - Y_hat;
		double derivative = Y_hat * (1 - Y_hat);//производная
		double graditnt = error * derivative;
		for (int i = 0; i < w.size(); i++)
		{
			w[i] = w[i] + (a * graditnt * x[i]);
		}
		b = b + (a * graditnt);

	}
};

