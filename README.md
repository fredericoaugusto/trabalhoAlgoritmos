# Projeto de Biblioteca de Classes para Manipulação de Vetores Dinâmicos para a disciplina de Algoritmos no curso Tecnólogo em Análise em Desenvolvimento de Sistemas pelo IFRN.

Este projeto implementa uma biblioteca de classes em C++ para manipulação de vetores dinâmicos. O trabalho tem como objetivo principal exercitar conceitos de gerenciamento de memória e realizar uma análise comparativa entre duas formas de implementação: alocação dinâmica de arrays e listas duplamente ligadas.

## Estrutura do Projeto

```plaintext
├── array_list.hpp
├── linked_list.hpp
├── tests
│   ├── push
│   │   ├── e1.txt
│   │   ├── e2.txt
│   │   ├── e3.txt
│   │   ├── e4.txt
│   │   ├── e5.txt
│   ├── remove_at
│   │   ├── e1.txt
│   │   ├── e2.txt
│   ├── gera_num.cpp
├── test-pushfront-array-list-01.cpp
├── test-pushfront-linked-list-01.cpp
├── test-removeat-array-list-01.cpp
├── test-removeat-linked-list-01.cpp
├── README.md
```

## Implementações

### Alocação Dinâmica de Arrays

A classe `array_list` foi implementada para manipular um vetor dinâmico utilizando alocação dinâmica de memória. A realocação de memória é feita conforme necessário, de três maneiras diferentes:
1. Aumento fixo de 100 elementos.
2. Aumento fixo de 1000 elementos.
3. Duplicação da capacidade inicial de 8 elementos.

### Lista Duplamente Ligada

A classe `linked_list` foi implementada para manipular um vetor dinâmico utilizando uma lista duplamente ligada. Cada nó da lista possui ponteiros para o próximo e para o nó anterior, permitindo inserções e remoções eficientes em qualquer posição.

## Métodos Implementados

### array_list.hpp

- **size()**: Retorna o número de elementos armazenados no vetor.
- **capacity()**: Retorna a capacidade atual do vetor.
- **percent_occupied()**: Retorna a porcentagem da capacidade do vetor que está ocupada.
- **insert_at(unsigned int index, int value)**: Insere um elemento no índice especificado.
- **remove_at(unsigned int index)**: Remove o elemento no índice especificado.
- **get_at(unsigned int index)**: Retorna o elemento no índice especificado.
- **clear()**: Remove todos os elementos do vetor.
- **push_back(int value)**: Adiciona um elemento ao final do vetor.
- **push_front(int value)**: Adiciona um elemento ao início do vetor.
- **pop_back()**: Remove o elemento no final do vetor.
- **pop_front()**: Remove o elemento no início do vetor.
- **front()**: Retorna o elemento no início do vetor.
- **back()**: Retorna o elemento no final do vetor.
- **remove(int value)**: Remove a primeira ocorrência de um valor específico no vetor.
- **find(int value)**: Retorna o índice da primeira ocorrência de um valor específico no vetor.
- **count(int value)**: Retorna o número de ocorrências de um valor específico no vetor.
- **sum()**: Retorna a soma de todos os elementos no vetor.

### linked_list.hpp

- **size()**: Retorna o número de elementos armazenados na lista.
- **capacity()**: Retorna a capacidade atual da lista (igual ao tamanho).
- **percent_occupied()**: Retorna a porcentagem da capacidade da lista que está ocupada.
- **insert_at(unsigned int index, int value)**: Insere um elemento no índice especificado.
- **remove_at(unsigned int index)**: Remove o elemento no índice especificado.
- **get_at(unsigned int index)**: Retorna o elemento no índice especificado.
- **clear()**: Remove todos os elementos da lista.
- **push_back(int value)**: Adiciona um elemento ao final da lista.
- **push_front(int value)**: Adiciona um elemento ao início da lista.
- **pop_back()**: Remove o elemento no final da lista.
- **pop_front()**: Remove o elemento no início da lista.
- **front()**: Retorna o elemento no início da lista.
- **back()**: Retorna o elemento no final da lista.
- **remove(int value)**: Remove a primeira ocorrência de um valor específico na lista.
- **find(int value)**: Retorna o índice da primeira ocorrência de um valor específico na lista.
- **count(int value)**: Retorna o número de ocorrências de um valor específico na lista.
- **sum()**: Retorna a soma de todos os elementos na lista.

## Compilação e Execução

### Compilando os Arquivos

Para compilar os arquivos de teste, use os seguintes comandos:

```sh
g++ -Wall -o test-pushfront-array-list-01 test-pushfront-array-list-01.cpp
g++ -Wall -o test-pushfront-linked-list-01 test-pushfront-linked-list-01.cpp
g++ -Wall -o test-removeat-array-list-01 test-removeat-array-list-01.cpp
g++ -Wall -o test-removeat-linked-list-01 test-removeat-linked-list-01.cpp
```
### Executando os Testes
 Os testes são executados utilizando arquivos de entrada que contêm uma série de números inteiros. Para cada teste, o tempo de execução é medido utilizando a biblioteca <chrono> do C++. A seguir estão as instruções para executar os testes:

### Testes de push_front
Para executar os testes de inserção no início (push_front), use os seguintes comandos:
```sh
./test-pushfront-array-list-01 < tests/push/e1.txt
./test-pushfront-linked-list-01 < tests/push/e1.txt
```

### Testes de remove_at
Para executar os testes de remoção por índice (remove_at), use os seguintes comandos:
```sh
./test-removeat-array-list-01 < tests/remove_at/e1.txt
./test-removeat-linked-list-01 < tests/remove_at/e1.txt
```

## Resultados dos Testes

### Teste de Inserção no Início (`push_front`)

| Número de Elementos | Array com Alocação Dinâmica (µs) | Lista Duplamente Ligada (µs) |
|---------------------|----------------------------------|------------------------------|
| 1000                | 150000                           | 70000                        |
| 5000                | 300000                           | 150000                       |
| 10000               | 600000                           | 300000                       |

### Teste de Remoção por Índice (`remove_at`)

| Número de Elementos | Array com Alocação Dinâmica (µs) | Lista Duplamente Ligada (µs) |
|---------------------|----------------------------------|------------------------------|
| 1000                | 120000                           | 90000                        |
| 5000                | 250000                           | 180000                       |
| 10000               | 500000                           | 350000                       |


### Gerando Arquivos de Entrada
O projeto inclui um gerador de números aleatórios (gera_num.cpp) para criar arquivos de entrada personalizados. Para compilar e executar o gerador, use os seguintes comandos:

#### Compilando o Gerador
```sh
g++ -Wall -o gera_num tests/gera_num.cpp
```

#### Executando o Gerador
```sh
./gera_num 1000 > meu_teste.txt
```

O arquivo gerado `meu_teste.txt` terá n+1 linhas, onde a primeira linha contém o valor `n` e as `n` linhas subsequentes contêm um número inteiro cada, gerados aleatoriamente.

### Informações mais detalhadas acerca do projeto estão no Relatorio.pdf
