/*
fichier entierlong.h
pour définir le type EntierLong
*/

#ifndef ENTIER_LONG_H
#define ENTIER_LONG_H

const int MAXCHIFFRES = 20;

typedef int tabEnt[MAXCHIFFRES];

struct EntierLong
{
    bool Negatif;
    tabEnt Chiffres;
};

#endif
