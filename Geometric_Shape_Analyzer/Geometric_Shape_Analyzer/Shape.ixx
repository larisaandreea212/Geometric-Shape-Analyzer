export module Shape;

export import <string>;
export import <string_view>;

export namespace GeometricShapes
{
    struct Point { double x, y; };

    export class Shape {
    protected:
        std::string m_name;

    public:
        Shape(std::string_view name);
        virtual ~Shape() = default;
        Shape(const Shape&) = delete;
        Shape& operator=(const Shape&) = delete;
        Shape(Shape&&) = default;
        Shape& operator=(Shape&&) = default;

        std::string_view getName() const;
        void setName(std::string_view name);

        virtual double getArea() const = 0;
        virtual double getPerimeter() const = 0;
        virtual Point getCentroid() const = 0;

        virtual double getMomentOfInertia() const { return 0.0; }

        void PrintInfo() const;
    };
}
