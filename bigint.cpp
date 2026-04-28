#include <iostream>
#include <cmath>
#include "bigint.h"

using namespace std;

/// Construtor default.
/// Inicializa com um inteiro de 1 digito, valor 0 (zero).
/// NAO PODE SER MODIFICADO
BigInt::BigInt()
  : neg(false)
  , nDig(1)
  , d(new int8_t[nDig]{0})
{}

/// Destrutor
/* Já acrescentado pelo aluno em 27/03/2026 */
BigInt::~BigInt() {
    delete[] d;
}

/// Construtor especifico PRIVADO que recebe o sinal e a quantidade de digitos
/* Já acrescentado pelo aluno em 27/03/2026 */
BigInt::BigInt(bool IsNeg, int Size) : neg(IsNeg), nDig(Size >= 1 ? Size : 1) {
    d = new int8_t[nDig];
    for(int i = 0; i < nDig; i++) {
        d[i] = 0;
    }
}
/// Construtor por copia.
/// Delega ao construtor especifico privado.
/// NAO PODE SER MODIFICADO.
BigInt::BigInt(const BigInt& B)
  : BigInt(B.isNeg(), B.size())
{
  // Copia os digitos
  for (int i=0; i<size(); ++i) d[i] = B.d[i];
}

/// Atribuicao por copia
/* Já acrescentado pelo aluno em 27/03/2026 */
BigInt& BigInt::operator=(const BigInt& other) {
    if (this == &other) return *this; // Evita erro se fizer A = A [2]
    
    delete[] d; // Libera a memória antiga [4]
    
    neg = other.neg;
    nDig = other.nDig;
    d = new int8_t[nDig]; // Aloca memória com o novo tamanho [4]
    
    for (int i = 0; i < nDig; i++) {
        d[i] = other.d[i]; // Copia os dígitos [4]
    }
    
    return *this;
}

/// Construtor por movimento
/* Já acrescentado pelo aluno em 27/03/2026 */
BigInt::BigInt(BigInt&& other) noexcept 
    : neg(other.neg), nDig(other.nDig), d(other.d) {
    // Zera o objeto temporário para o destrutor dele não apagar a memória
    other.nDig = 0;
    other.d = nullptr;
}

/// Atribuicao por movimento
/* Já acrescentado pelo aluno em 27/03/2026 */
BigInt& BigInt::operator=(BigInt&& other) noexcept {
    if (this == &other) return *this;
    
    delete[] d; // Libera a memória antiga [5]
    
    neg = other.neg;
    nDig = other.nDig;
    d = other.d; // Rouba a área de memória [5]
    
    // Zera o temporário [5]
    other.nDig = 0;
    other.d = nullptr;
    
    return *this;
}
/*Já acrescentado pelo aluno em 27/03/2026*/
bool BigInt::isNeg() const {
    return neg;
}

int BigInt::size() const {
    return nDig;
}

bool BigInt::isZero() const {
    return (nDig == 1 && d[0] == 0);
}

int BigInt::operator[](int i) const {
    if (i >= nDig || i < 0) {
        return 0;
    }
    return static_cast<int>(d[i]);
}

/// Construtor especifico a partir de inteiro longo.
/// Tambem conversor de long long int para BigInt.
/// NAO PODE SER MODIFICADO NAS PARTES JAH IMPLEMENTADAS.
/// PODE (E PRECISA) RECEBER ACRESCIMOS, APENAS
/// NAS PARTES INDICADAS POR /* ACRESCENTAR */
BigInt::BigInt(long long int N)
  /* Já acrescentado pelo aluno em 27/03/2026 */
    : BigInt(N < 0, N == 0 ? 1 : 1 + static_cast<int>(log10(fabs(static_cast<double>(N)))))
{
  // Calcula os digitos, usando divisao inteira por 10
  for (int i=0; i<size(); ++i)
  {
    d[i] = abs(N%10); // Modulo do resto da divisao
    N /= 10;          // Divisao inteira
  }
}

/// Conversor de BigInt para long long int
/* Já acrescentado pelo aluno em 27/03/2026 */
long long int BigInt::toInt() const {
    long long int val = 0;
    for (int i = size() - 1; i >= 0; --i) {
        val = 10 * val + d[i];
        if (val < 0) {
            std::cerr << "Erro: valor excede limite de long long int\n";
            return 0;
        }
    }
    
    if (isNeg()) {
        val = -val;
    }
    
    return val;
}

/// ******************
/// * FIM DA PARTE 1 *
/// ******************

/// Funcao privada que corrige o numero, caso haja inconsistencias
/* Já acrescentado pelo aluno em 30/03/2026 */
void BigInt::correct() {
    int newSize = size();
    while (newSize > 1 && d[newSize - 1] == 0) {
        newSize--;
    }

    if (newSize != size()) {
        BigInt prov(neg, newSize); // Usa o construtor privado
        for (int i = 0; i < newSize; ++i) {
            prov.d[i] = d[i];
        }
        *this = std::move(prov); // Usa a atribuição por movimento que já fizemos!
    }

    if (isZero()) {
        neg = false;
    }
}

/// Construtor especifico a partir de string.
/// Nao eh conversor de string para BigInt.
/// Delega ao construtor default.
/// NAO PODE SER MODIFICADO NAS PARTES JAH IMPLEMENTADAS.
/// PODE (E PRECISA) RECEBER ACRESCIMOS, APENAS
/// NAS PARTES INDICADAS POR /* ACRESCENTAR */
BigInt::BigInt(const string& S)
  : BigInt() // Valor inicial zero
{
  // Se string vazia, emite erro e permanece com valor inicial zero
  if (S.empty())
  {
    cerr << "empty string cannot create a BigInt\n";
    return;
  }

  // Posicao onde comecam os digitos, inicialmente zero
  size_t ini=0;
  // Leva em conta o sinal
  bool IsNeg = false;

  if (S[0]=='+' || S[0]=='-')
  {
    // Se nao tem nenhum digito alem do sinal, emite erro e permanece com valor inicial
    if (S.size()==1)
    {
      cerr << "sign-only string cannot create a BigInt\n";
      return;
    }
    IsNeg = (S[0]=='-');
    ++ini;
  }

  // Faz ter sinal (IsNeg) e numero de digitos (tamanho da string - ini) corretos
  /* Já acrescentado pelo aluno em 30/03/2026 */
  *this = BigInt(IsNeg, S.size() - ini);

  // Calculo dos digitos do BigInt
  for (int i=0; i<size(); ++i)
  {
    char c = S[S.size()-1-i];
    if (!isdigit(c))
    {
      *this = BigInt(); // = 0
      cerr << "string with invalid character cannot create a BigInt\n";
      return;
    }
    d[i] = static_cast<int8_t>(c-'0');
  }
  // Corrige eventuais numeros fora da especificacao
  correct();
}

/// ******************
/// * FIM DA PARTE 2 *
/// ******************

/// Insercao (impressao)
/* Já acrescentado pelo aluno em 01/04/2026 */
std::ostream& operator<<(std::ostream& O, const BigInt& B) {
    if (B.isNeg()) O << '-';
    for (int i = B.size() - 1; i >= 0; --i) {
        int digito = B[i];
        if (digito >= 0 && digito <= 9) O << digito;
        else O << '#';
    }
    return O;
}

/// Extracao (digitacao).
/// NAO PODE SER MODIFICADO NAS PARTES JAH IMPLEMENTADAS.
/// PODE (E PRECISA) RECEBER ACRESCIMOS, APENAS
/// NAS PARTES INDICADAS POR /* ACRESCENTAR */
std::istream& operator>>(istream& I, BigInt& B)
{
  // Valor inicial zero
  B = BigInt(); // = 0

  // Testa a stream de entrada e descarta eventuais separadores iniciais.
  // Em caso de erro, encerra a digitacao.
  istream::sentry s(I);
  if (!s) return I;

  // Caractere lido da stream
  int c;

  // Inspeciona o primeiro caractere que serah lido
  c = I.peek();

  // Testa se o primeiro caractere eh um sinal.
  // Se for, consome (elimina do buffer), processa e inspeciona o proximo caractere.
  if (c=='+' || c=='-')
  {
    // Consome
    c = I.get();
    // Atribui o sinal
    B.neg = (c=='-');
    // Obtem o proximo caractere
    c = I.peek();
  }

  // Numero de digitos que foram digitados
  int numDigitos = 0;

  // Testa se eh um caractere valido: digitos 0 a 9
  while (isdigit(c))
  {
    // Consome do buffer
    c = I.get();
    ++numDigitos;

    if (numDigitos>1)
    {
      // Faz o BigInt manter o sinal e passar a ter size()+1 digitos,
      // avancando todos para uma posicao mais significativa aa frente.
      /* Já acrescentado pelo aluno em 01/04/2026 */
        BigInt prov(B.isNeg(), B.size() + 1);
        for (int i = 0; i < B.size(); ++i) {
            prov.d[i + 1] = B.d[i];
        }
        B = std::move(prov);
    }

    // Acrescenta o novo digito como sendo o primeiro (o menos significativo)
    B.d[0] = static_cast<int8_t>(c-'0');

    // Inspeciona o proximo caractere que vai ser lido
    c = I.peek();
  }

  // Assinala erro na stream se nenhum digito foi lido
  if (numDigitos==0) I.setstate(ios::failbit);

  // Corrige eventuais erros na digitacao
  B.correct();

  // Encerra a digitacao
  return I;
}

/// ******************
/// * FIM DA PARTE 3 *
/// ******************

/// Teste de igualdade
/* Já acrescentado pelo aluno em 01/04/2026 */
bool operator==(const BigInt& A, const BigInt& B) {
    if (A.isNeg() != B.isNeg()) return false;
    if (A.size() != B.size()) return false;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

bool operator!=(const BigInt& A, const BigInt& B) {
    return !(A == B);
}

/// Menor que
/* Já acrescentado pelo aluno em 01/04/2026 */
bool operator<(const BigInt& A, const BigInt& B) {
    if (A.isNeg() != B.isNeg()) return A.isNeg();

    if (!A.isNeg()) { // Ambos positivos ou nulos
        if (A.size() != B.size()) return A.size() < B.size();
        for (int i = A.size() - 1; i >= 0; --i) {
            if (A[i] != B[i]) return A[i] < B[i];
        }
    } else { // Ambos negativos
        if (A.size() != B.size()) return A.size() > B.size();
        for (int i = A.size() - 1; i >= 0; --i) {
            if (A[i] != B[i]) return A[i] > B[i];
        }
    }
    
    return false; // Números idênticos
}

bool operator>(const BigInt& A, const BigInt& B) {
    return B < A;
}

bool operator<=(const BigInt& A, const BigInt& B) {
    return !(B < A);
}

bool operator>=(const BigInt& A, const BigInt& B) {
    return !(A < B);
}

/// ******************
/// * FIM DA PARTE 4 *
/// ******************

/// Funcao privada que incrementa os digitos (o modulo) do numero
/* Já acrescentado pelo aluno em 04/04/2026 */
void BigInt::increment() {
    int k = 0;
    while (k < size() && d[k] == 9) {
        d[k] = 0;
        k++;
    }
    
    if (k < size()) {
        d[k]++;
    } else {
        // Aumenta o número de dígitos (ex: 999 -> 1000)
        BigInt prov(isNeg(), size() + 1); // Cria com size+1, todos os dígitos já são 0
        prov.d[size()] = 1;               // O dígito mais significativo recebe 1
        *this = std::move(prov);          // Substitui o objeto atual
    }
}

/// Funcao privada que decrementa os digitos (o modulo) do numero
/* Já acrescentado pelo aluno em 04/04/2026 */

void BigInt::decrement() {
    if (isZero()) {
        neg = true;
        d[0] = 1;
        return;
    }
    
    int k = 0;
    while (k < size() && d[k] == 0) {
        d[k] = 9;
        k++;
    }
    
    d[k]--;
    
    if (d[size() - 1] == 0) {
        correct();
    }
}

/// Operador de incremento pre-fixado
/// NAO PODE SER MODIFICADO
BigInt& BigInt::operator++()
{
  if (!isNeg()) increment();
  else decrement();
  return *this;
}

/// Operador de decremento pre-fixado
/// NAO PODE SER MODIFICADO
BigInt& BigInt::operator--()
{
  if (isNeg()) increment();
  else decrement();
  return *this;
}

/// Operador de incremento pos-fixado
/* Já acrescentado pelo aluno em 04/04/2026 */
BigInt BigInt::operator++(int) {
    BigInt prov(*this); // Cria a cópia
    ++(*this);          // Incrementa usando o pré-fixado
    return prov;        // Retorna a cópia
}

/// Operador de decremento pos-fixado
/* Já acrescentado pelo aluno em 04/04/2026 */
BigInt BigInt::operator--(int) {
    BigInt prov(*this); // Cria a cópia
    --(*this);          // Decrementa usando o pré-fixado
    return prov;        // Retorna a cópia
}

/// ******************
/// * FIM DA PARTE 5 *
/// ******************


/* Já acrescentado pelo aluno em 04/04/2026 */
/// Modulo (abs)
BigInt abs(const BigInt& X) {
    return X.isNeg() ? -X : X;
}

/// Positivo (unario)
const BigInt& BigInt::operator+() const {
    return *this;
}

/// Negativo (unario)
BigInt BigInt::operator-() const {
    BigInt prov(*this);
    if (!prov.isZero()) {
        prov.neg = !prov.neg;
    }
    return prov;
}

/// Soma
/* Já acrescentado pelo aluno em 04/04/2026*/
BigInt BigInt::operator+(const BigInt& B) const {
    if (isNeg() == B.isNeg()) { // Sinais iguais
        int maxSize = (size() > B.size()) ? size() : B.size();
        BigInt C(isNeg(), maxSize + 1);
        int carry = 0;
        for (int i = 0; i < C.size(); ++i) {
            int sum = (*this)[i] + B[i] + carry;
            if (sum > 9) {
                C.d[i] = sum - 10;
                carry = 1;
            } else {
                C.d[i] = sum;
                carry = 0;
            }
        }
        C.correct();
        return C;
    } else { // Sinais diferentes
        BigInt absThis = abs(*this);
        BigInt absB = abs(B);
        if (absThis >= absB) {
            BigInt C(isNeg(), size());
            int borrow = 0;
            for (int i = 0; i < C.size(); ++i) {
                int diff = (*this)[i] - B[i] - borrow;
                if (diff < 0) {
                    C.d[i] = diff + 10;
                    borrow = 1;
                } else {
                    C.d[i] = diff;
                    borrow = 0;
                }
            }
            C.correct();
            return C;
        } else {
            return B + (*this);
        }
    }
}

BigInt BigInt::operator-(const BigInt& B) const {
    return *this + (-B);
}

/// ******************
/// * FIM DA PARTE 6 *
/// ******************

/// Multiplicacao
/* Já acrescentado pelo aluno em 05/04/2026 */
BigInt BigInt::operator*(const BigInt& B) const {
    if (isZero() || B.isZero()) return BigInt(); // Retorna 0

    bool sign = (isNeg() != B.isNeg());
    BigInt C(sign, size() + B.size()); // Cria número preenchido com 0s

    for (int i = 0; i < size(); ++i) {
        if (d[i] != 0) {
            for (int j = 0; j < B.size(); ++j) {
                if (B.d[j] != 0) {
                    int k = i + j;
                    C.d[k] = C.d[k] + d[i] * B.d[j];
                    while (C.d[k] > 9) {
                        int carry = C.d[k] / 10;
                        C.d[k] = C.d[k] % 10;
                        k++;
                        C.d[k] = C.d[k] + carry;
                    }
                }
            }
        }
    }
    C.correct();
    return C;
}

/// Fatorial
/* Já acrescentado pelo aluno em 05/04/2026  */
BigInt BigInt::operator!() const {
    if (isNeg()) {
        std::cerr << "Erro: Fatorial de numero negativo.\n";
        return BigInt(); // Retorna 0
    }
    
    BigInt C(1);
    for (BigInt N(2); N <= *this; ++N) {
        C = C * N;
    }
    return C;
}

/// ******************
/// * FIM DA PARTE 7 *
/// ******************

/// Deslocamento aa esquerda
/* Já acrescentado pelo aluno em 05/04/2026 */
BigInt BigInt::operator<<(int N) const {
    if (N <= 0 || isZero()) return *this;
    
    BigInt C(isNeg(), size() + N);
    for (int i = N; i < C.size(); ++i) {
        C.d[i] = d[i - N];
    }
    return C;
}

/// Deslocamento ah direita
/* Já acrescentado pelo aluno em 05/04/2026 */
BigInt BigInt::operator>>(int N) const {
    if (N <= 0 || isZero()) return *this;
    if (N >= size()) return BigInt(); // Retorna 0
    
    BigInt C(isNeg(), size() - N);
    for (int i = 0; i < C.size(); ++i) {
        C.d[i] = d[i + N];
    }
    return C;
}

/// Divisao de *this por D.
/// Armazena o resultado (quociente) em Q e o resto da divisao em R.
/* Já acrescentado pelo aluno em 05/04/2026 */
void BigInt::division(const BigInt& D, BigInt& Q, BigInt& R) const {
    Q = BigInt(); // Q inicializado com 0
    if (isZero() || D.isZero()) {
        if (D.isZero()) std::cerr << "Erro: Divisao por zero.\n";
        R = BigInt();
        return;
    }

    BigInt absD = abs(D);
    if (abs(*this) < absD) {
        R = *this;
        return;
    }

    R = BigInt(); // R inicializado com 0
    for (int i = size() - 1; i >= 0; --i) {
        if (!R.isZero()) R = R << 1;
        R.d[0] = d[i];

        int div = 0;
        while (R >= absD) {
            R = R - absD;
            div++;
        }

        if (!Q.isZero()) Q = Q << 1;
        Q.d[0] = div;
    }

    Q.neg = (isNeg() != D.isNeg());
    if (!R.isZero()) R.neg = isNeg();
}
/// Quociente da divisao inteira
/* Já acrescentado pelo aluno em 05/04/2026  */
BigInt BigInt::operator/(const BigInt& D) const {
    BigInt Q, R;
    division(D, Q, R);
    return Q;
}
/// Resto da divisao inteira
/* Já acrescentado pelo aluno em 05/04/2026 */
BigInt BigInt::operator%(const BigInt& D) const {
    BigInt Q, R;
    division(D, Q, R);
    return R;
}
/// ******************
/// * FIM DA PARTE 8 *
/// ******************
/// ******************
/// ******************
