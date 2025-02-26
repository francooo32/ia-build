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
	void setError(double);
	void setWeight(double, int);
	double calculatePreActivation(std::vector<double>);
	double activate();
	double calculateOutputDerivated();
	double sigmoid();
	double relu();
	double leakyRelu();
	double inverseSqtrRelu();
	double getOutput();
	double getOutputDerivate();
	double getError();
	std::vector<double> getWeights();
};

#endif 

