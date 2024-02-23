#ifndef ELEMENT_CST_H
#define ELEMENT_CST_H

#include "Element.H"

namespace Element
{
class CST : public Element<2,3,1>
{
public:
    using Element<2,3,1>::Element;

    std::array<double,3> eta(Eigen::Vector2d Y) override
    {
        std::array<double,3> ret;

        // TODO - Copy implementation from PS03

        return ret;
    }

    std::array<Eigen::Vector2d,3> Deta(Eigen::Vector2d Y) override
    {
        std::array<Eigen::Vector2d,3> ret;

        // TODO - Copy implementation from PS03

        return ret;
    }

public:
    //
    // These are utility functions 
    //
    virtual const std::array<Eigen::Vector2d,3> & getY0() {return Y0;}
    virtual const std::array<Eigen::Vector2d,1> & getQp() {return Qp;}
    virtual const std::array<double,1> & getQw() {return Qw;}
    virtual const double getArea() {
        // Todo: return the area of the template element.
    }

private:
    //
    // Hard-coded values common to all elements
    //

    const std::array<Eigen::Vector2d,3> Y0 = {
        Eigen::Vector2d(0.0,0.0),
        Eigen::Vector2d(1.0,0.0),
        Eigen::Vector2d(0.0,1.0)
    };

    const std::array<Eigen::Vector2d,1> Qp = {
        // TODO: Create quadrature points (vectors) here
    };

    const std::array<double,1> Qw = {
        // TODO: list quadrature weights (scalars) here
    };


public:
    
};

}
#endif
