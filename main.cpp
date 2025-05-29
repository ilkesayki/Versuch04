//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{

    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);

    std::cout << "Vektor 1:" << std::endl;
    vector1.ausgabe();

    std::cout << "Vektor 2:" << std::endl;
    vector2.ausgabe();

    std::cout << "Länge von Vektor 1: " << vector1.laenge() << std::endl;
    std::cout << "Skalarprodukt: " << vector1.skalarProd(vector2) << std::endl;
    std::cout << "Winkel zwischen Vektor 1 und 2: " << vector1.winkel(vector2) << " Grad" << std::endl;

    Vektor differenz = vector1.sub(vector2);
    std::cout << "Differenz Vektor (Vektor1 - Vektor2):" << std::endl;
    differenz.ausgabe();

    std::cout << "Rotation von Vektor 1 um Z-Achse um 90 Grad:" << std::endl;
    vector1.rotiereUmZ(M_PI / 2);
    vector1.ausgabe();

    // Erd- und Beobachterdaten
    constexpr double ERD_RADIUS = 6371000.0;  	// in Meter
    const double plattformH     = 555.7;        // in Meter
    const double koerperH       = 1.70;         // in Meter
    const double H              = (plattformH + koerperH); //Gesamthöhe in Meter

    // Zähler für die Anzahl der Berechnungsschritte
       int anzahlSchritte = 0;


    // Beobachterposition E
    Vektor E(ERD_RADIUS + H, 0.0, 0.0);


    // Brute-Force-Methode: Wir testen alle möglichen Winkel in kleinen Schritten
    const double startWinkel = 0.0;      // Startwinkel in Grad
    const double endWinkel = 5.0;        // Endwinkel in Grad (realistischer Bereich)
    const double schrittGroesse = 0.000000573; // Schrittgröße in Grad (çok daha küçük adımlar)

    double beta = 0.0;  // Direkt die Variable für den endgültigen Winkel verwenden

    // Durchlaufen aller möglichen Winkel
    for (double testWinkel = startWinkel; testWinkel <= endWinkel; testWinkel += schrittGroesse)
    {
    	anzahlSchritte++;

    // Winkel in Radiant für die Rotation
    double winkelRad = testWinkel * M_PI / 180.0;

    // Punkt auf der Erdoberfläche berechnen
    Vektor punktAufErde(ERD_RADIUS, 0.0, 0.0);
    punktAufErde.rotiereUmZ(winkelRad);

    // Vektor vom Erdmittelpunkt zum Punkt
    Vektor radius(punktAufErde);

    // Vektor vom Punkt zum Beobachter
    Vektor sichtlinie = E.sub(punktAufErde);

    // Winkel zwischen Radius und Sichtlinie
    double winkel = radius.winkel(sichtlinie);

    // Abweichung vom 90-Grad-Winkel berechnen
    double abweichung = std::abs(winkel - 90.0);

    // Aktuellen Winkel als besten speichern
    beta = testWinkel;

    // Wenn die Abweichung klein genug ist, brechen wir ab
    if (abweichung < 0.000001)
    {
    	break;
    }
    }

    // Distanz berechnen (kein besterWinkel mehr nötig)
    double distanz = beta * M_PI / 180.0 * ERD_RADIUS;
    double distanz_km = distanz / 1000.0;


    // Formatierte Ausgabe der Ergebnisse
       std::cout << std::fixed << std::setprecision(4) << std::endl;
       std::cout << "Ergebnisse:" << std::endl;
       std::cout << "Sie koennen " << distanz_km << " Km weit sehen." << std::endl;
       std::cout << "Sie sind " << (plattformH + koerperH) << " Meter hoch." << std::endl;
       std::cout << "Der Winkel betraegt " << beta << " Grad." << std::endl;
       std::cout << "Anzahl Schritte: " << anzahlSchritte << std::endl;






    return 0;

}
