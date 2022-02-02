#include "MultiVariRNG.h"

// ERROR HANDLER CONSTRUCTOR 
errorHandler::errorHandler(size_t idi, std::string msgi):
id(idi),msg(msgi){};

// ONLY CONSTRUCTOR - I RECOMMEND GETTING POINTER TO CLASS WITH "new" OPERATOR
template <typename T1, typename T2>
// NOTICE THAT SEED IS RANDOMIZED IF ONE IS NOT GIVEN
MultiVariRNG<T1,T2>::MultiVariRNG(T1 mui, T2 sigmai, int seedi /* = -1 */){

    /////////////////////////////////////////////////////////////////////////////////////////
    // MOST ERRORS WILL HAPPEN AT CONSTRUCTION, SO EXPECTED ERRORS ARE CHECKED HERE

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

    /////////////////////////////////////////////////////////////////////////////////////////

    this -> mu = mui;

    // Class doesn't use Sigma itself and therefor can instead just 
    // hold the Cholesky Covariance Decomposition

    this -> CholFacSigma = sigmai.llt().matrixL();

    // Seed Normal Distribution generator 
    if( seedi != -1){
        std::default_random_engine generator ( (unsigned int)seedi );
    }else{
        // Defaults to using system clock to generate random a seed 
        unsigned int seedRand = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator (seedRand);
    }

};

// GENERATOR MEMBER FUNCTION - ALL INPUTS ARE GIVEN AT CLASS CONSTRUCTION
// NOTE THAT THIS CLASS CANNOT CHANGE AFTER CONSTRUCTION BECAUSE ALL VARIABLES 
// USED ARE PRIVATE. [IF DYNAMIC MEAN AND COVARIANCE IS REQUESTED IT CAN BE 
// EASILY IMPLEMENTED]
template <typename T1, typename T2>
Eigen::MatrixXd MultiVariRNG<T1,T2>::MVRNGenerate(){

    // NEED TO: Populate Initial Random Vector 

    // NEED TO: Transform with Input Covariance and Mean
};