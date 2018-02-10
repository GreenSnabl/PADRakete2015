/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snbl
 *
 * Created on February 10, 2018, 1:46 PM
 */

#include "Rakete.h"
#include "Tank.h"
#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::vector;


Tank choose_tank(const vector<Tank>& tanks)
{
    int input = -1;
    Tank tank;
    double fuellung = -1;
    while (input > tanks.size() || input < 1){
    cout << "Welchen Tank möchten Sie hinzufügen?\nZur Auswahl stehen:\n\n";
    for (int i = 0; i < tanks.size(); ++i)
    {
        cout << i + 1 << "\n";
        tanks[i].print();
    }
    cout << "0. Abbrechen\n?>";
    cin >> input;
    if (input >= 1 && input <= tanks.size()){
        tank = tanks[input-1];

        while(fuellung > 100 || fuellung < 0){
        cout << "Zu wieviel Prozent soll der Tank gefüllt sein? (0-100)\n?> ";
        cin >> fuellung;
        }
        tank.set_fuellstand(fuellung);
        return tank;
    }
    }   
}
Triebwerk choose_triebwerk(vector<Triebwerk> triebwerke)
{
    int input = -1;
    while (input > triebwerke.size() || input < 1){
    cout << "Welches Triebwerk möchten Sie hinzufügen?\nZur Auswahl stehen:\n\n";
    for (int i = 0; i < triebwerke.size(); ++i)
    {
        cout << i + 1 << "\n";
        triebwerke[i].print();
    }
    cout << "0. Abbrechen\n?>";
    cin >> input;
    if (input >= 1 && input <= triebwerke.size())
        return triebwerke[input-1];
    }   
}


int main(int argc, char** argv) {

    vector<Tank> tanks = {Tank("Kleiner Treibstofftank", 1, 20, 100, TREIBSTOFF),
                        Tank("Kleiner Nutzlastcontainer", 1, 10, 100, NUTZLAST),
                        Tank("Mittlerer Treibstofftank", 3, 80, 100, TREIBSTOFF),
                        Tank("Grosser Nutzlastcontainer", 5, 100, 100, NUTZLAST),
                        Tank("Großer Treibstofftank", 5, 200, 100, TREIBSTOFF)   
    };
    
    vector<Triebwerk> triebwerke = {Triebwerk("LVT-30", 2000, 0.5, 2.5),
                                    Triebwerk("LVT-80", 10000, 1.5, 10.5),
                                    Triebwerk("LVT-45", 3500, 0.75, 4)
    };
    Rakete rakete;
    char input;
    while (input != 'x') {
    cout << "1. Tankliste ausgeben\n"
         << "2. Triebwerksliste ausgeben\n"
         << "3. Rakete anzeigen\n"
         << "4. Tank hinzufügen\n"
         << "5. Triebwerk hinzufügen\n"
         << "x. Beenden\n"
         << "?> ";
    cin >> input;
    switch(input)
    {
        case '1': 
            for(int i = 0; i < tanks.size(); ++i) {
                tanks[i].print();
                cout << "\n";
            }break;
        case '2': 
            for (int i = 0; i < triebwerke.size(); ++i) {           
                triebwerke[i].print(); 
                cout << "\n";
            }break;
        case '3': rakete.print(); break;
        case '4': rakete.einfuegen(choose_tank(tanks)); break;
        case '5': rakete.einfuegen(choose_triebwerk(triebwerke)); break; 
    }
    }
    
    return 0;
}

