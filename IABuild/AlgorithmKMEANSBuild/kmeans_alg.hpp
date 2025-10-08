#ifndef __KMEANS_ALG_HPP
#define _CRT_SECURE_NO_WARNINGS
#define __KMEANS_ALG_HPP

#include "common.hpp"
#include <unordered_set>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <map>
#include "data_handler.hpp"

typedef struct cluster
{

	std::vector<double>* centroid;
	std::vector<data*>* cluster_points;
	std::map<int, int> class_counts;
	int most_frequent_class;

	cluster(data* initial_point)
	{
		centroid = new std::vector<double>;
		cluster_points = new std::vector<data*>;
		for (auto value : *(initial_point->get_feature_vector()))
		{
			centroid->push_back(value);
		}
		cluster_points->push_back(initial_point);
		class_counts[initial_point->get_label()] = 1;
		most_frequent_class = initial_point->get_label();
	}

	void add_to_cluster(data* point)
	{
		int prevoious_size = cluster_points->size();
		cluster_points->push_back(point);
		for (int i = 0; i < centroid->size() - 1; i++)
		{
			double value = centroid->at(i);
			value *= prevoious_size;
			value += point->get_feature_vector()->at(i);
			value /= (double)cluster_points->size();
			centroid->at(i) = value;
		}
		if (class_counts.find(point->get_label()) == class_counts.end())
		{
			class_counts[point->get_label()] = 1;
		}
		else
		{
			class_counts[point->get_label()]++;
		}
		set_most_frequent_class();
	}

	void set_most_frequent_class()
	{
		int best_class;
		int freq = 0;
		for (auto kv : class_counts)
		{
			if (kv.second > freq)
			{
				freq = kv.second;
				best_class = kv.first;
			}
		}
		most_frequent_class = best_class;
	}

} cluster_t;

class kmeans_alg : public common_data
{
	int num_clusters;
	std::vector<cluster_t*>* clusters;
	std::unordered_set<int>* used_indexes;

public:

	kmeans_alg(int k);

	void init_cluster();
	void init_cluster_for_each_class();
	void train();
	double euclidean_distance(std::vector<double> *, data *);
	double validate();
	double test();

};


#endif