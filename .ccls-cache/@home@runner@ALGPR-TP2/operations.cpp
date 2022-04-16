#include "operations.h"
#include "lit_ecrit.h"
#include <cmath> 
#include <iostream>

EntierLong addSig(const EntierLong &n1, const EntierLong &n2) {
  EntierLong n;

  // On assume qu'ils sont du même signe, on prend le signe de l'un
  n.Negatif = n1.Negatif;

  // Et on ajoute les différents chiffres
  int retenue = 0, modulo, addChiffre;
  for (int i = 0; i<MAXCHIFFRES; i++) {
    addChiffre = n1.Chiffres[i]+n2.Chiffres[i]+retenue;
    
    retenue = addChiffre/10;
    n.Chiffres[i] = addChiffre%10;
  }
  return n;
}

EntierLong sousSig(const EntierLong &a, const EntierLong &b){
  EntierLong c = int2entierLong(0);
  c.Negatif = a.Negatif;
  
  for (int i = 0; i<MAXCHIFFRES; i++){
    if (a.Chiffres[i] >= b.Chiffres[i]){
      c.Chiffres[i] = c.Chiffres[i]+a.Chiffres[i] - b.Chiffres[i];
    }
    else {
      c.Chiffres[i] = 10 - (b.Chiffres[i]-a.Chiffres[i]);
      c.Chiffres[i+1] = -1;
    }
  }
  return c;
}

EntierLong addEL( EntierLong n1,  EntierLong n2) {
  if (n1.Negatif == n2.Negatif) {
    return addSig(n1, n2);
  }
  else {
    EntierLong nTemp;
    // SI |n1|<=|n2|
    if (comparaison_absolue(n1, n2)) {
      nTemp = n1; nTemp.Negatif = !nTemp.Negatif;
      EntierLong n = sousSig(n2, nTemp);
      return n;
    }
    else {
      nTemp = n2; nTemp.Negatif = !nTemp.Negatif;
      return sousSig(n1, nTemp);
    }
  }
}


EntierLong soustractionEL(const EntierLong &a, const EntierLong &b) {
  EntierLong c;
  if(a.Negatif == b.Negatif){
    if (comparaison_absolue(b,a)){
      return sousSig(a,b);
      }
    else{
      c = sousSig(b,a);
      c.Negatif = !c.Negatif;
      return c;
    }
  }
  else{                           //a<0 et b>0
    c=b;
    c.Negatif = !c.Negatif;
    return addSig(a,c);
  }
}


//------------------------------------------------

EntierLong multiplication(const EntierLong &a, const EntierLong &b){
  EntierLong c = int2entierLong(0);
  int produit;
  
  // Valeur absolue du résultat
  for (int i=0; i<MAXCHIFFRES; i++){
    for (int j=0; j<MAXCHIFFRES; j++){
      produit = a.Chiffres[j]*b.Chiffres[i];
      c = addEL(c,int2entierLong(produit*pow(10,i+j)));
    }
  }

  // Signe du résultat
  if (a.Negatif == b.Negatif){
    c.Negatif = false;
  }
  else{
    c.Negatif = true;
  }
  
  return c;
}

//------------------------------------------------------

EntierLong Division(const EntierLong &a, const EntierLong &b){
  int i=0;
  while (comparaison_absolue(multiplication(b,int2entierLong(i)),a)){
    i = i + 1;
  }
  return int2entierLong(i-1); 
}

//---------------------------------------------------------------

EntierLong divEucli(const EntierLong &a, const EntierLong &b) {
  EntierLong resultat = int2entierLong(0);
  EntierLong un = int2entierLong(1);

  EntierLong n1, n2, reste; // Entier Grand, Petit, reste
  n2 = a; reste = b;
  bool compare;
  int i = 0;
  do {
    // Plus grand, plus petit
    compare = comparaison_absolue(n2, reste);
    n1 = (compare) ? reste : n2;
    n2 = (compare) ? n2 : reste;

    // Calcul du reste
    reste = soustractionEL(n1, n2);
    std::cout << i << " - ";
    AfficheEntierLong(reste);
    resultat = addEL(resultat, un);
    i++;
  } while (!comparaison_absolue(reste, soustractionEL(b, un)) && !egalite(reste, int2entierLong(0)) && i<500);
  
  return resultat;
}