#include <MultiVariRNG.h>
#include <vector>

// CHECKING/PROVING COVARIANCE TRANSFORM

int main(){

    int nsamp = 10000;

    Eigen::Matrix3d covar;

    // SAMPLE COVARIANVE FROM UNNAMED SIMULATED SENSOR
    covar << 3.74594018895874e-05,	1.07418247112003e-05,	-6.33235754470261e-06,
            1.07418247112003e-05,	0.000115064443419884	,-4.66088712363351e-05,
            -6.33235754470261e-06,	-4.66088712363351e-05,	6.34761546905283e-05;

    Eigen::Vector3d mean{1,2,3};
    MultiVariRNG<Eigen::Vector3d,Eigen::Matrix3d> mvrng(mean,covar);

    std::vector<Eigen::Vector3d> ppl;

    Eigen::Vector3d vecSum = Eigen::MatrixXd::Zero(3,1);

    for(size_t i = 0; i<nsamp; i++){
        Eigen::Vector3d randVec = mvrng.MVRNGenerate();
        ppl.push_back( randVec );
        vecSum += randVec;
    }

    Eigen::Vector3d vecMean = vecSum/ppl.size();

    std::cout << "Ouput Mean: \n" << vecMean << "\n" << std::endl;

    Eigen::Matrix3d sigmaSum = Eigen::MatrixXd::Zero(3,3);

    for(size_t i = 0; i<ppl.size(); i++){
        sigmaSum += (ppl[i]-vecMean)*( (ppl[i]-vecMean).adjoint() );
    }

    Eigen::Matrix3d Sigma =  sigmaSum/(ppl.size()-1);

    std::cout << "Ouput Covariance: \n" << Sigma << std::endl;

    return 0;
    

}