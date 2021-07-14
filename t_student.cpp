#ifndef MEDIAS_T_STUDENT_H
#define MEDIAS_T_STUDENT_H

#include "distribuition.h"
#include "average.h"
using namespace std;


//Teste T de Student



double standard_deviation(const vector<double>& data, double mean) {
    double sum = accumulate(data.begin(), data.end(), 0.0);
    double mean = sum/data.size();

    double sq_sum = inner_product(data.begin(), data.end(), data.begin(), 0.0);
    return sqrt(sq_sum/data.size() - mean * mean);
}
double statistic_T(vector<double>& numbers1, vector<double>& numbers2) {
    auto total_size = numbers1.size() + numbers2.size();
    auto n1 = mean(numbers1);
    auto n2 = mean(numbers2);
    double s1 = standard_deviation(numbers1, n1);
    double s2 = standard_deviation(numbers2, n2);
    return abs((mean(numbers1) - mean(numbers2))/sqrt(pow(s1,2) + pow(s2,2)) /total_size));
}

#endif
