#ifndef __OUTPUT_LAYER_HPP
#define __OUTPUT_LAYER_HPP

#include "layer.hpp"
#include "data.hpp"

class OutputLayer : public Layer
{
public:
	OutputLayer(int prev, int current) : Layer(prev, current) {}
	~OutputLayer();

	void feedFroward(Layer);
	void backProp(data *data);
	void updateWeights(double, Layer*);

};

#endif
