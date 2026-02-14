export module Circle;

import Std;
import Shape;

export namespace GeometricShapes
{
    export class Circle : public Shape {
    private:
        Point m_center;
        double m_radius;
    public:

        Circle(std::string_view name, double x, double y, double radius);
        virtual ~Circle() = default;

        void setRadius(double radius);
        void setCenter(double x, double y);

        double getRadius() const;
        Point getCenter() const;

        double getArea() const override;
        double getPerimeter() const override;
        Point getCentroid() const override;
        double getMomentOfInertia() const override;

    };
}
