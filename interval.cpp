#ifndef MEDIAS_CONFIDENCEINTERVAL_H
#define MEDIAS_CONFIDENCEINTERVAL_H

#include "distribuition.h"
#include "average.h"
#include <list>
#include <algorithm>

//Intervalos de Confiança 3

using namespace std;

pair<double,double> t_distribution_confidence_interval(const vector<double>& data, double alpha){
    vector<double> confidence_list{};
    for (auto element : data){
        confidence_list.push_back(t_distribution_cdf(element, element-1));
    }

    sort(confidence_list.begin(),confidence_list.end());
    auto a = binary_search(confidence_list.begin(), confidence_list.end(), alpha);

    if (a != 0) {
        return {data[a], alpha};
    }else
        return {0.0,0.0};
}

#endif
