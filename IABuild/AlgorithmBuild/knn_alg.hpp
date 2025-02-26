#ifndef __KNN_ALG_HPP
#define _CRT_SECURE_NO_WARNINGS
#define __KNN_ALG_HPP

#include "common.hpp"

class knn_alg : public common_data
{
	int alg;
	std::vector<data*>* neighbors; //Is the standard and also recommended algorithm to start.

public:
	knn_alg();
	knn_alg(int);
	~knn_alg();
	
	void find_knearest(data *query_point);
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