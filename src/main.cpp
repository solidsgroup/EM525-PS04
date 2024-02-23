#include <iostream>
#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/Dense"
#include "Element/CST.H"
#include "Element/LST.H"
#include "Element/Q4.H"
#include "Element/Q9.H"
#include "Element/Test.H"

namespace Set
{
using Scalar = double;            // Note that "Set::Scalar" is the same as double
using Vector = Eigen::Vector2d;   // Note that "Set::Vector" is the same as Eigen::Vector2d
using Matrix = Eigen::Matrix2d;   // Note that "Set::Matrix" is the same as Eigen::Matrix2d
}

int main(int argc, char **argv)
{

    //
    // CST Tests
    //
    
    std::cout << "test.element.cst.diractest...";
    try {Element::Test<Element::CST>::Dirac(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.cst.sumtounitytest...";
    try {Element::Test<Element::CST>::SumToUnity(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.cst.etaderivativetest...";
    try {Element::Test<Element::CST>::EtaDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.cst.quadrature...";
    try {Element::Test<Element::CST>::Quadrature(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    //
    // LST Tests
    //
    
    std::cout << "test.element.lst.diractest...";
    try {Element::Test<Element::LST>::Dirac(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.lst.sumtounitytest...";
    try {Element::Test<Element::LST>::SumToUnity(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.lst.etaderivativetest...";
    try {Element::Test<Element::LST>::EtaDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.lst.quadrature...";
    try {Element::Test<Element::LST>::Quadrature(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    //
    // Q4 Tests
    //
    
    std::cout << "test.element.q4.diractest...";
    try {Element::Test<Element::Q4>::Dirac(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.q4.sumtounitytest...";
    try {Element::Test<Element::Q4>::SumToUnity(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.q4.etaderivativetest...";
    try {Element::Test<Element::Q4>::EtaDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.q4.quadrature...";
    try {Element::Test<Element::Q4>::Quadrature(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    //
    // Q9 Tests
    //
    
    std::cout << "test.element.q9.diractest...";
    try {Element::Test<Element::Q9>::Dirac(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.q9.sumtounitytest...";
    try {Element::Test<Element::Q9>::SumToUnity(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.q9.etaderivativetest...";
    try {Element::Test<Element::Q9>::EtaDerivative(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    std::cout << "test.element.q9.quadrature...";
    try {Element::Test<Element::Q9>::Quadrature(); std::cout <<"pass"<<std::endl;}
    catch(Util::Exception::UnitTest e) {std::cout << "failed:" << std::endl << e.what() << std::endl;}

    //
    // TODO: Jacobian Test:
    //
    //       Test your implementation of the Jacobian by
    //       calculating the Jacobian for the embedded CST in
    //       the example in the notes. 
    // 
    {
        // This is an array containing the embedded points.
        std::array<Eigen::Vector2d,3> X0;
        //X0[0] = Eigen::Vector2d(todo, todo); // Uncomment these lines and put in
        //X0[1] = Eigen::Vector2d(todo, todo); // the coordinates of the points.
        //X0[2] = Eigen::Vector2d(todo, todo); // 

        // This creates a CST element with the coordinates specified above.
        Element::CST element(X0);

        // Eigen::Vector2d Y(todo, todo) // Uncomment and put in the coordinates of a test point;

        // Uncomment this line to print out the Jacobian
        // std::cout << element.Jacobian(Y) << std::endl; 
    }
}
