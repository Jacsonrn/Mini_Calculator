#include <iostream>
#include "bigint.h"

using namespace std;

int main(void)
{
  BigInt BI;
  int i;

  cout << "CONFIRA SE AS SEQUENCIAS GERADAS PELO PROGRAMA ESTAO CORRETAS, "
       << "especialmente nas transicoes:\n"
       << "De 0 para +1 ou -1\t"
       << "De -1 ou +1 para 0\n"
       << "De +127 para +128\t"
       << "De -128 para -129\n";

  cout << "\nIncremento pre-fixado:\n";
  cout << "I01 (de -129 a 130):\t";
  BI = -130;
  for (i=0; i<260; i++)
  {
    cout << ++BI << ' ';
  }
  cout << endl;


  cout << "\nDecremento pre-fixado:\n";
  cout << "I02 (de 129 a -130):\t";
  BI = 130;
  for (i=0; i<260; i++)
  {
    cout << --BI << ' ';
  }
  cout << endl;

  //
  // OPERADORES POS-FIXADOS
  //

  cout << "\nIncremento pos-fixado:\n";
  cout << "I03 (de -130 a 129):\t";
  BI = -130;
  for (i=0; i<260; i++)
  {
    cout << BI++ << ' ';
  }
  cout << endl;

  cout << "\nDecremento pos-fixado:\n";
  cout << "I04 (de 130 a -129):\t";
  BI = 130;
  for (i=0; i<260; i++)
  {
    cout << BI-- << ' ';
  }
  cout << endl;

  return 0;
}

