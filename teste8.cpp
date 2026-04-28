#include <iostream>
#include <cstdlib>
#include <ctime>
#include "bigint.h"

using namespace std;

int main(void)
{
  BigInt BI0(0), BI1(1), BIm1(-1),
         BIbig(1234567890), BImbig(-1234567890), BIbig1(1234567891);

  // Teste do deslocamento aa esquerda
  cout << "I01 - TESTE DO DESLOCAMENTO AA ESQUERDA\n";
  cout << "Confira se os resultados estao corretos:\n";
  cout << "BI=" << BI0 << " (BI<<3)=" << (BI0<<3) << " (deve ser 0)\t ";
  cout << "BI=" << BI1 << " (BI<<3)=" << (BI1<<3) << " (deve ser 1000)\t ";
  cout << "BI=" << BIm1 << " (BI<<3)=" << (BIm1<<3) << " (deve ser -1000)\n";
  cout << "BI=" << BIbig << " (BI<<-1)=" << (BIbig<<-1) << " (deve ser 1234567890)\t ";
  cout << "BI=" << BIbig << " (BI<<0)=" << (BIbig<<0) << " (deve ser 1234567890)\n";
  cout << "BI=" << BIbig << " (BI<<3)=" << (BIbig<<3) << " (deve ser 1234567890000)\t ";
  cout << "BI=" << BImbig << " (BI<<3)=" << (BImbig<<3) << " (deve ser -1234567890000)\n";

  // Teste do deslocamento aa direita
  cout << "\nI02 - TESTE DO DESLOCAMENTO AA DIREITA\n";
  cout << "Confira se os resultados estao corretos:\n";
  cout << "BI=" << BI0 << " (BI>>3)=" << (BI0>>3) << " (deve ser 0)\t ";
  cout << "BI=" << BI1 << " (BI>>3)=" << (BI1>>3) << " (deve ser 0)\t ";
  cout << "BI=" << BIm1 << " (BI>>3)=" << (BIm1>>3) << " (deve ser 0)\n";
  cout << "BI=" << BIbig << " (BI>>-1)=" << (BIbig>>-1) << " (deve ser 1234567890)\t ";
  cout << "BI=" << BIbig << " (BI>>0)=" << (BIbig>>0) << " (deve ser 1234567890)\n";
  cout << "BI=" << BIbig << " (BI>>3)=" << (BIbig>>3) << " (deve ser 1234567)\t ";
  cout << "BI=" << BIbig << " (BI>>10)=" << (BIbig>>10) << " (deve ser 0)\t ";
  cout << "BI=" << BImbig << " (BI>>3)=" << (BImbig>>3) << " (deve ser -1234567)\n";

  // Testando funcao de divisao
  cout << "\nI03 - NAO DEVE EMITIR NENHUMA MENSAGEM DE ERRO\n";
  BigInt A,B,Q,R;
  srand(time(nullptr));
  try
  {
    A = 1;
    for (int i=0; i<15; ++i)
    {
      A = (A<<1) + rand()%10;
      B = rand();
      A.division(B,Q,R);
      if (Q*B+R != A) throw 1;
      B = -rand();
      A.division(B,Q,R);
      if (Q*B+R != A) throw 2;
    }
    A = -1;
    for (int i=0; i<15; ++i)
    {
      A = (A<<1) + rand()%10;
      B = rand();
      A.division(B,Q,R);
      if (Q*B+R != A) throw 3;
      B = -rand();
      A.division(B,Q,R);
      if (Q*B+R != A) throw 4;
    }
  }
  catch(int i)
  {
    cout << "Erro " << i << " na divisao " << A << '/' << B << " = "
         << Q << " resto " << R<< endl;
  }

  // Testando operadores de divisao envolvendo zeros
  cout << "\nI04 - OPERADORES DE DIVISAO ENVOLVENDO ZERO\n";
  cout << "Confira se os resultados e eventuais msgs de erro estao corretos:\n";
  A = 0;
  B = 0;
  cout << "\n(" << A << ")/(" << B << ")="<< A/B << " resto=" << A%B << '\n'
       << "Deve imprimir msg de erro, quociente=0, msg de erro, resto=0\n";
  A = 0;
  B = 123;
  cout << "\n(" << A << ")/(" << B << ")="<< A/B << " resto=" << A%B << '\n'
       << "Deve imprimir quociente=0, resto=0\n";
  A = 123;
  B = 0;
  cout << "\n(" << A << ")/(" << B << ")="<< A/B << " resto=" << A%B << '\n'
       << "Deve imprimir msg de erro, quociente=0, msg de erro, resto=0\n";
  A = 0;
  B = -123;
  cout << "\n(" << A << ")/(" << B << ")="<< A/B << " resto=" << A%B << '\n'
       << "Deve imprimir quociente=0, resto=0\n";
  A = -123;
  B = 0;
  cout << "\n(" << A << ")/(" << B << ")="<< A/B << " resto=" << A%B << '\n'
       << "Deve imprimir msg de erro, quociente=0, msg de erro, resto=0\n";

  // Testando operadores de divisao sem zeros
  cout << "\nI05 - OPERADORES DE DIVISAO SEM ZERO\n";
  cout << "Confira se nao exibe msgs de erro e se os resultados estao corretos:\n";
  // Dois numeros nao negativos, dividendo modulo menor que o divisor
  A = 10000;
  B = 98765;
  cout << "\n(" << A << ")/(" << B << ")="<< A/B << " resto=" << A%B << '\n'
       << "Deve imprimir quociente=0, resto=10000\n";
  // Dois numeros nao negativos, dividendo modulo maior que o divisor
  A = 1000000000000;
  B = 98765;
  cout << "\n(" << A << ")/(" << B << ")="<< A/B << " resto=" << A%B << '\n'
       << "Deve imprimir quociente=10125044, resto=29340\n";
  // Dois numeros negativos
  A = -123456700;
  B = -12345;
  cout << "\n(" << A << ")/(" << B << ")="<< A/B << " resto=" << A%B << '\n'
       << "Deve imprimir quociente=10000, resto=-6700\n";
  // Primeiro numero nao negativo, segundo negativo
  A = 123456;
  B = -1234;
  cout << "\n(" << A << ")/(" << B << ")="<< A/B << " resto=" << A%B << '\n'
       << "Deve imprimir quociente=-100, resto=56\n";
  // Primeiro numero negativo, segundo nao negativo
  A = -123450000;
  B = 12345;
  cout << "\n(" << A << ")/(" << B << ")="<< A/B << " resto=" << A%B << '\n'
       << "Deve imprimir quociente=-10000, resto=0\n";

  return 0;
}

