/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Triebwerk.h
 * Author: snbl
 *
 * Created on February 10, 2018, 1:48 PM
 */

#ifndef TRIEBWERK_H
#define TRIEBWERK_H

#include <string>


class Triebwerk {
public:
    Triebwerk(std::string m_name, double m_schub, double m_verbrauch, double m_gewicht);
    ~Triebwerk();
    
    const double get_verbrauch() const;
    const double get_schub() const;
    const double get_gewicht() const;
    void print();
private:
    

        
    std::string name;
    double schub;
    double verbrauch;
    double gewicht;
    
};

#endif /* TRIEBWERK_H */

