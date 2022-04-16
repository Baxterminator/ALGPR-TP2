#include "entierlong.h"
#include <iostream>
#include <cmath>
using namespace std;

EntierLong int2entierLong(int n) {
  EntierLong nlong;
  int actu, chiffre;

  // Test négatif
  nlong.Negatif = n<0;
  actu = (n<0) ? -n : n;
  cout << "Hello";

  // Conversion des chiffres
  for (int i = MAXCHIFFRES-1; i>=0; i--) {
    chiffre = actu/(pow(10,i));
    nlong.Chiffres[i] = chiffre;
    actu = actu - chiffre*(10^i);
  }
  return nlong;
}

//---------------------------------------------------

//Test d'égalité entre deux entiers longs

bool egalite(EntierLong a, EntierLong b){
  if (a.Negatif == b.Negatif){
    for (int i=0; i<MAXCHIFFRES; i=i+1){
      if (a.Chiffres[i] != b.Chiffres[i]){
        return false;
      }
    }
    return true;
  }
}

//-------------------------------------------------------

bool comparaison_absolue(EntierLong a, EntierLong b){
  int i=MAXCHIFFRES;
  while (a.Chiffres[i]==b.Chiffres[i]) {
    i=i-1;
  }
  return (a.Chiffres[i] <= b.Chiffres[i] );
}
