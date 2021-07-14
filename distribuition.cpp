#ifndef MEDIAS_DISTRIBUITION_H
#define MEDIAS_DISTRIBUITION_H

#include <cmath>
#include <gsl/gsl_sf_hyperg.h>

//Intervalos de Confiança 2

double t_distribution_pdf(double x, int v){
    auto t_distribution = (tgamma(v+1/2)/ sqrt(v * M_PI) * tgamma(v/2)) * pow((1+pow(x,2)/v), -(v+1/2));

    return t_distribution;
}

double t_distribution_cdf(double x, int v){
    //2F1
    auto result = 1/2 + (x * (tgamma((v + 1) / 2)) * (gsl_sf_hyperg_2F1(1/2, (v + 1)/2, 3/2, -(pow(x, 2)) /v))/(sqrt(v * M_PI) * tgamma(v/2)));
    return result;

    // BOOST nao funcionou hypergeometric_distribution(unsigned r, unsigned n, unsigned N);
}

double t_distribution_cdf(double x1, double x2, int v){

    auto result_x1 = t_distribution_pdf(x1, v);
    auto result_x2 = t_distribution_pdf(x2, v);
    if (result_x1 > result_x2){
        return result_x1-result_x2;
    }else{
        return result_x2-result_x1;
    }
}


#endif

