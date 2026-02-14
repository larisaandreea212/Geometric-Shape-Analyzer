import Std;
import Shape;
import Rectangle;
import Circle;
import Triangle;

using namespace GeometricShapes;

int main()
{
    try {
        std::cout << "===================================================\n";
        std::cout << "   GEOMETRIC SHAPE ANALYZER v1.0 (Engine: C++20)   \n";
        std::cout << "===================================================\n\n";

       
        std::vector<std::unique_ptr<Shape>> shapes;

        shapes.push_back(std::make_unique<Rectangle>("Placa Baza Otel", 0.0, 0.0, 100.0, 50.0));
        shapes.push_back(std::make_unique<Circle>("Teava Principala", 50.0, 25.0, 10.0));
        shapes.push_back(std::make_unique<Triangle>("Guseu Rigidizare", 0.0, 0.0, 30.0, 0.0, 0.0, 40.0));

        double totalArea = 0.0;
        double totalPerimeter = 0.0;

        const double DENSITY_STEEL = 7.85; 
        const double THICKNESS = 1.0;      

        std::cout << "Rulare Analiza Structurala...\n";

        for (const auto& shape : shapes) {
            shape->PrintInfo();

            totalArea += shape->getArea();
            totalPerimeter += shape->getPerimeter();

            if (auto* tri = dynamic_cast<Triangle*>(shape.get())) {
                if (tri->isRightAngled()) {
                    std::cout << "   [!] NOTA INGINER: Acesta este un Triunghi Dreptunghic (Optim pentru colturi).\n";
                }
            }

            if (auto* circ = dynamic_cast<Circle*>(shape.get())) {
                std::cout << std::format("   [i] Moment Inertie (Rezistenta la incovoiere): {:.2f} cm^4\n",
                    circ->getMomentOfInertia());
            }

            std::cout << "\n";
        }

        double totalWeight = totalArea * THICKNESS * DENSITY_STEEL / 1000.0; // in kg

        std::cout << "===================================================\n";
        std::cout << "                RAPORT FINAL                       \n";
        std::cout << "===================================================\n";
        std::cout << std::format(" > Suprafata Totala Material:   {:.2f} cm^2\n", totalArea);
        std::cout << std::format(" > Lungime Taiere (Perimetru):  {:.2f} cm\n", totalPerimeter);
        std::cout << "---------------------------------------------------\n";
        std::cout << std::format(" > ESTIMARE GREUTATE (Otel):    {:.2f} kg\n", totalWeight);
        std::cout << "===================================================\n";

    }
    catch (const std::exception& ex) {
        std::cerr << "\n[EROARE CRITICA]: " << ex.what() << "\n";
        return -1;
    }

    return 0;
}