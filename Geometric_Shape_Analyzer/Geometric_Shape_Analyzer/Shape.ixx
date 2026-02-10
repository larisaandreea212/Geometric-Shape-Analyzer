module;
#include <string>
#include <string_view>
#include <stdexcept>
#include <format>
#include <iostream>


export module Shape;

export namespace GeometricShapes
{
	struct Point {
		double x, y;
	};

	class Shape {
	protected:
		std::string m_name;

	public:
		Shape(std::string_view name):m_name(name) {}
		virtual ~Shape() {}
		Shape(const Shape&) = delete;
		Shape& operator=(const Shape&) = delete;
		Shape(Shape&&) = default;
		Shape& operator=(Shape&&) = default;

		std::string_view getName() const
		{
			return m_name;
		}
		
		void setName(std::string_view name)
		{
			if (name.empty())
				throw std::invalid_argument("Shape name cannot be empty");
			else
				m_name = name;
		}

		virtual double getArea() const = 0;
		virtual double getPerimeter() const = 0;
		virtual Point getCentroid() const = 0;

		void PrintInfo() const
		{
			Point c = getCentroid();
			std::string output = std::format(
				"------------------------------------------\n"
				"Analiza Forma: {}\n"
				">Arie:                     {:.2f} unitati^2\n"
				">Perimetru:                  {:.2f} unitati\n"
				">Centru de greutate:     X={:.2f),  Y={:.2f}\n",
				getName(),
				getArea(),
				getPerimeter(),
				c.x, c.y
			);
			std::cout << output;
		}
	};
}
