#pragma once
#include <Eigen/Dense>
#include <string>
#include <iostream>
#include <random>
#include <chrono>

class errorHandler{
    public:
        size_t id;
        std::string msg;
        errorHandler( size_t, std::string );
};

template <typename T1, typename T2>
// TEMPLATE 1 IS FOR mu -> Mean Vector
// TEMPLATE 2 IS FOR sigma -> Covariance Matrix

// MVRNG CLASS: ALLOCATE AND POINT TO THE CLASS VARIABLE 
// USING THE "new" OPERATOR SUCH THAT YOU CAN CALL ITS 
// CONSTRUCTOR. NOTICE THAT THIS CLASS HAS NO DEFAULT 
// CONSTRUCTOR
class MultiVariRNG{
    private:
        T1 mu;
        T2 CholFacSigma;
        // Normal Distribution - Zero Mean, Standard Deviation of One
        std::normal_distribution<double> norm_dist; 

    public:
        MultiVariRNG(T1, T2, int = -1);
        Eigen::MatrixXd MVRNGenerate();
};
