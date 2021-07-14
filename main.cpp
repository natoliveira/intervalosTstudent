#include <iostream>
#include "confidenceInterval.h"

int main() {

    vector<double> numbers = {1, 2, 3, 4};
    auto r = t_distribution_confidence_interval(numbers, 9);


    return 0;
}
