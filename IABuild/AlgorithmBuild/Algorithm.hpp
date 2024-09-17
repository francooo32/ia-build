#ifndef __ALGORITHM_H
#define _CRT_SECURE_NO_WARNINGS
#define __ALGORITHM_H

#include <vector>
#include "data.hpp"

class algorithm
{
	int alg;
	std::vector<data*>* neighbors; //Is the standard and also recommended algorithm to start.
	std::vector<data*>* training_data;
	std::vector<data*>* test_data;
	std::vector<data*>* validation_data;

public:
	algorithm();
	algorithm(int);
	~algorithm();
	
	void find_knearest(data *query_point);
	void set_training_data(std::vector<data*> *vector);
	void set_test_data(std::vector<data*>* vector);
	void set_validation_data(std::vector<data*>* vector);
	void set_k(int val);

	int predict();
	double calculate_distance(data* query_point, data* input);
	double validate_performance();
	double test_performance();

private:

	const char* READING_VECTOR = "Error ocurred, mismatch between vector sizes.\n";
	const char* PERFORMANCE_VALUE = "The performance is: %.3f %%\n";
	const char* TEST_PERFORMANCE_VALUE = "The test performance is: %.3f %%\n";

};

#endif