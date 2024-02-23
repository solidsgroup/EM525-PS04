#ifndef ELEMENT_Q4_H
#define ELEMENT_Q4_H

#include "Element.H"

namespace Element
{
class Q4 : public Element<2,4,4>
{
public:
    using Element<2,4,4>::Element;

    std::array<double,4> eta(Eigen::Vector2d Y) override
    {
        std::array<double,4> ret;

        // TODO - Copy implementation from PS03

        return ret;
    }

    std::array<Eigen::Vector2d,4> Deta(Eigen::Vector2d Y) override
    {
        std::array<Eigen::Vector2d,4> Deta;

        // TODO - Copy implementation from PS03

        return Deta;
    }

public:
    virtual const std::array<Eigen::Vector2d,4> & getY0() {return Y0;}
    virtual const std::array<Eigen::Vector2d,4> & getQp() {return Qp;}
    virtual const std::array<double,4> & getQw() {return Qw;}
    virtual const double getArea() {
        // TODO: return the area of the template element
    }

private:
    //
    // Hard-coded values common to all elements
    //

    const std::array<Eigen::Vector2d,4> Y0 = {
        Eigen::Vector2d(-1.0,-1.0),
        Eigen::Vector2d(1.0,-1.0),
        Eigen::Vector2d(1.0,1.0),
        Eigen::Vector2d(-1.0,1.0)
    };

    static constexpr double sq3 = sqrt(3.);
    const std::array<Eigen::Vector2d,4> Qp = {
        // TODO - create quadrature points (vectors).
    };

    const std::array<double,4> Qw = {
        // TODO - create quadrature weights (scalars)
    };


public:
    
    static const int vtkid = 5;
};

}
#endif
