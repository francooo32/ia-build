#include "knn_alg.hpp"
#include <cmath>
#include <limits>
#include <map>
#include "stdint.h"
#include "data_handler.cc"

knn_alg::knn_alg()
{

}

knn_alg::knn_alg(int val)
{
	alg = val;
}

knn_alg::~knn_alg()
{

}

void knn_alg::find_knearest(data* query_point)
{
	neighbors = new std::vector<data*>;
	double min = std::numeric_limits<double>::max();
	double previous_min = min;
	int index = 0;
	for (int i = 0; i < alg; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < training_data->size(); j++)
			{
				double distance = calculate_distance(query_point, training_data->at(j));
				training_data->at(j)->set_distance(distance);
				if (distance < min)
				{
					min = distance;
					index = j;
				}
			}
			neighbors->push_back(training_data->at(index));
			previous_min = min;
			min = std::numeric_limits<double>::max();
		}
		else
		{
			for (int j = 0; j < training_data->size(); j++)
			{
				double distance = training_data->at(j)->get_distance();
				if (distance > previous_min && distance < min)
				{
					min = distance;
					index = j;
				}
			}
			neighbors->push_back(training_data->at(index));
			previous_min = min;
			min = std::numeric_limits<double>::max();
		}
	}

}

void knn_alg::set_k(int val)
{
	alg = val;
}

int knn_alg::predict()
{
	std::map<uint8_t, int> class_freq;
	for (int i = 0; i < neighbors->size(); i++)
	{
		if (class_freq.find(neighbors->at(i)->get_label()) == class_freq.end())
		{
			class_freq[neighbors->at(i)->get_label()] = 1;
		}
		else
		{
			class_freq[neighbors->at(i)->get_label()]++;
		}
	}

	int best = 0;
	int max = 0;
	
	for (auto &kv : class_freq) 
	{
		if (kv.second > max) 
		{
			max = kv.second;
			best = kv.first;
		}
	}

	neighbors->clear();
	return best;
}

double knn_alg::calculate_distance(data* query_point, data* input)
{
	double distance = 0.0;
	if (query_point->get_feature_vector_size() != input->get_feature_vector_size())
	{
		printf(READING_VECTOR);
		exit(1);
	}
	for (unsigned i = 0; i < query_point->get_feature_vector_size(); i++) {
		distance += pow(query_point->get_feature_vector()->at(i) - input->get_feature_vector()->at(i), 2);
	}
	distance = sqrt(distance);
	//printf("%f \n", distance);
	return distance;
}

double knn_alg::validate_performance()
{
	double current_performance = 0;
	int count = 0;
	int data_index = 0;

	for (data* query_point : *validation_data)
	{
		find_knearest(query_point);
		int prediction = predict();
		printf("%d -> %d \n", prediction, query_point->get_label());
		if (prediction == query_point->get_label())
		{
			count++;
		}
		data_index++;
		printf( PERFORMANCE_VALUE, ((double)count*100.0) / ((double) data_index) );
	}
	current_performance = ((double)count * 100.0) / ((double)validation_data->size());
	printf(PERFORMANCE_VALUE, current_performance);
	return current_performance;
}

double knn_alg::test_performance()
{
	double current_performance = 0;
	int count = 0;

	for (data* query_point : *test_data)
	{
		find_knearest(query_point);
		int prediction = predict();
		if (prediction == query_point->get_label())
		{
			count++;
		}
	}

	current_performance = ((double)count + 100.0) / ((double)test_data->size());
	printf(TEST_PERFORMANCE_VALUE, current_performance);
	return current_performance;
}

//int main()
//{
//	data_handler* dh = new data_handler();
//	dh->read_feature_vector("../MNIST_data/train-images.idx3-ubyte");
//	dh->read_feature_labels("../MNIST_data/train-labels.idx1-ubyte");
//	dh->split_data();
//	dh->count_classes();
//
//	knn_alg* algorithm_nearest = new knn_alg();
//	algorithm_nearest->set_training_data(dh->get_training_data());
//	algorithm_nearest->set_test_data(dh->get_test_data());
//	algorithm_nearest->set_validation_data(dh->get_validation_data());
//	double data_performance = 0;
//	double best_data_performance = 0;
//	int best_k = 1;
//	for (int i = 1; i <= 4; i++)
//	{
//		if (i == 1)
//		{
//			algorithm_nearest->set_k(i);
//			data_performance = algorithm_nearest->validate_performance();
//			best_data_performance = data_performance;
//		}
//		else
//		{
//			algorithm_nearest->set_k(i);
//			data_performance = algorithm_nearest->validate_performance();
//			if (data_performance > best_data_performance)
//			{
//				best_data_performance = data_performance;
//				best_k = i;
//			}
//		}
//	}
//	algorithm_nearest->set_k(best_k);
//	algorithm_nearest->test_performance();
//}
