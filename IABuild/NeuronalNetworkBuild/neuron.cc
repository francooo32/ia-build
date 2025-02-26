#include "neuron.hpp"
#include <random>

Neuron::Neuron(int prevLayerSize, int currentLayerSize)
{
	initializeWeights(prevLayerSize);
}

Neuron::~Neuron()
{
}

static double generateRandomNumber(double min, double max)
{
	double random = (double)rand() / RAND_MAX;
	return min + random * (max - min);
}

void Neuron::initializeWeights(int previousLayerSize)
{
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(0.0, 1.0);
	for (int i = 0; i < previousLayerSize + 1; i++)
	{
		weights.push_back(generateRandomNumber(-1.0, 1.0));
	}
}

