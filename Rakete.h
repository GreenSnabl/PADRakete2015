/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rakete.h
 * Author: snbl
 *
 * Created on February 10, 2018, 2:11 PM
 */

#ifndef RAKETE_H
#define RAKETE_H
#include <vector>
#include "Triebwerk.h"
#include "Tank.h"

class Rakete {
public:
    Rakete();
    ~Rakete();
    const double get_gesamtverbrauch() const;
    const double get_fuellgewicht() const;
    void print();
    void einfuegen(Triebwerk);
    void einfuegen(Tank);
    
private:

    double berechneGewicht();
    double berechneTWR();
    double berechneBrenndauer();
    
    std::vector<Triebwerk> triebwerke;
    std::vector<Tank> tanks;
};

#endif /* RAKETE_H */

