#include "entierlong.h"
#include "lit_ecrit.h"
#include "utilitaires.h"
#include "operations.h"

#include <iostream>
using namespace std;

int main() {
  int nA=0, nB=0;
  cout << "Entrez les nombres voulus" << endl;
  cin >> nA; cin >> nB;
  
  EntierLong n1, n2;
  n1 = int2entierLong(nA);
  n2 = int2entierLong(nB);

  //cout << "|n1| <= |n2| ?  " << comparaison_absolue(n1,n2) << endl;

  cout << "n1 : "; AfficheEntierLong(n1);
  cout << "n2 : "; AfficheEntierLong(n2);

  //cout << "n1-n2 = " ; AfficheEntierLong(sousSig(n1,n2));
  //cout << "n1+n2 = "; AfficheEntierLong(addEL(n1,n2));
  //cout << endl << "n1-n2 = ";
  //AfficheEntierLong(soustractionEL(n1,n2));
  //cout << endl << "n1*n2 = ";
  //AfficheEntierLong(multiplication(n1,n2));
  cout << "Division euclidienne de n1 par n2 : ";
  AfficheEntierLong(Division(n1,n2));

  cout << "Division euclidienne de n1 par n2 : ";
  AfficheEntierLong(divEucli(n1,n2));
  

  return 0;
}