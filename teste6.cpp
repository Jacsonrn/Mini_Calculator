#include <iostream>
#include "bigint.h"

using namespace std;

int main(void)
{
  BigInt A,B;
  BigInt BI0(0), BI1(1), BIm1(-1),
         BIbig(1234567890), BImbig(-1234567890);

  cout << "CONFIRA SE OS RESULTADOS CALCULADOS PELO PROGRAMA ESTAO CORRETOS\n\n";

  // Teste do valor absoluto
  cout << "\nI01:\t";
  cout << "BI=" << BI0 << " abs(BI)=" << abs(BI0) << " \t "
       << "BI=" << BI1 << " abs(BI)=" << abs(BI1) << " \t "
       << "BI=" << BIm1 << " abs(BI)=" << abs(BIm1) << " \t "
       << "BI=" << BIbig << " abs(BI)=" << abs(BIbig) << " \t "
       << "BI=" << BImbig << " abs(BI)=" << abs(BImbig) << endl;

  // Testando positivo e negativo
  cout << "\nI02:\t";
  A = 0;
  cout << "+(" << A << ")=" << +A << " -(" << A << ")=" << -A << " \t ";
  A = 1;
  cout << "+(" << A << ")=" << +A << " -(" << A << ")=" << -A << " \t ";
  A = -1;
  cout << "+(" << A << ")=" << +A << " -(" << A << ")=" << -A << endl;

  // Testando adicao
  cout << "\nI03:\t";

  // Envolvendo nulos
  A = 0;
  B = 0;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  A = 0;
  B = 123;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  A = 123;
  B = 0;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  A = 0;
  B = -123;
  cout << "(" << A << ")+(" << B << ")=" << A+B << " \t ";
  A = -123;
  B = 0;
  cout << "(" << A << ")+(" << B << ")="<< A+B << endl;

  cout << "\nI04:\t";

  // Dois numeros nao negativos
  // Mesmo numero de digitos, sem carry
  A = 234;
  B = 765;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Mesmo numero de digitos, com carry
  A = 666;
  B = 345;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Numero diferente de digitos, sem carry
  A = 1;
  B = 998;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Numero diferente de digitos, com carry
  A = 998;
  B = 28;
  cout << "(" << A << ")+(" << B << ")="<< A+B << endl;

  cout << "\nI05:\t";

  // Dois numeros negativos
  // Mesmo numero de digitos, sem carry
  A = -234;
  B = -765;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Mesmo numero de digitos, com carry
  A = -666;
  B = -345;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Numero diferente de digitos, sem carry
  A = -1;
  B = -998;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Numero diferente de digitos, com carry
  A = -998;
  B = -28;
  cout << "(" << A << ")+(" << B << ")="<< A+B << endl;

  cout << "\nI06:\t";

  // Primeiro numero nao negativo, segundo numero negativo
  // Modulo do primeiro maior ou igual que o do segundo
  // Mesmo numero de digitos, sem carry
  A = 765;
  B = -234;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Mesmo numero de digitos, com carry
  A = 645;
  B = -366;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Mesmo numero de digitos, iguais
  A = 765;
  B = -765;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Numero diferente de digitos, sem carry
  A = 998;
  B = -1;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Numero diferente de digitos, com carry
  A = 926;
  B = -68;
  cout << "(" << A << ")+(" << B << ")="<< A+B << endl;

  cout << "\nI07:\t";

  // Primeiro numero nao negativo, segundo numero negativo
  // Modulo do primeiro menor que o do segundo
  // Mesmo numero de digitos
  A = 265;
  B = -734;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Numero diferente de digitos
  A = 98;
  B = -111;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";

  // Primeiro numero negativo, segundo numero nao negativo
  // Modulo do primeiro maior ou igual que o do segundo
  // Mesmo numero de digitos
  A = -865;
  B = 734;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Numero diferente de digitos
  A = -12398;
  B = 111;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";

  // Primeiro numero negativo, segundo numero nao negativo
  // Modulo do primeiro menor que o do segundo
  // Mesmo numero de digitos
  A = -265;
  B = 734;
  cout << "(" << A << ")+(" << B << ")="<< A+B << " \t ";
  // Numero diferente de digitos
  A = -98;
  B = 111;
  cout << "(" << A << ")+(" << B << ")="<< A+B << endl;

  // Testando subtracao
  cout << "\nI08:\t";

  // Envolvendo nulos
  A = 0;
  B = 0;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  A = 0;
  B = 123;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  A = 123;
  B = 0;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  A = 0;
  B = -123;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  A = -123;
  B = 0;
  cout << "(" << A << ")-(" << B << ")="<< A-B << endl;

  cout << "\nI09:\t";

  // Dois numeros nao negativos
  // Mesmo numero de digitos, sem carry
  A = 234;
  B = 765;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Mesmo numero de digitos, com carry
  A = 666;
  B = 345;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Mesmo numero de digitos, iguais
  A = 666;
  B = 666;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Numero diferente de digitos, sem carry
  A = 1;
  B = 998;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Numero diferente de digitos, com carry
  A = 998;
  B = 28;
  cout << "(" << A << ")-(" << B << ")="<< A-B << endl;

  cout << "\nI10:\t";

  // Dois numeros negativos
  // Mesmo numero de digitos, sem carry
  A = -234;
  B = -765;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Mesmo numero de digitos, com carry
  A = -666;
  B = -345;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Mesmo numero de digitos, iguais
  A = -345;
  B = -345;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Numero diferente de digitos, sem carry
  A = -1;
  B = -998;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Numero diferente de digitos, com carry
  A = -998;
  B = -28;
  cout << "(" << A << ")-(" << B << ")="<< A-B << endl;

  cout << "\nI11:\t";

  // Primeiro numero nao negativo, segundo numero negativo
  // Modulo do primeiro maior ou igual que o do segundo
  // Mesmo numero de digitos, sem carry
  A = 765;
  B = -234;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Mesmo numero de digitos, com carry
  A = 645;
  B = -366;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Numero diferente de digitos, sem carry
  A = 998;
  B = -1;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Numero diferente de digitos, com carry
  A = 926;
  B = -68;
  cout << "(" << A << ")-(" << B << ")="<< A-B << endl;

  cout << "\nI12:\t";

  // Primeiro numero nao negativo, segundo numero negativo
  // Modulo do primeiro menor que o do segundo
  // Mesmo numero de digitos
  A = 265;
  B = -734;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Numero diferente de digitos
  A = 98;
  B = -111;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";

  // Primeiro numero negativo, segundo numero nao negativo
  // Modulo do primeiro maior ou igual que o do segundo
  // Mesmo numero de digitos
  A = -865;
  B = 734;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Numero diferente de digitos
  A = -12398;
  B = 111;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";

  // Primeiro numero negativo, segundo numero nao negativo
  // Modulo do primeiro menor que o do segundo
  // Mesmo numero de digitos
  A = -265;
  B = 734;
  cout << "(" << A << ")-(" << B << ")="<< A-B << " \t ";
  // Numero diferente de digitos
  A = -98;
  B = 111;
  cout << "(" << A << ")-(" << B << ")="<< A-B << endl;

  return 0;
}
