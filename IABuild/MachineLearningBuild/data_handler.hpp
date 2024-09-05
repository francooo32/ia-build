#ifndef __DATA_HANDLER_H
#define _CRT_SECURE_NO_WARNINGS
#define __DATA_HANDLER_H

#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>


#include "stdint.h"
#include "data.hpp"

class data_handler
{
	std::vector<data *> *data_array;
	std::vector<data *> *training_data;
	std::vector<data *> *test_data;
	std::vector<data *> *validation_data;

	int num_clases;
	int feature_vector_size;
	std::map<uint8_t, int> class_map;

	const double TRAIN_SET_PERCENT = 0.75;
	const double TEST_SET_PERCENT = 0.20;
	const double VALIDATION_SET_PERCENT = 0.05;

public:
	data_handler();
	~data_handler();

	void read_feature_vector(std::string path);
	void read_feature_labels(std::string path);
	void split_data();
	void count_classes();

	uint32_t convert_to_little_endian(const unsigned char* bytes);

	std::vector<data*>* get_training_data();
	std::vector<data*>* get_test_data();
	std::vector<data*>* get_validation_data();

private:
	const char* HEADER_SUCCEED = "Succeeded processing header file.\n";
	const char* READING_ERROR = "An error occured while trying to read the file.\n";
	const char* NO_FILE_ERROR = "Looks like there is not file.\n";
	const char* SUCCESS_READING = "Succeeded reading and storing the file.\n";

	const char* TRAINING_SIZE = "Training size: %lu.\n";
	const char* TEST_SIZE = "Test size: %lu.\n";
	const char* VALIDATION_SIZE = "Validation size: %lu.\n";

	const char* SUCESS_EXTRACTING_CLASSES = "Clases where extracted successfuly: %d .\n";
};

#endif
