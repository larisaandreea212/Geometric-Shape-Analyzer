export module Triangle;

import Std;
import Shape;

export namespace GeometricShapes
{
    export class Triangle : public Shape {
    private:
        Point m_p1;
        Point m_p2;
        Point m_p3;

        static double distance(Point a, Point b);
        static bool arePointsCollinear(Point p1, Point p2, Point p3);

    public:

        Triangle(std::string_view name,
            double x1, double y1,
            double x2, double y2, 
            double x3, double y3);
        virtual ~Triangle() = default;

        Point getP1() const;
        Point getP2() const;
        Point getP3() const;

        void setP1(Point p);
        void setP2(Point p);
        void setP3(Point p);

        double getArea() const override;
        double getPerimeter() const override;
        Point getCentroid() const override;
        double getMomentOfInertia() const override;
        bool isRightAngled() const;
        bool isEquilateral() const;

    };
    
}
