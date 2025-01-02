#include "common.hpp"

void common_data::set_training_data(std::vector<data*>* vector)
{
	training_data = vector;
}

void common_data::set_test_data(std::vector<data*>* vector)
{
	test_data = vector;
}

void common_data::set_validation_data(std::vector<data*>* vector)
{
	validation_data = vector;
}