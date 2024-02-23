#ifndef ELEMENT_LST_H
#define ELEMENT_LST_H

#include "Element.H"

namespace Element
{
class LST : public Element<2,6,4>
{
public:
    using Element<2,6,4>::Element;

    std::array<double,6> eta(Eigen::Vector2d Y) override
    {
        std::array<double,6> ret;

        // TODO - Copy implementation from PS03

        return ret;
    }

    std::array<Eigen::Vector2d,6> Deta(Eigen::Vector2d Y) override
    {
        std::array<Eigen::Vector2d,6> ret;

        // TODO - Copy implementation from PS03
        
        return ret;
    }

public:
    virtual const std::array<Eigen::Vector2d,6> & getY0() {return Y0;}
    virtual const std::array<Eigen::Vector2d,4> & getQp() {return Qp;}
    virtual const std::array<double,4> & getQw() {return Qw;}
    virtual const double getArea() {
        // TODO - return the area of the template element
    }

private:
    //
    // Hard-coded values common to all elements
    //

    const std::array<Eigen::Vector2d,6> Y0 = {
        Eigen::Vector2d(0.0,0.0),
        Eigen::Vector2d(0.5,0.0),
        Eigen::Vector2d(1.0,0.0),
        Eigen::Vector2d(0.5,0.5),
        Eigen::Vector2d(0.0,1.0),
        Eigen::Vector2d(0.0,0.5)
    };

    const std::array<Eigen::Vector2d,4> Qp = {
        // TODO: Create quadrature points (vectors) here
    };

    const std::array<double,4> Qw = {
        // TODO: list quadrature weights (scalars) here
    };


public:
    
    static const int vtkid = 5;
    
    template<class DERIVED> friend void EnergyDerivativeTest();
    };

}
#endif
