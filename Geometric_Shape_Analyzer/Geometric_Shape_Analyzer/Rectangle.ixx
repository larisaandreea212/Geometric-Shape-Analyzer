export module Rectangle;

#include <string>
#include <string_view>
import Shape;


export namespace GeometricShapes
{
	export class Rectangle : public Shape {
	private:
		double m_width;
		double m_height;

	public:

		Rectangle(std::string_view name, double width, double height);
		virtual ~Rectangle() = default;

		void setWidth(double width);
		void setHeight(double height);

		double getWidth() const;
		double getHeight() const;

		double getArea() const override;
		double getPerimeter() const override;
		Point getCentroid() const override;
		double getMomentOfInertia() const;

		static Rectangle createSquare(std::string_view name, double side);
	};
}
