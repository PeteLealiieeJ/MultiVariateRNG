# MultiVariateRNG
 Multi-Variate Random Number Generator to generate random numbers with the same multi-variate normal distribution contained in an Eigen Matrix. Developed primarily for producing simulated noise in UT Robotics Simulations. Note that this Repo is HEADER ONLY and doesn't need to be built.

 # Dependencies 
 1. [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)

# Proof and Explaination
If you are unfamillar with the process of transforming a mutually independent standard normal distributed sample, from population x, to 
a sample y whose population will represent a desired covaiance relationship (or Matrix) and would like to see the theories that this 
Repo. works on, see [ProofExplain.pdf](ProofExplain.pdf)

# Utilitization
Again, this Repo's inner-workings are HEADER ONLY, primarily due to the templating method implemented for universal application. Utilizing the 
repo itself is simple and linking this Repository's CmakeLists with yours (although it's unnessesary) will add the class as a library interface. Most questions can be answered by looking in the examples folder which has a CMakeList and example implementation and operating proofs which show its 
accuracy. Personally, I use this repo as a submodule of my sensor simulation repositories. BEST OF LUCK!!!
