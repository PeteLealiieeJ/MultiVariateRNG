// HEADER ONLY BECAUSE OF TEMPLATING METHOD

// INCREASE COMPILATION TIMES BECAUSE IT IS APPENDED 
// TO WHERE IT IS INCLUDED (HEADER)

#pragma once

// NOTICE THAT EIGEN ISN'T USED AT ALL IN THIS TEMPLATE HEADER.

// ALTHOUGH THE REQUIREMENT FOR EIGEN IS APPARENT, THE HEADER DOESN'T
// INCLUDE <EIGEN/DENSE> TO BE SAFE BECAUSE EIGEN IS OFTEN INCLUDED IN PROJECTS 
// IN MANY DIFFERENT FASHIONS (USER INCLUDE, PROJECT INCLUDE, ETC.)

// THIS MAKES IT THE RESPONSIBILITY OF THE USER TO INCLUDE EIGEN 
// ALONG WITH THIS HEADER OF THEIR OWN FASHION. SEE EXAMPLES FOLDER.

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

template <class T1, class T2>
// TEMPLATE 1 IS FOR mu AND generation output -> Mean Vector AND transformed sample
// TEMPLATE 2 IS FOR sigma -> Covariance Matrix

// MultiVariRNG CLASS: ALLOCATE AND POINT TO THE CLASS VARIABLE 
// USING THE "new" OPERATOR SUCH THAT YOU CAN CALL ITS 
// CONSTRUCTOR OR CONSTRUCT THE VARIABLE TYPE NORMALLY. 
// NOTICE THAT THIS CLASS HAS NO DEFAULT CONSTRUCTOR.
class MultiVariRNG{
    private:
        T1 mu;
        T2 CholFacSigma;
        // STANDARD NORMAL DISTRIBUTION = ZERO MEAN & STD OF ONE
        // THE "normal_distribution<double>"'s DEFAULT CONSTRUCTOR USES STANDARD,
        // BUT TO BE SAFE THE BELOW IS DONE. IT CAN BE COMMENTED OUT
        std::normal_distribution<double> norm_dist{0.,1.}; 
        std::mt19937 generator;

    public:
        MultiVariRNG(T1, T2, int = -1);
        T1 MVRNGenerate();
};

// ERROR HANDLER CONSTRUCTOR 
errorHandler::errorHandler(size_t idi, std::string msgi):
id(idi),msg(msgi){};

// ONLY CONSTRUCTOR - I RECOMMEND GETTING POINTER TO CLASS WITH "new" OPERATOR
// OR OPERATING NORMALLY
template <class T1, class T2>
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

        if( mui.cols() > 1 || mui.rows() <= 1 ){
            std::string msg{  
                "Currently, ONLY column VECTORS are accepted"
            };
            throw(errorHandler(2,msg));
        }

        // NEED TO: Check if seed is in viable range 

        // NEED TO: Check if inputs are Eigen Matrices 

    }catch( errorHandler& e ){
        std::cout << "ERROR CODE: " << e.id
                << " \n - " << e.msg << std::endl;
    }

    /////////////////////////////////////////////////////////////////////////////////////////

    // PASS NEEDED PARAMETERS TO CLASS
    this -> mu = mui;
    this -> CholFacSigma = sigmai.llt().matrixL();

    // SEED STANDARD NORMAL DISTRIBUTED RANDOM NUMBER GENERATOR
    if( seedi != -1){
        this -> generator = std::mt19937( (unsigned int) seedi );
    }else{
        // NOTICE THAT SEED IS PSUEDO-RANDOMIZED IF ONE IS NOT GIVEN
        unsigned int seedRand = std::chrono::system_clock::now().time_since_epoch().count();
        this -> generator = std::mt19937(seedRand);
    }

};

// GENERATOR MEMBER FUNCTION - ALL INPUTS ARE GIVEN AT CLASS CONSTRUCTION

// NOTE THAT THIS CLASS CANNOT CHANGE AFTER CONSTRUCTION BECAUSE ALL VARIABLES 
// USED ARE PRIVATE. [IF DYNAMIC MEAN AND COVARIANCE INPUTS ARE REQUESTED IT CAN BE 
// EASILY IMPLEMENTED]
template <class T1, class T2>
T1 MultiVariRNG<T1,T2>::MVRNGenerate(){

    // POPULATE INTITIAL RANDOM VECTOR
    T1 xbar = T1::Zero();
    for( size_t i = 0; i < xbar.size(); i++ ){
        xbar(i) = norm_dist( this -> generator );
    }

    // TRANSFORM WITH INPUT COVARIANCE AND MEAN VECTOR
    return( ((this->CholFacSigma) * xbar) + this->mu );
};
