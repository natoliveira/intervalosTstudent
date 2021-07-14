#ifndef MEDIAS_AVERAGE_H
#define MEDIAS_AVERAGE_H

#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

// Intervalos de Confiança 1

double normal_distribution_cdf(double x, double mu, double std_dev){
    auto result = (1 + erf(x-mu/std_dev * sqrt(2)))/2;
    return result;
}

double normal_distribution_cdf(double x){
    //média zero e desvio padrão 1.
    auto result = (1 + erf(x/1 * sqrt(2)))/2;
    return result;
}

double normal_distribution_cdf(double x1, double x2, double mu, double std_dev) {
    auto result_x1 = normal_distribution_cdf(x1, mu, std_dev);
    auto result_x2 = normal_distribution_cdf(x2, mu, std_dev);

    if (result_x1 > result_x2){
        return result_x1-result_x2;
    }else{
        return result_x2-result_x1;
    }
}

double normal_distribution_cdf(double x1, double x2){
    auto result_x1 = normal_distribution_cdf(x1);
    auto result_x2 = normal_distribution_cdf(x2);
    if (result_x1>result_x2){
        return result_x1-result_x2;
    }else{
        return result_x2-result_x1;
    }
}

double mean(const vector<double>& numbers) {
    //calculo da média aritmetica
    if(numbers.empty()){
        return 0.0;

    }
    double sum;
    sum = accumulate(numbers.begin(), numbers.end(), 0);
    return (double) sum/(int) numbers.size(); // média dos elementos de numbers
}

#endif
