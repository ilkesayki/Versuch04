//
// Praktikum Informatik 1
//
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

#ifndef Vektor_H
#define Vektor_H

#include <iostream>
#include <cmath>
#include <iomanip>

class Vektor
{
   public:
    Vektor(double x, double y, double z);
    ~Vektor();

    void ausgabe() const; //Ekrana yazdırma
    Vektor sub(const Vektor& input) const; // Vektör çıkarma
    double laenge() const; // Uzunluk hesabı
    double skalarProd(const Vektor& input) const; // Skaler çarpım
    double winkel(const Vektor& input) const; //in Grad
    void rotiereUmZ(const double rad); //in Rad

    double getX() const;	// x bileşeni
    double getY() const;	// y bileşeni
    double getZ() const;	// z bileşeni


   private:
    double x;
    double y;
    double z;

};

#endif
