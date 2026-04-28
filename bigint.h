#include <climits>
#include <cstdint>
#include <string>
#include <iostream>

class BigInt {
private:
    bool neg;
    int nDig;
    int8_t* d;

    // Construtor específico privado (Obrigatório ser privado)
    BigInt(bool IsNeg, int Size);
    
    void correct();
    void increment();
    void decrement();

public:
    // Construtores que já vieram prontos no arquivo base
    BigInt();
    BigInt(const BigInt& B);
    explicit BigInt(const std::string& S);

    // Gerenciamento de Memória (Dia 1)
    ~BigInt();
    BigInt(BigInt&& other) noexcept;
    BigInt& operator=(const BigInt& other);
    BigInt& operator=(BigInt&& other) noexcept;

    // Funções de Consulta (Dia 2)
    bool isNeg() const;
    int size() const;
    bool isZero() const;
    int operator[](int i) const;

    // Conversões Numéricas (Dia 2)
    BigInt(long long int N);
    long long int toInt() const;

    BigInt& operator++();
    BigInt& operator--();
    BigInt operator++(int);
    BigInt operator--(int);

    friend std::istream& operator>>(std::istream& I, BigInt& B);
    friend std::ostream& operator<<(std::ostream& O, const BigInt& B);
    const BigInt& operator+() const;
    BigInt operator-() const;
    BigInt operator+(const BigInt& B) const;
    BigInt operator-(const BigInt& B) const;
    BigInt operator*(const BigInt& B) const;
    BigInt operator!() const;
    BigInt operator<<(int N) const;
    BigInt operator>>(int N) const;
    void division(const BigInt& D, BigInt& Q, BigInt& R) const;
    BigInt operator/(const BigInt& D) const;
    BigInt operator%(const BigInt& D) const;
};

bool operator==(const BigInt& A, const BigInt& B);
bool operator!=(const BigInt& A, const BigInt& B);
bool operator<(const BigInt& A, const BigInt& B);
bool operator>(const BigInt& A, const BigInt& B);
bool operator<=(const BigInt& A, const BigInt& B);
bool operator>=(const BigInt& A, const BigInt& B);
BigInt abs(const BigInt& X);
