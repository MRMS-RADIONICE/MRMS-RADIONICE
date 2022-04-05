#pragma once
#include "helper.h"

void RobotLine::radionica() {
    // Priprema robota za praćenje zida
    if (setup()){
        armOpen();
    }
    
    // Prioritet stavljen na praćenje linije
    if (lineAny()){
        // Priprema robota za praćenje linije
        armClose();
        
        // Zaustavlja robota na cilju koji je označen s crnim trokutom i 3 zida
        if (front() > 160 and front() < 200 and frontLeft() < 120 and frontRight() < 120){
            stop();
            end();
        }       
        
        // Prepoznaje raskrižje i skreće udesno
        if (line(0) and line(8)){
            go(70, -70);
            delayMs(600);
        }
        // Praćenje linije
        else
            lineFollow();
    }
    
    // Ako nema linije robot prati zid
    else
    {
        // Priprema robota za praćenje zida
        armOpen();
        
        // Prioritet stavljen na praćenje zida s lijeve strane
        if (frontLeft() < 200)
        {   
            if (front() < 130){
                go(70, -70);
                delayMs(600);
            }
            if (frontLeft() < 100){
                go(70, 30);   
            }
            else
                go(30, 70);
        }
        
        // Praćenje zida s desne strane
        else if(frontRight() < 200)
        {
            if (front() < 130){
                go(-70, 70);
                delayMs(600);
            }
            if (frontRight() < 100){
                go(30, 70);
            }
            else
                go(70, 30);    
        }
        
        // Ako nevidi zid ni s jedne strane robot ide ravno
        else
            go(60, 60);
    }
}


/*
Ponavljanje pračenje linije, pračenje zida i korištenje servo motora. 
Naglasak na sljedećim naredbama: 
    --> go();
    --> delayMs();
    --> lineFollow();
    --> frontLeft();
    --> frontRight();
    --> front();
Cilj: Preći s pračenja linije na pračenje zida i nazad
*/
