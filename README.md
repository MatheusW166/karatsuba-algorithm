[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/MatheusW166/karatsuba-algorithm/blob/main/LICENCE)

| [Uso](#use) | [Teoria](#teoria) | [Referências](#refs) |

# Implementação do Algoritmo de Karatsuba
Implementação na linguagem C do Algoritmo de Karatsuba, feita durante trabalho semestral na universidade. O algoritmo funciona recebendo dois números em forma de texto (char), e realiza divisões suscessivas até atingir dígitos menores para então multiplicá-los. Dessa forma, é possível realizar operaçẽos de multiplicação com valores extremamente grandes, que não poderiam ser armazenados em variáveis de tipo numérico.

## <span id="use">✅ Uso</span>
### Requisitos
- gcc ou g++

### Instruções
- Clonando repositório
```bash
$ git clone https://github.com/MatheusW166/karatsuba-algorithm.git
```
- Compilando o programa 
```bash
$ gcc karatsuba.c -o exe -lm
```
- Executando
```bash
$ ./exe
```

## <span id="teoria">📝 Teoria</span>
### O algoritmo
Assenálio ou Método de Multiplicação de Karatsuba é um método utilizado para multiplicar números grandes eficientemente, descoberto por Anatolii Alexeievitch Karatsuba em 1960. Este algoritmo reduz a multiplicação de dois números de `n` dígitos a no máximo:

$M(n)=O(n^{\log_{2} 3})$, multiplicação de dígitos simples quando `n` é uma potência de 2.

É mais rápido que o método usual de multiplicação longa, que necessita de $n^{2}$ multiplicações de um dígito simples.

### Divisão e conquista
A divisão e conquista é um paradigma de algoritmo que consiste na quebra do problema em subproblemas que são similares ao orgininal, os subproblemas são resolvidos recursivamente e então combinados para resolver o problema original.

Você deve pensar o algoritmo dividir-e-conquistar como tendo três partes:

- Dividir o problema em um número de subproblemas que sejam partes menores do mesmo problemas.
- Conquistar os subproblemas resolvendo-os recursivamente. Se eles forem pequenos o suficiente, resolva os subproblemas como problemas base.
- Combinar as soluções dos subproblemas em uma solução para o problema original.

## <span id="refs">📖 Referências</span>

  - [Algoritmo de Karatsuba](https://www.wikiwand.com/pt/Algoritmo_de_Karatsuba)
  - [Divisão e conquista](https://pt.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/divide-and-conquer-algorithms#:~:text=Voc%C3%AA%20deve%20pensar%20o%20algoritmo,os%20subproblemas%20como%20problemas%20base.)
