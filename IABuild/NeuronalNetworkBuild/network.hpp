#ifndef __NETWORK_HPP
#define __NETWORK_HPP

#include "data.hpp"
#include "neuron.hpp"
#include "layer.hpp"
#include "hidden_layer.hpp"
#include "input_layer.hpp"
#include "output_layer.hpp"
#include "common.hpp"

class Network : public common_data
{
private:
	InputLayer* inputLayer;
	OutputLayer* outputLayer;
	std::vector<Layer*> layers;
	std::vector<HiddenLayer*> hiddenLayers;
	double learningRate;
	double testPerformance;
	double eta;

public:
		Network(std::vector<int> spec, int, int, double);
		~Network();
		
		std::vector<double> fprop(data *data);
		double activate(std::vector<double>, std::vector<double>);
		double transfer(double);
		double transferDerivate(double);
		double test();
		int predict(data* data);
		void bprop(data *data);
		void updateWeights(data* data);
		void train(int);
		void validate();
};

#endif 
