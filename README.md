# Projeto 01: BigInt - Inteiros de Tamanho Ilimitado

Este projeto consiste no desenvolvimento de uma classe C++ chamada `BigInt`, desenhada para representar e manipular números inteiros (positivos, nulos ou negativos) com uma quantidade ilimitada de dígitos, ultrapassando os limites dos tipos primitivos como `long long int`.

## 🎯 Objetivos e Restrições Acadêmicas

O projeto foi desenvolvido para a disciplina de Programação Avançada na UFRN, com um foco estrito em boas práticas e fundamentos da linguagem C++. As principais restrições adotadas foram:

- **Gerenciamento Manual de Memória:** É proibido o uso de contêineres da Standard Template Library (STL), como `std::vector` ou `std::string`, para armazenar os dígitos. O armazenamento é feito através de arrays dinâmicos na memória heap, utilizando ponteiros brutos (`int8_t* d`), `new` e `delete`.
- **Aplicação da "Regra dos Cinco":** Para evitar vazamentos de memória (memory leaks) e falhas de segmentação, a classe implementa rigorosamente:
  - Destrutor customizado.
  - Construtor de cópia e Operador de atribuição por cópia.
  - Construtor de movimento e Operador de atribuição por movimento.
- **Sem uso de exceções avançadas:** A validação e o controle de fluxo dependem estritamente de lógica condicional e tratamentos locais.

## 🚀 Funcionalidades da Classe `BigInt`

- **Operadores Aritméticos:** Soma (`+`), Subtração (`-`), Multiplicação (`*`), Divisão (`/`) e Resto (`%`).
- **Fatorial:** Cálculo de fatorial (`!`) para números gigantes.
- **Deslocamento:** Operadores de deslocamento de dígitos para a esquerda (`<<`) e direita (`>>`), equivalentes a multiplicar/dividir por potências de 10.
- **Operadores Lógicos e Relacionais:** Suporte completo para `==`, `!=`, `<`, `>`, `<=`, `>=`.
- **Incremento e Decremento:** Operadores pré-fixados e pós-fixados (`++`, `--`).
- **Fluxo de E/S (I/O):** Sobrecarga de `operator<<` e `operator>>` para fácil exibição no console e leitura formatada, com descarte de caracteres inválidos.
- **Construtores de Conversão:** A partir de `long long int` e de `std::string` válida.

## 🗂 Estrutura do Projeto

- `bigint.h` / `bigint.cpp`: Declaração e implementação completa da classe `BigInt`.
- `bigint-main.cpp`: Um programa principal interativo, no estilo **Mini Calculadora**, operando através do console. Permite testar na prática a manipulação dos "BigInts".
- `teste1.cpp` a `teste8.cpp`: Conjunto de arquivos de testes unitários que garantem a cobertura e funcionamento de construtores, métodos e operadores.
- `run_tests.bat`: Script batch para automatizar a compilação e execução de todos os testes em sistemas Windows.

## 🛠️ Como Compilar e Executar

**Requisitos:** 
- Compilador compatível com C++17 (ex: `g++` via MinGW).
- Sistema operacional Windows (para uso do `.bat`).

### Opção 1: Executar os Testes Automatizados

Abra o terminal na pasta do projeto e execute o script em lote para compilar e rodar os testes unitários.

```cmd
run_tests.bat
```
*Você poderá escolher um teste específico (ex: `1` para rodar apenas `teste1.cpp`) ou `T` para executar a bateria completa de 1 a 8.*

### Opção 2: Executar a Mini Calculadora Interativa

Caso queira utilizar o programa interativo para digitar seus próprios números astronômicos e calcular (como um fatorial gigantesco), compile o arquivo principal junto com a classe:

```cmd
g++ -Wall -Wextra -std=c++17 bigint.cpp bigint-main.cpp -o mini_calculator.exe
```
E então, inicie a aplicação:
```cmd
mini_calculator.exe
```

---

*Desenvolvido como exercício acadêmico de engenharia de software e programação estruturada orientada a objetos.*