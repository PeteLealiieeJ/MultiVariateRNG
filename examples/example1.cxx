#include <MultiVariRNG.h>
#include <Eigen/Dense>

// EXAMPLE 1: WAYS TO USE MULTIVARIRNG

int main(){

    std::cout << "\n ---------------------------- Start Double \n";

    // USING NORMALLY WITH CONSTRUCTOR
    Eigen::Matrix3d covar = Eigen::MatrixXd::Ones(3,3);
    Eigen::Vector3d mean = Eigen::MatrixXd::Zero(3,1);
    MultiVariRNG<Eigen::Vector3d,Eigen::Matrix3d> mvrng(mean,covar);

    for(size_t i = 0; i<100; i++){
        std::cout << "\n" << mvrng.MVRNGenerate() << "\n" << std::endl;
    }

    std::cout << "\n ---------------------------- Start Float \n";

    // USING WITH FLOAT MATRIX
    Eigen::Matrix3f covarf = Eigen::MatrixXf::Ones(3,3);
    Eigen::Vector3f meanf = Eigen::MatrixXf::Zero(3,1);
    MultiVariRNG<Eigen::Vector3f,Eigen::Matrix3f> mvrngf(meanf,covarf);

    for(size_t i = 0; i<100; i++){
        std::cout << "\n" << mvrngf.MVRNGenerate() << "\n" << std::endl;
    }

    std::cout << "\n ---------------------------- Start 4dim \n";

    // USING WITH POINTER AND CONSTRUCTOR WITH "new"
    Eigen::Matrix4d covar2 = Eigen::MatrixXd::Ones(4,4);
    Eigen::Vector4d mean2 = Eigen::MatrixXd::Zero(4,1);

    MultiVariRNG<Eigen::Vector4d,Eigen::Matrix4d>* mvrng_ptr
     = new MultiVariRNG< Eigen::Vector4d,Eigen::Matrix4d >(mean2,covar2);

    for(size_t i = 0; i<100; i++){
        std::cout << "\n" << mvrng_ptr->MVRNGenerate() << "\n" << std::endl;
    }

    return 0;
}