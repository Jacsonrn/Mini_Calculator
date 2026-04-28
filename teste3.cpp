#include <iostream>
#include <limits>
#include "bigint.h"

using namespace std;

int main(void)
{
  string msg[] = {
    "<ENTER><ENTER><TAB><TAB><espaco><espaco>12",
    "z",
    "-",
    "+",
    "-0",
    "0000",
    "0075",
    "-0075",
    "123z",
    "Nao vai esperar digitar, pois vai processar o que ficou da digitacao anterior",
    "32-16",
    "Nao vai esperar digitar, pois vai processar o que ficou da digitacao anterior",
    "1 2 3",
    "Nao vai esperar digitar, pois vai processar o que ficou da digitacao anterior",
    "Nao vai esperar digitar, pois vai processar o que ficou da digitacao anterior",
    "+123456789012345678901234567890",
    "-123456789012345678901234567890"
  };
  string result[] = {
    "12",
    "0, com msg de erro antes",
    "0, com msg de erro antes",
    "0, com msg de erro antes",
    "0",
    "0",
    "75",
    "-75",
    "123",
    "0, com msg de erro antes",
    "32",
    "-16",
    "1",
    "2",
    "3",
    "123456789012345678901234567890",
    "-123456789012345678901234567890"
  };

  BigInt BI;
  double x;

  cout << "Digite<espaco><espaco>321.25\n";
  cin >> BI >> x;
  cout << "I1: deve imprimir BI=321 x=0.25\n";
  cout << "BI=" << BI << " x=" << x << endl;

  for (int i=0; i<17; ++i) // I2 ateh I18
  {
    cout << "\nDigite " << msg[i] << endl;
    cout << "> ";
    cin >> BI;
    cout << "I" << i+2 << ": Deve imprimir BI=" << result[i] << endl;
    if (cin.fail())
    {
      cin.clear(); // Limpa o estado de erro
      cout << "Erro na leitura! ";
      // Para ler e descartar tudo que foi digitado ateh o proximo ENTER,
      // incluindo o que gerou erro.
      string nada;
      getline(cin,nada);
    }
    cout << "BI=" << BI << endl;
  }

  return 0;
}

