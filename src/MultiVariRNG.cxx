#include "MultiVariRNG.h"

// Constructor
template <typename T1, typename T2>
MultiVariRNG<T1,T2>::MultiVariRNG(T1 mui, T2 sigmai, double seedi /* = 0 */)
:seed(seedi){

    if( sigmai.rows() != sigmai.cols() ){
        // throw non-matrix error
    }

    if( mui.rows() != sigmai.cols() ){
        // throw covariance error
    }

    // NEED TO: Check if seed is in viable range 

    // NEED TO: Check if inputs are Eigen Matrices 

    this -> mu = mui;
    this -> sigma = sigmai;
};

template <typename T1, typename T2>
Eigen::MatrixXd MultiVariRNG<T1,T2>::MVRNGenerate(){
    
};