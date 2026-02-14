module Circle;

import Std;
import Shape;

namespace GeometricShapes
{
    Circle::Circle(std::string_view name, double x, double y, double radius) :
        Shape(name), m_center({ x,y }), m_radius(radius)
    {
        if (radius <= 0) {
            throw std::invalid_argument("Raza cercului trebuie sa fie pozitiva!");
        }
    }

    double Circle::getRadius() const { return m_radius; }
    Point Circle::getCenter() const { return m_center; }

    double Circle::getArea() const
    {
        return std::numbers::pi * std::pow(m_radius, 2);
    }

    double Circle::getPerimeter() const
    {
        return 2 * std::numbers::pi * m_radius;
    }

    Point Circle::getCentroid() const
    {
        return m_center;
    }

    double Circle::getMomentOfInertia() const
    {
        return (std::numbers::pi * std::pow(m_radius, 4)) / 4.0;
    }

    void Circle::setRadius(double radius) {
        if (radius <= 0) throw std::invalid_argument("Raza trebuie pozitiva!");
        m_radius = radius;
    }

    void Circle::setCenter(double x, double y) {
        m_center.x = x;
        m_center.y = y;
    }
}