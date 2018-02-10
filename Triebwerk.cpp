/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Triebwerk.cpp
 * Author: snbl
 * 
 * Created on February 10, 2018, 1:48 PM
 */

#include "Triebwerk.h"
#include <iostream>

using std::cout; using std::endl;

Triebwerk::Triebwerk(std::string m_name, double m_schub, double m_verbrauch, double m_gewicht) : name {m_name}, schub {m_schub}, verbrauch {m_verbrauch}, gewicht {m_gewicht} {}

Triebwerk::~Triebwerk() {
}

const double Triebwerk::get_schub() const
{
    return schub;
}


const double Triebwerk::get_gewicht() const
{
    return gewicht;
}

const double Triebwerk::get_verbrauch() const
{
    return verbrauch;
}

void Triebwerk::print()
{
    cout << "Name: " << name << "\n"
         << "Gewicht: " << gewicht << " kg\n"
         << "Schub: " << schub << " kN\n"
         << "Verbrauch: " << verbrauch << "kg/sec\n";
}


