/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tank.h
 * Author: snbl
 *
 * Created on February 10, 2018, 1:54 PM
 */

#ifndef TANK_H
#define TANK_H
#include <string>

enum Tankart {TREIBSTOFF, NUTZLAST};

class Tank {
public:
    Tank();
    Tank(std::string m_name, double m_leergewicht, double m_volumen, double m_fuellstand, Tankart m_art);
    Tank(const Tank&);
    ~Tank();
    const double get_gesamtgewicht() const;
    const double get_fuellgewicht() const;
    void set_fuellstand(double);
    void print() const;
        
private:
    const std::string art_to_string() const;

    

    
    std::string name;
    double leergewicht;
    double volumen;
    double fuellstand;
    Tankart art;
};

#endif /* TANK_H */

