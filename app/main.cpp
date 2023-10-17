// ref: https://github.com/thedancomplex/cpp-boilerplate

#include <string>
#include <iostream>
#include <Eigen/Dense>

int main()
{
	Eigen::Matrix3d M = Eigen::Matrix3d::Random();
	M = (M + Eigen::Matrix3d::Constant(1.2)) * 50;

	std::cout << "M = " << std::endl << M << std::endl;

	Eigen::Vector3d v(1, 2, 3);
	std::cout << "M*v = " << std::endl << M * v << std::endl;
    return 0;
}
