#include <iostream>
#include <string>
#include "bigint.h"

using namespace std;

int main(void)
{
  BigInt BI0(0), BI1(1), BIm1(-1),
         BIbig(1234567890), BImbig(-1234567890), BIbig1(1234567891);

  cout << "CONFIRA SE AS RESPOSTAS GERADAS PELO PROGRAMA ESTAO CORRETAS (ok)\n";

  // Teste da igualdade
  cout << "\nI01: TESTE DA IGUALDADE:\n";
  cout << BI0 << "==" << BI0 << " ? " << (BI0==BI0 ? "SIM-ok" : "NAO-erro") << " \t "
       << BI0 << "==" << BigInt() << " ? " << (BI0==BigInt() ? "SIM-ok" : "NAO-erro") << " \t "
       << BI0 << "==" << BI1 << " ? " << (BI0==BI1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BigInt(1) << "==" << BI1 << " ? " << (BigInt(1)==BI1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BIm1 << "==" << BI1 << " ? " << (BIm1==BI1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BIbig << "==" << BI1 << " ? " << (BIbig==BI1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BIbig << "==" << BIbig << " ? " << (BIbig==BIbig ? "SIM-ok" : "NAO-erro") << " \t "
       << BIbig << "==" << BImbig << " ? " << (BIbig==BImbig ? "SIM-erro" : "NAO-ok") << endl;

  // Teste da desigualdade
  cout << "\nI02: TESTE DA DESIGUALDADE:\n";
  cout << BI0 << "!=" << BI0 << " ? " << (BI0!=BI0 ? "SIM-erro" : "NAO-ok") << " \t "
       << BI0 << "!=" << BigInt() << " ? " << (BI0!=BigInt() ? "SIM-erro" : "NAO-ok") << " \t "
       << BI0 << "!=" << BI1 << " ? " << (BI0!=BI1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BigInt(1) << "!=" << BI1 << " ? " << (BigInt(1)!=BI1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BIm1 << "!=" << BI1 << " ? " << (BIm1!=BI1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BIbig << "!=" << BI1 << " ? " << (BIbig!=BI1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BIbig << "!=" << BIbig << " ? " << (BIbig!=BIbig ? "SIM-erro" : "NAO-ok") << " \t "
       << BIbig << "!=" << BImbig << " ? " << (BIbig!=BImbig ? "SIM-ok" : "NAO-erro") << endl;

  // Teste do <
  cout << "\nI03: TESTE DO <:\n";
  cout << BIm1 << "<" << BI0 << " ? " << (BIm1<BI0 ? "SIM-ok" : "NAO-erro") << " \t "
       << BI1 << "<" << BIm1 << " ? " << (BI1<BIm1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BImbig << "<" << BIm1 << " ? " << (BImbig<BIm1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BIm1 << "<" << BImbig << " ? " << (BIm1<BImbig ? "SIM-erro" : "NAO-ok") << " \t "
       << BI1 << "<" << BIbig << " ? " << (BI1<BIbig ? "SIM-ok" : "NAO-erro") << " \t "
       << BIbig << "<" << BI1 << " ? " << (BIbig<BI1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BIbig << "<" << BIbig1 << " ? " << (BIbig<BIbig1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BIbig1 << "<" << BIbig << " ? " << (BIbig1<BIbig ? "SIM-erro" : "NAO-ok") << " \t "
       << BI0 << "<" << BI0 << " ? " << (BI0<BI0 ? "SIM-erro" : "NAO-ok") << " \t "
       << BI1 << "<" << BI1 << " ? " << (BI1<BI1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BIbig << "<" << BIbig << " ? " << (BIbig<BIbig ? "SIM-erro" : "NAO-ok") << endl;

  // Teste do <=
  cout << "\nI04: TESTE DO <=:\n";
  cout << BIm1 << "<=" << BI0 << " ? " << (BIm1<=BI0 ? "SIM-ok" : "NAO-erro") << " \t "
       << BI1 << "<=" << BIm1 << " ? " << (BI1<=BIm1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BImbig << "<=" << BIm1 << " ? " << (BImbig<=BIm1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BIm1 << "<=" << BImbig << " ? " << (BIm1<=BImbig ? "SIM-erro" : "NAO-ok") << " \t "
       << BI1 << "<=" << BIbig << " ? " << (BI1<=BIbig ? "SIM-ok" : "NAO-erro") << " \t "
       << BIbig << "<=" << BI1 << " ? " << (BIbig<=BI1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BIbig << "<=" << BIbig1 << " ? " << (BIbig<=BIbig1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BIbig1 << "<=" << BIbig << " ? " << (BIbig1<=BIbig ? "SIM-erro" : "NAO-ok") << " \t "
       << BI0 << "<=" << BI0 << " ? " << (BI0<=BI0 ? "SIM-ok" : "NAO-erro") << " \t "
       << BI1 << "<=" << BI1 << " ? " << (BI1<=BI1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BIbig << "<=" << BIbig << " ? " << (BIbig<=BIbig ? "SIM-ok" : "NAO-erro") << endl;

  // Teste do >
  cout << "\nI05: TESTE DO >:\n";
  cout << BIm1 << ">" << BI0 << " ? " << (BIm1>BI0 ? "SIM-erro" : "NAO-ok") << " \t "
       << BI1 << ">" << BIm1 << " ? " << (BI1>BIm1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BImbig << ">" << BIm1 << " ? " << (BImbig>BIm1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BIm1 << ">" << BImbig << " ? " << (BIm1>BImbig ? "SIM-ok" : "NAO-erro") << " \t "
       << BI1 << ">" << BIbig << " ? " << (BI1>BIbig ? "SIM-erro" : "NAO-ok") << " \t "
       << BIbig << ">" << BI1 << " ? " << (BIbig>BI1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BIbig << ">" << BIbig1 << " ? " << (BIbig>BIbig1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BIbig1 << ">" << BIbig << " ? " << (BIbig1>BIbig ? "SIM-ok" : "NAO-erro") << " \t "
       << BI0 << ">" << BI0 << " ? " << (BI0>BI0 ? "SIM-erro" : "NAO-ok") << " \t "
       << BI1 << ">" << BI1 << " ? " << (BI1>BI1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BIbig << ">" << BIbig << " ? " << (BIbig>BIbig ? "SIM-erro" : "NAO-ok") << endl;

  // Teste do >=
  cout << "\nI06: TESTE DO >=:\n";
  cout << BIm1 << ">=" << BI0 << " ? " << (BIm1>=BI0 ? "SIM-erro" : "NAO-ok") << " \t "
       << BI1 << ">=" << BIm1 << " ? " << (BI1>=BIm1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BImbig << ">=" << BIm1 << " ? " << (BImbig>=BIm1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BIm1 << ">=" << BImbig << " ? " << (BIm1>=BImbig ? "SIM-ok" : "NAO-erro") << " \t "
       << BI1 << ">=" << BIbig << " ? " << (BI1>=BIbig ? "SIM-erro" : "NAO-ok") << " \t "
       << BIbig << ">=" << BI1 << " ? " << (BIbig>=BI1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BIbig << ">=" << BIbig1 << " ? " << (BIbig>=BIbig1 ? "SIM-erro" : "NAO-ok") << " \t "
       << BIbig1 << ">=" << BIbig << " ? " << (BIbig1>=BIbig ? "SIM-ok" : "NAO-erro") << " \t "
       << BI0 << ">=" << BI0 << " ? " << (BI0>=BI0 ? "SIM-ok" : "NAO-erro") << " \t "
       << BI1 << ">=" << BI1 << " ? " << (BI1>=BI1 ? "SIM-ok" : "NAO-erro") << " \t "
       << BIbig << ">=" << BIbig << " ? " << (BIbig>=BIbig ? "SIM-ok" : "NAO-erro") << endl;

  // Teste do conversor implicito de string, que nao deve existir
  cout << "\nI07: TESTE DO CONVERSOR IMPLICITO DE STRING:\n";
  string S("123456789");
  BigInt BS(S);
  cout << "Soh deve compilar se comentar a proxima linha\n";
  // Tentativa de usar o conversor implicito de string para BigInt
  // if (BS == S) cerr << "Nao deveria compilar essa linha, que contem erro\n";

  return 0;
}
