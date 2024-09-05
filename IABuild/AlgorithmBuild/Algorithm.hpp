#ifndef __ALGORITHM_H
#define __ALGORITHM_H

#include <vector>
#include "../MachineLearningBuild/data.hpp"

class algorithm
{
	int alg;
	std::vector<data>* neighbors(); //Is the standard and also recommended algorithm to start.
	std::vector<data>* training_data(); //Is the standard and also recommended algorithm to start.
	std::vector<data>* test_data(); //Is the standard and also recommended algorithm to start.
	std::vector<data>* validation_data(); //Is the standard and also recommended algorithm to start.


public:
	algorithm();
	~algorithm();
	void set_feature_vector(std::vector<uint8_t>*);
	void append_to_feature_vector(uint8_t);
	void set_label(uint8_t);
	void set_enumerated_label(int);

	int get_feature_vector_size();
	uint8_t get_label();
	uint8_t get_enumated_label();

	std::vector<uint8_t>* get_feature_vector();

};

#endif