#ifndef __OUTPUT_LAYER_HPP
#define __OUTPUT_LAYER_HPP

#include "layer.hpp"

class OutputLayer : public Layer
{
public:
	OutputLayer(int prev, int current) : Layer(prev, current) {}

};

#endif
