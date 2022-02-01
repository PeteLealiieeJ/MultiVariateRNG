#pragma once
#include <Eigen/Dense>
#include <string>
#include <iostream>

class errorHandler{
    public:
        size_t id;
        std::string msg;
        errorHandler( size_t, std::string );
};

template <typename T1, typename T2>
// Template 1 is for mu -> Mean Vector
// Template 2 is for sigma -> Covariance Matrix

// A class which holds the MV random number generator
class MultiVariRNG{
    private:
        double seed;
        T1 mu;
        T2 CholFacSigma;

    public:
        MultiVariRNG(T1, T2, double = 0);
        Eigen::MatrixXd MVRNGenerate();
};
