export module Rectangle;

import Std;
import Shape;

export namespace GeometricShapes
{
    export class Rectangle : public Shape {
    private:
        double m_width;
        double m_height;
        Point m_position; //top-left point
    public:

        Rectangle(std::string_view name,double x, double y, double width, double height);
        virtual ~Rectangle() = default;

        void setWidth(double width);
        void setHeight(double height);
        void setPosition(double x, double y);

        double getWidth() const;
        double getHeight() const;
        Point getPosition() const;

        double getArea() const override;
        double getPerimeter() const override;
        Point getCentroid() const override;
        double getMomentOfInertia() const override;

        static Rectangle createSquare(std::string_view name, double side);
    };
}
