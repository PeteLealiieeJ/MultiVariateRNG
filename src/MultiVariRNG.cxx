#include "MultiVariRNG.h"

// Error handler 
errorHandler::errorHandler(size_t idi, std::string msgi):
id(idi),msg(msgi){};

// Constructor
template <typename T1, typename T2>
MultiVariRNG<T1,T2>::MultiVariRNG(T1 mui, T2 sigmai, double seedi /* = 0 */)
:seed(seedi){

    try{

        if( sigmai.rows() != sigmai.cols() ){
            std::string msg{  
                "Covariance Matrix is NOT A SQUARE MATRIX"
            };
            throw(errorHandler(1,msg));
        };

        if( mui.rows() != sigmai.cols() ){
            std::string msg{  
                "Number of Mean Values and Number of Correlated elements not equal"
            };
            throw(errorHandler(2,msg));
        };

        // NEED TO: Check if seed is in viable range 

        // NEED TO: Check if inputs are Eigen Matrices 

    }catch( errorHandler& e ){
        std::cout << "ERROR CODE: " << e.id
                << " \n - " << e.msg << std::endl;
    }

    this -> mu = mui;

    // Class doesn't use Sigma itself and therefor can instead just 
    // hold the Cholesky Covariance Decomposition

    this -> CholFacSigma = sigmai.llt().matrixL();

};

template <typename T1, typename T2>
Eigen::MatrixXd MultiVariRNG<T1,T2>::MVRNGenerate(){

    
};