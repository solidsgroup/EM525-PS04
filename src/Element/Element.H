#ifndef ELEMENT_ELEMENT_H
#define ELEMENT_ELEMENT_H
#include "eigen3/Eigen/Core"
#include <time.h>

namespace Element
{
template<int D, int N, int Q>
class Element
{
public:

    Element()
    {}
                
    Element(std::vector<Eigen::Vector2d> &a_X0, std::array<int,N> a_id) :
        X0(&a_X0), id(a_id)
    {}

    Element(std::array<Eigen::Vector2d,N> &a_X0) 
    {
        X0 = new std::vector<Eigen::Vector2d>();
        for (int n = 0 ; n < N ; n++)
        {
            X0->push_back(a_X0[n]);
            id[n] = n;
        }
    }

    virtual std::array<double,N> eta(Eigen::Vector2d y) = 0;

    virtual std::array<Eigen::Vector2d,N> Deta(Eigen::Vector2d y) = 0;

    Eigen::Matrix2d Jacobian(Eigen::Vector2d Y)
    {
        // TODO Calculate the Jacobian
        
        // This line creates a zero-valued jacobian matrix --
        // your job is to fill it.
        Eigen::Matrix2d jacobian = Eigen::Matrix2d::Zero();

        // This line calculates the eta derivatives 
        // The components are indexed by:
        //    deta^m / dx^n = deta[m](n)
        // 
        std::array<Eigen::Vector2d,N> deta = Deta(Y);

        //
        // Use this loop to calculate the components of the jacobian matrix.
        // 
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int n = 0 ; n < N ; n++)
                {
                    // Notes:
                    //   - to get the "ij"th component of the jacobian use
                    //        jacobian(i,j)
                    //   - to access the "i"th component of the "n"th X0 use
                    //        (*X0)[n](i)
                }
        return jacobian;
    }

public:
    constexpr int getN() {return N;}
    virtual const std::array<Eigen::Vector2d,N> & getY0() = 0;
    virtual const std::array<Eigen::Vector2d,Q> & getQp() = 0;
    virtual const std::array<double,Q> & getQw() = 0;
    virtual const double getArea() = 0;
    virtual const std::array<int,N> & getid() {return id;};

    static const int _D = D; // The DIMENSION of the space (2d or 3d)
    static const int _N = N; // The number of NODES in the element
    static const int _Q = Q; // The number of QUADRATURE POINTS in the element

private:
    std::vector<Eigen::Vector2d> *X0;
    std::array<int,N> id;

public:

    static const int vtkid = 0;

};



}
#endif
