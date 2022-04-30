#pragma once
#include "helper.h"

void RobotLine::radionica() {
  // Uvođenje varijable lopta s kojom mijenjamo ponašanje robota ovisno dali drži robot loptu ili ne
  static bool lopta;
  if (setup()) {
    lopta = false;
    armOpen();
  }

  // Ukoliko robot NE nosi loptu ponašat će se prema sljedećim naredbama
  if (lopta == false) {
    if (lineAny()) {
      // Priprema robota za praćenje linije
      armClose();

      // Prepoznavanje raskrižja koji označava pronalazak lopte
      if (line(8) and line(4) and front() > 200) {
        catchBall();
        lopta = true;
      }

      // Praćenje linije
      lineFollow();
    }
    else {
      // Priprema robota za praćenje zida
      armOpen();

      // Praćenje zida
      wallFollowLeft();
      wallFollowRight();
      
    }
  }

  // Ukoliko robot NOSI loptu ponašat će se prema sljedećim naredbama
  else {
    if (lineAny()) {
      // Prepozavanje raskrižja gdje robot ostavlja loptu
      if (line(8) and line(0) and front() < 200) {
        stop();
        armDrop();
        delayMs(80);
        end();
      }

      // Praćenje linije
      lineFollow();
    }
    else {
      // Praćenje zida dok drži loptu u gripperu
      wallFollowRightCarry();
      wallFollowLeftCarry();
    }
  }
}


void RobotLine::wallFollowRight() {
  // Praćenje zida s desne strane
  if (frontRight() < 200)
  {
    if (front() < 130) {
      go(-120, 120);        // Skretanje u lijevu stranu
      delayMs(300);
    }
    if (frontRight() < 100) {
      go(80, 120);
    }
    else
      go(120, 80);
  }
  else
    go(110, 110);
}

void RobotLine::wallFollowLeft() {
  // Praćenje zida s lijeve strane
  if (frontLeft() < 300)
  {
    if (front() < 130) {
      go(120, -120);        // Skretanje u desnu stranu
      delayMs(300);
    }
    if (frontLeft() < 100) {
      go(120, 80);
    }
    else
      go(80, 120);
  }
  else
    go(110, 110);
}

void RobotLine::catchBall() {
  // Rutina za hvatanje lopte
  stop();
  delayMs(50);
  armCatchReady();        // Priprema grippera za hvatanje

  go(70, 70);             // Polako prilaženje loptici
  delayMs(1700);
  go(50, 50);
  delayMs(800);

  armCatch();             // Hvatanje loptice
  stop();
  delayMs(10);

  go(-80, -80);           // Izlazak iz zone čuvanja loptice vožnjom unazad
  delayMs(1400);
  stop();
  delayMs(50);

  go(85, -85);            // Okretanje u mjestu za 180°
  delayMs(1100);
  stop();
  delayMs(40);

  go(90, 90);             // Prelazak raskrižja
  delayMs(200);

  stop();
  delayMs(10);
  armCarry();
  delayMs(10);
}


/*
        OVAJ DIO MORAJU SAMI NAPRAVITI
*/
void RobotLine::wallFollowRightCarry() {
  // Praćenje zida s desne strane nakon hvatanja lopte
  if (frontRight() < 250)
  {
    if (front() < 130) {
      go(-120, 120);        // Skretanje u lijevu stranu
      delayMs(600);
    }
    if (frontRight() < 220) {
      go(80, 120);
    }
    else
      go(120, 80);
  }
}

void RobotLine::wallFollowLeftCarry() {
  // Praćenje zida s lijeve strane nakon hvatanja lopte
  if (frontLeft() < 250)
  {
    if (front() < 130) {
      go(-120, 120);        // Skretanje u lijevu stranu
      delayMs(600);
    }
    if (frontLeft() < 220) {
      go(120, 70);
    }
    else
      go(80, 120);
  }
  else 
    go(50, 120);
}
