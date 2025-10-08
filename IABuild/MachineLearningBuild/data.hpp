#ifndef __DATA_HPP
#define __DATA_HPP

#include <vector>
#include "stdint.h"
#include "stdio.h"

class data
{
	std::vector<uint8_t>* feature_vector;
	std::vector<double>* double_feature_vector;
	std::vector<int>* class_vector;
	uint8_t label;
	int enum_label;
	double distance;

public:
	data();
	~data();
	void set_feature_vector(std::vector<uint8_t>*);
	void append_to_feature_vector(uint8_t);
	void set_double_feature_vector(std::vector<double>*);
	void append_to_double_feature_vector(double);
	void set_class_vector(int count);
	void set_label(uint8_t);
	void set_enumerated_label(int);
	void set_distance(double val);

	int get_feature_vector_size();
	double get_distance();
	uint8_t get_label();
	uint8_t get_enumated_label();

	std::vector<uint8_t>* get_feature_vector();
	std::vector<double>* get_double_feature_vector();
	std::vector<int>* get_class_vector();

};

#endif
