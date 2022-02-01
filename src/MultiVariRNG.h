#pragma once
#include <Eigen/Dense>

template <typename T1, typename T2>
// Template 1 is for mu -> Mean Vector
// Template 2 is for sigma -> Covariance Matrix

// A class which holds the MV random number generator
class MultiVariRNG{
    private:
        double seed;
        T1 mu;
        T2 sigma;

    public:
        MultiVariRNG(T1, T2, double = 0);
        Eigen::MatrixXd MVRNGenerate();
};
