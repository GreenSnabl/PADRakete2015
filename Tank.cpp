/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tank.cpp
 * Author: snbl
 * 
 * Created on February 10, 2018, 1:54 PM
 */

#include "Tank.h"
#include <iostream>

using std::cout; using std::endl;

Tank::Tank() : 
name {""}, leergewicht{0}, volumen {0}, fuellstand {0}, art {TREIBSTOFF} {}

Tank::Tank(std::string m_name, double m_leergewicht, double m_volumen, double m_fuellstand, Tankart m_art) :
    name {m_name}, leergewicht{m_leergewicht}, volumen {m_volumen}, fuellstand {m_fuellstand}, art {m_art}
{
}
    
Tank::Tank(const Tank& tank) : 
    name {tank.name}, leergewicht{tank.leergewicht}, volumen{tank.volumen}, fuellstand{tank.fuellstand}, art {tank.art}
    {
    }
    
Tank::~Tank() {
}

const std::string Tank::art_to_string() const
{
    if (art == TREIBSTOFF)
    return "Treibstoff";
    else return "Nutzlast";
}

const double Tank::get_fuellgewicht() const 
{
    if (art == TREIBSTOFF)
        return volumen * fuellstand / 100;
    else return 0;
}



const double Tank::get_gesamtgewicht() const
{
    return leergewicht + get_fuellgewicht();
}

void Tank::set_fuellstand(double fuellung)
{
    if (fuellung >= 0 && fuellung <= 100) fuellstand = fuellung;
}


void Tank::print() const
{
  cout << "Name: " << name << "\n"
       << "Art: " << art_to_string() << "\n"
       << "Leergewicht: " << leergewicht << " kg\n"
       << "Volumen: " << volumen << "\n"
       << "Fuellstand: " << fuellstand << "%\n"
       << "Gesamtgewicht: " << get_gesamtgewicht() << endl;
}
