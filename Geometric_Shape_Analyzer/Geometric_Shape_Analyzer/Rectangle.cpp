module Rectangle;

#include <string>
#include <string_view>
#include <stdexcept>
import Shape;


export namespace GeometricShapes {
	Rectangle::Rectangle(std::string_view name, double width, double height)
		:Shape(name),
		m_width(width),
		m_height(height){
	if(width<=0 || height<=0)
		throw std::invalid_argument("Dimensiunile trebuie sa fie pozitive!");
	}
	void Rectangle::setWidth(double width)
	{
		if(width<=0)
			std::invalid_argument("Latimea trebuie sa fie pozitiva.")
		m_width = width;
	}
	void Rectangle::setHeight(double height)
	{
		if (height <= 0)
			std::invalid_argument("Lungimea trebuie sa fie pozitiva.")
		m_height = height;
	}
	double Rectangle::getWidth() const
	{
		return m_width;
	}
	double Rectangle::getHeight() const
	{
		return m_height;
	}
	double Rectangle::getArea() const
	{
		return m_width*m_height;
	}
	double Rectangle::getPerimeter() const
	{
		return 2*(m_width+m_height);
	}
	Point Rectangle::getCentroid() const
	{
		return { m_width / 2.0, m_height / 2.0 };
	}
	///De intrebat dudusorul
	double Rectangle::getMomentOfInertia() const
	{
		return (m_width * std::pow(m_height, 3)) / 12.0;
	}
	Rectangle Rectangle::createSquare(std::string_view name, double side)
	{
		return Rectangle(name,side,side );
	}
}