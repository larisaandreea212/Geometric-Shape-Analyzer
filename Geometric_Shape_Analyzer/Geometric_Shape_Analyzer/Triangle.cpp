module Triangle;

import Std;
import Shape;

const double EPSILON = 0.001;

namespace GeometricShapes
{
    double Triangle::distance(Point a, Point b)
    {
        return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
    }

    bool Triangle::arePointsCollinear(Point p1, Point p2, Point p3)
    {
        double val = 0.5 * std::abs(
            p1.x * (p2.y - p3.y) +
            p2.x * (p3.y - p1.x) +
            p3.x * (p1.y - p2.y)
        );
        return val < 0.0001;
    }

    Triangle::Triangle(std::string_view name, double x1, double y1, double x2, double y2, double x3, double y3)
        : Shape(name)
    {
        Point p1{ x1, y1 };
        Point p2{ x2, y2 };
        Point p3{ x3, y3 };

        if (arePointsCollinear(p1, p2, p3)) {
            throw std::invalid_argument("Punctele sunt coliniare la constructie!");
        }

        m_p1 = p1;
        m_p2 = p2;
        m_p3 = p3;
    }

    Point Triangle::getP1() const { return m_p1; }
    Point Triangle::getP2() const { return m_p2; }
    Point Triangle::getP3() const { return m_p3; }

    void Triangle::setP1(Point p)
    {
        if (arePointsCollinear(p, m_p2, m_p3))
            throw std::invalid_argument("Punct invalid. Ar face punctele coliniare!");
        m_p1 = p;
    }

    void Triangle::setP2(Point p)
    {
        if (arePointsCollinear(m_p1, p, m_p3))
            throw std::invalid_argument("Punct invalid. Ar face punctele coliniare!");
        m_p2 = p;
    }

    void Triangle::setP3(Point p)
    {
        if (arePointsCollinear(m_p1, m_p2, p))
            throw std::invalid_argument("Punct invalid. Ar face punctele coliniare!");
        m_p3 = p;
    }

    double Triangle::getArea() const
    {
        return 0.5 * std::abs(
            m_p1.x * (m_p2.y - m_p3.y) +
            m_p2.x * (m_p3.y - m_p1.y) + 
            m_p3.x * (m_p1.y - m_p2.y));
    }

    double Triangle::getPerimeter() const
    {
        return distance(m_p1, m_p2) + distance(m_p2, m_p3) + distance(m_p3, m_p1);
    }

    Point Triangle::getCentroid() const
    {
        return {
            (m_p1.x + m_p2.x + m_p3.x) / 3.0,
            (m_p1.y + m_p2.y + m_p3.y) / 3.0
        };
    }

    bool Triangle::isRightAngled() const
    {
        std::vector<double> sides;
        
        sides.push_back(distance(m_p1, m_p2));
        sides.push_back(distance(m_p2, m_p3));
        sides.push_back(distance(m_p3, m_p1));

        std::sort(sides.begin(), sides.end());  

        double a2 = std::pow(sides[0], 2);
        double b2 = std::pow(sides[1], 2);
        double c2 = std::pow(sides[2], 2);

        return std::abs((a2 + b2) - c2) < EPSILON;
    }
    bool Triangle::isEquilateral() const
    {
        
        double ab = distance(m_p1, m_p2);
        double bc = distance(m_p2, m_p3);
        double ca = distance(m_p3, m_p1);

        return std::abs(ab - bc) < EPSILON && std::abs(bc - ca) < EPSILON;

    }


    double Triangle::getMomentOfInertia() const {
        double side1 = distance(m_p1, m_p2);
        double side2 = distance(m_p2, m_p3);
        double side3 = distance(m_p3, m_p1);

        double base = std::max({ side1, side2, side3 });

        double area = getArea();

        double height = (2.0 * area) / base;

        return (base * std::pow(height, 3)) / 36.0;
    }
}