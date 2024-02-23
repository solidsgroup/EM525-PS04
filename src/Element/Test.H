#ifndef ELEMENT_TEST_H
#define ELEMENT_TEST_H
#include "Util/Exception.H"
#include "Element/Element.H"
namespace Element
{
//
// This is a suite of tesing functions to determine whether Elements are
// coded properly.
//
template<class ELEMENT>
class Test
{
private:

    //
    // [function Element::Test<ELEMENT>::Default()]
    //
    // Static utility function (not for general use)
    // to generate a "default" element, where the 
    // embedded position is the same as the template position.
    //
    static ELEMENT Default()
    {
        ELEMENT tmp;
        std::array<Eigen::Vector2d,ELEMENT::_N> X0;
        for (int n = 0 ; n < ELEMENT::_N; n++)
        {
            X0[n] = Eigen::Vector2d::Zero();
            for (int d = 0; d < ELEMENT::_D; d++)
                X0[n](d) = tmp.getY0()[n](d);
        }
        return ELEMENT(X0);
    }

    //
    // [function RandomPointInElement]
    //
    // Static utility function (not for general use)
    // that produces a random vector in template space that is
    // guaranteed to be within the element, as long as the
    // element is convex.
    //
    static Eigen::Vector2d RandomPointInElement(ELEMENT &elem)
    {
        double sum = 0.0;
        const int N = ELEMENT::_N;
        std::array<double,N> lamb;
        for (int n = 0; n < N; n++) lamb[n] = (float)rand();
        for (int n = 0; n < N; n++) sum += lamb[n];
        for (int n = 0; n < N; n++) lamb[n] /= sum;
        auto Y0 = elem.getY0();
        Eigen::Vector2d Y = Eigen::Vector2d::Zero();
        for (int n = 0; n < N; n++) Y += lamb[n] * Y0[n];
        return Y;
    }    


public:

    //
    // [function Dirac]
    //
    // Test the shape function property that
    //
    // eta_i(y_j) = delta_{ij}
    //
    // where y_j are the element points and eta
    // are the shape functions.
    //
    static void Dirac()
    {
        ELEMENT elem = Default();
        auto Y0 = elem.getY0();
        int N = Y0.size();

        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < N; m++)
            {
                if (n==m && fabs(elem.eta(Y0[n])[m] - 1.0) > 1E-8)
                    throw Util::Exception::UnitTest(
                        "Dirac test failed: n="+std::to_string(n) +
                        " m=" + std::to_string(m) + 
                        "eta^m(y^n) = " + std::to_string(elem.eta(Y0[n])[m]) + " != 1.0");
                if (n!=m && fabs(elem.eta(Y0[n])[m] - 0.0) > 1E-8)
                    throw Util::Exception::UnitTest(
                        "Dirac test failed: n="+std::to_string(n) +
                        " m=" + std::to_string(m) + 
                        " eta^m(y^n) = " + std::to_string(elem.eta(Y0[n])[m]) + " != 0.0" );
            }
        }
     }

    //
    // [function SumToUnity]
    //
    // This is a test to guarantee that the shape functions all
    // sum to one at any random point within the element.
    //
    static void SumToUnity()
    {
        ELEMENT elem = Default();
        int N = ELEMENT::_N;

        for (int iter = 0; iter < 100; iter++)
        {
            Eigen::Vector2d Y = RandomPointInElement(elem);
            double sum = 0.0;
            for (int n = 0; n < N; n++) sum += elem.eta(Y)[n];
            if (fabs(sum-1.0) > 1E-8)
            {
                throw Util::Exception::UnitTest("SumToUnity test failed: sum=" + std::to_string(sum) +
                                  " for Y = [" + std::to_string(Y(0)) + ", " + std::to_string(Y(1)) + "]");
            }
        }
     }


    static void Quadrature()
    {
        ELEMENT elem = Default();
        const int N = ELEMENT::_N;
        const int Q = ELEMENT::_Q;

        double Aexact = elem.getArea();
        std::array<Eigen::Vector2d,Q> qp = elem.getQp();
        std::array<double,Q> qw = elem.getQw();

        double Anumerical = 0.0;
        for (int q = 0; q < Q; q++)
            for (int n = 0; n < N; n++)
            {
                Anumerical += qw[q] * elem.eta(qp[q])[n];
            }
        if (fabs(Aexact-Anumerical) > 1E-8)
            throw Util::Exception::UnitTest("Quadrature error: Aexact = " + std::to_string(Aexact) +
                              ", Anumerical = " + std::to_string(Anumerical));
    }


    //
    // [function EtaDerivative]
    //
    // This function checks to make sure the eta derivatives
    // have been computed properly.
    //
    static void EtaDerivative()
    {
        ELEMENT elem = Default();
        int N = ELEMENT::_N;
        int D = ELEMENT::_D;
    
        srand((unsigned)(time(NULL)));
        double small = 1E-8;
        double tolerance = 1E-4;

        for (int iter = 0; iter < 100; iter++)
        {
            Eigen::Vector2d Y = RandomPointInElement(elem);

            auto deta_exact = elem.Deta(Y);
            for (int d = 0 ; d < D; d++)
            {
                Eigen::Vector2d dy = Eigen::Vector2d::Zero();
                dy(d) = small;

                for (int n = 0; n < N; n++)
                {
                    double exact = deta_exact[n](d);
                
                    double numerical = (elem.eta(Y+dy)[n] - elem.eta(Y)[n])/small;

                    double diff = exact-numerical;
                    double norm = std::max(exact+numerical,1.0);
                    if (fabs(diff/norm) > tolerance)
                        throw Util::Exception::UnitTest("Element::Test::EtaDerivative failed for node " 
                                                        + std::to_string(n) + ", error = "
                                                        + std::to_string(fabs(diff)));
                }
            }
        }
    }

};
}
#endif 
