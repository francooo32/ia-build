#ifndef __NEURON_HPP
#define __NEURON_HPP

#include <cmath>
#include <vector>

class Neuron
{
	public:
		std::vector<double> weights;
		double preActivation;
		double activatedOutput;
		double output;
		double error;
		double delta;

public:
	Neuron(int, int);
	~Neuron();
	void initializeWeights(int previousLayerSize);
};

#endif 

