/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rakete.cpp
 * Author: snbl
 * 
 * Created on February 10, 2018, 2:11 PM
 */

#include "Rakete.h"
#include <iostream>

using std::cout; using std::endl;


Rakete::Rakete() {
}


Rakete::~Rakete() {
}

void Rakete::einfuegen(Triebwerk triebwerk)
{
    triebwerke.push_back(triebwerk);
}

void Rakete::einfuegen(Tank tank)
{
    tanks.push_back(tank);
}

double Rakete::berechneGewicht()
{
    double gewicht = 0;
    for (int i = 0; i < tanks.size(); ++i)
    {
        gewicht += tanks[i].get_gesamtgewicht();
    }
    for (int i = 0; i < triebwerke.size(); ++i)
    {   
        gewicht += triebwerke[i].get_gewicht();
    }
    return gewicht;
}

double Rakete::berechneTWR()
{
    double schub = 0;
    if (berechneGewicht() == 0) return 0;
    for (int i = 0; i < triebwerke.size(); ++i)
    {
        schub += triebwerke[i].get_schub();    
    }
    return schub * 1000 / (berechneGewicht() * 9.807);
}

const double Rakete::get_gesamtverbrauch() const
{
    double verbrauch = 0;
    for (int i = 0; i < triebwerke.size(); ++i)
    {
        verbrauch += triebwerke[i].get_verbrauch();
    }
    return verbrauch;
}

const double Rakete::get_fuellgewicht() const
{
    double fuellgewicht = 0;
    for (int i = 0; i < tanks.size(); ++i)
    {
        fuellgewicht += tanks[i].get_fuellgewicht();    
    }
    return fuellgewicht;
}


double Rakete::berechneBrenndauer()
{
    if (get_gesamtverbrauch() == 0) return 0;
    return get_fuellgewicht() / get_gesamtverbrauch();
}

void Rakete::print()
{
    cout << "Gesamtgewicht: " << berechneGewicht() << "kg\n"
         << "TWR: " << berechneTWR() << "\n"
         << "Brenndauer: " << berechneBrenndauer() << "s\n\n";
    for (int i = 0; i < tanks.size(); ++i)
    {
        tanks[i].print();
        cout << endl;
    }
    for (int i = 0; i < triebwerke.size(); ++i)
    {
        triebwerke[i].print();
        cout << endl;
    }
}