module Shape;

import Std;

namespace GeometricShapes 
{
    Shape::Shape(std::string_view name): m_name(name){}

    std::string_view Shape::getName() const
    {
        return m_name;
    }

    void Shape::setName(std::string_view name)
    {
        if (name.empty())
            throw std::invalid_argument("Shape name cannot be empty");
        else
            m_name = name;
    }

    void Shape::PrintInfo() const
    {
        Point c = getCentroid();
        std::string output = std::format(
            "------------------------------------------\n"
            "Analiza Forma: {}\n"
            ">Arie:                     {:.2f} unitati^2\n"
            ">Perimetru:                  {:.2f} unitati\n"
            ">Centru de greutate:     X={:.2f},  Y={:.2f}\n",
            getName(),
            getArea(),
            getPerimeter(),
            c.x, c.y
        );
        std::cout << output;
    }
}
