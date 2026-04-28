#include <iostream>
#include "bigint.h"

using namespace std;

int main(void)
{
  BigInt A,B;

  cout << "CONFIRA SE OS RESULTADOS CALCULADOS PELO PROGRAMA ESTAO CORRETOS\n";

  // Testando multiplicacao

  // Envolvendo nulos
  cout << "\nI01:\n";

  A = 0;
  B = 0;
  cout << "(" << A << ")*(" << B << ")="<< A*B << endl;
  A = 0;
  B = 123;
  cout << "(" << A << ")*(" << B << ")="<< A*B << endl;
  A = 123;
  B = 0;
  cout << "(" << A << ")*(" << B << ")="<< A*B << endl;
  A = 0;
  B = -123;
  cout << "(" << A << ")*(" << B << ")="<< A*B << endl;
  A = -123;
  B = 0;
  cout << "(" << A << ")*(" << B << ")="<< A*B << endl;

  // Sem nulos
  cout << "\nI02:\n";

  // Dois numeros nao negativos, sem carry
  A = 1000;
  B = 98765;
  cout << "(" << A << ")*(" << B << ")="<< A*B << endl;
  // Dois numeros nao negativos, com carry
  A = 1234;
  B = 98765;
  cout << "(" << A << ")*(" << B << ")="<< A*B << endl;
  // Dois numeros negativos
  A = -1234;
  B = -98765;
  cout << "(" << A << ")*(" << B << ")="<< A*B << endl;
  // Primeiro numero nao negativo, segundo negativo
  A = 1234;
  B = -98765;
  cout << "(" << A << ")*(" << B << ")="<< A*B << endl;
  // Primeiro numero negativo, segundo nao negativo
  A = -1234;
  B = 98765;
  cout << "(" << A << ")*(" << B << ")="<< A*B << endl;

  // Testando fatorial
  cout << "\nI03:\n";

  A = -100;
  cout << "(" << A << ")!=" << !A << endl;
  A = -1;
  cout << "(" << A << ")!=" << !A << endl;
  A = 0;
  cout << "(" << A << ")!=" << !A << endl;
  A = 1;
  cout << "(" << A << ")!=" << !A << endl;
  A = 10;
  cout << "(" << A << ")!=" << !A << endl;
  A = 100;
  cout << "(" << A << ")!=" << !A << endl;
  A = 1000;
  cout << "(" << A << ")!=" << !A << endl;

  // Testando que o construtor a partir de string nao eh conversor
  cout << "\nI04: Deve gerar um erro de compilacao.\n";
  cout << "O programa soh deve compilar se voce comentar a proxima linha.\n";
  // A = B * string("1000");

  return 0;
}
