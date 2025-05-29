//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ)
: x(inX),
  y(inY),
  z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

//Subtraktion: this - input
Vektor Vektor::sub(const Vektor& input) const
{
	return Vektor(x - input.x,
				  y - input.y,
				  z - input.z);
}

//Länge des Vektors
double Vektor::laenge() const
{
	return std::sqrt(x*x + y*y + z*z);
}

//Skalarprodukt
double Vektor::skalarProd(const Vektor& input) const{
	return x*input.x + y*input.y + z*input.z;
}

//Winkel in Grad zwischen diesem Vektor und input
double Vektor::winkel(const Vektor& input) const
{
    double len1 = laenge();
    double len2 = input.laenge();
    if (len1 == 0.0 || len2 == 0.0)
        return 0.0;

    double cosW = skalarProd(input) / (len1 * len2);
    cosW = std::fmax(-1.0, std::fmin(1.0, cosW));  // Stabilisierung
    double rad = std::acos(cosW);
    const double PI = std::acos(-1.0);
    return rad * 180.0 / PI;
}

// Rotation um die z-Achse (in-place)
void Vektor::rotiereUmZ(const double rad)
{
    double c = std::cos(rad);
    double s = std::sin(rad);
    double x_new = x * c - y * s;
    double y_new = x * s + y * c;
    x = x_new;
    y = y_new;
    // z bleibt gleich
}

// Getter
double Vektor::getX() const { return x; }
double Vektor::getY() const { return y; }
double Vektor::getZ() const { return z; }
