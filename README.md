Geometric Shape Analyzer (C++20)
A high-performance engineering tool designed to analyze geometric structural properties using Modern C++.
This project demonstrates the transition from legacy C++ headers to C++20 Modules, utilizing advanced OOP concepts and memory safety features to simulate material proprierties for structural engineers.

Key features:
*Technical Implementation
  C++ Modules: Full separation of Interface ('.ixx') and Implementation ('.cpp') for faster compilation and strict encapsulation.
  Smart Pointers: Usage of 'std::unique_ptr' and 'std::vector' for RAII-compliant memory management (No 'new/delete').
  Polymorphism: Robust Virtual Method hierarchy for treating  heterogeneous shapes uniformly.
  Strict Validation: "Smart Setters" that prevent invalid geometric states (e.g. collinear points for triangles).
  Standard Library: Utilization of '<format>', '<numbers>' (pi), and '<algorithm>'.

*Engineering & Math Logic
  Structural Analysus: Calculates area, perimeter and centroid for arbitrary shapes.
  Physiscs Simulation: Moment of Inertia calculation for Circle and Triangle to simulate bending resistance.
                       Material Weight Estimation: Simulates steel density for mass calculation.
  Coordinate Systems: Shapes are defined i a global Cartesian coordinate system (2D space).

*How to build 
  Prerequisites: Visual Studio 2022 (v17.0 or later), Desktop developement with C++ workload

*Steps:
1. Clone the repository
2. Open '.sln' file in Visual Studio
3. Right-click on Project->Properties->C++ Language Standard:'ISO C++20 Standard (/std:c++20)'
                                     ->Scan Sources for Module Dependencies: 'Yes'
4. Build and Run

*Exemple Output:
===================================================
   GEOMETRIC SHAPE ANALYZER v1.0 (Engine: C++20)
===================================================

Rulare Analiza Structurala...
------------------------------------------
Analiza Forma: Placa Baza Otel
>Arie:                     5000.00 unitati^2
>Perimetru:                  300.00 unitati
>Centru de greutate:     X=50.00,  Y=25.00

------------------------------------------
Analiza Forma: Teava Principala
>Arie:                     314.16 unitati^2
>Perimetru:                  62.83 unitati
>Centru de greutate:     X=50.00,  Y=25.00
   [i] Moment Inertie (Rezistenta la incovoiere): 7853.98 cm^4

------------------------------------------
Analiza Forma: Guseu Rigidizare
>Arie:                     600.00 unitati^2
>Perimetru:                  120.00 unitati
>Centru de greutate:     X=10.00,  Y=13.33
   [!] NOTA INGINER: Acesta este un Triunghi Dreptunghic (Optim pentru colturi).

===================================================
                RAPORT FINAL
===================================================
 > Suprafata Totala Material:   5914.16 cm^2
 > Lungime Taiere (Perimetru):  482.83 cm
---------------------------------------------------
 > ESTIMARE GREUTATE (Otel):    46.43 kg
===================================================
