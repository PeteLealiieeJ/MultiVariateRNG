#include <MultiVariRNG.h>

// EXAMPLE 1: WAYS TO USE MULTIVARIRNG

int main(){
    // USING NORMALLY WITH CONSTRUCTOR
    Eigen::Matrix3d covar = Eigen::MatrixXd::Zero(3,3);
    Eigen::Vector3d mean = Eigen::MatrixXd::Zero(3,1);
    MultiVariRNG<Eigen::Vector3d,Eigen::Matrix3d> mvrng(mean,covar);

    for(size_t i = 0; i<100; i++){
        std::cout << "\n" << mvrng.MVRNGenerate() << "\n" << std::endl;
    }

    std::cout << "\n ---------------------------- \n";

    // USING WITH POINTER AND CONSTRUCTOR WITH "new"
    Eigen::Matrix4d covar2 = Eigen::MatrixXd::Zero(4,4);
    Eigen::Vector4d mean2 = Eigen::MatrixXd::Zero(4,1);

    MultiVariRNG<Eigen::Vector4d,Eigen::Matrix4d>* mvrng_ptr
     = new MultiVariRNG< Eigen::Vector4d,Eigen::Matrix4d >(mean2,covar2);

    for(size_t i = 0; i<100; i++){
        std::cout << "\n" << mvrng_ptr->MVRNGenerate() << "\n" << std::endl;
    }

    return 0;
}