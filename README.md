# U5412 - Programação de Computadores - Estruturada

## Ficha 1

1. **Impressão de Números**: Escreva um programa que solicite dois números inteiros e imprima esses números.
2. **Operações Aritméticas**: Escreva um programa que solicite ao utilizador dois números inteiros e apresente o resultado das seguintes operações aritméticas: adição, subtração, multiplicação e divisão.
3. **Conversão de Segundos**: Escreva um programa que solicite um determinado número de segundos e indique quantas horas, minutos e segundos esse valor representa.

## Ficha 2

1. **Cálculo de Preço de Venda**: Calcule o preço de venda de um artigo, sabendo o preço base e a percentagem do IVA.
2. **Sucessor e Antecessor**: Escreva um programa que solicite um número inteiro e escreva o seu sucessor e o antecessor.
3. **Troca de Números**: Escreva um programa que solicite dois números e faça a troca dos números entre variáveis.
4. **Ciclos Encadeados**: Elabore 3 algoritmos em C que utilizem ciclos encadeados para imprimir os resultados conforme o PDF fornecido.

## Ficha 3

1. **Movimentação de Números em Array**: Construa um programa em C que preencha um array de 10 números inteiros. O programa deve movimentar os números ímpares para a esquerda do array e os números pares para a direita.

## Ficha 4

1. **Transposição de Matriz**: Elabore um algoritmo em C que preencha uma matriz de inteiros com 5 linhas e 5 colunas. Faça as trocas necessárias para que as linhas se transformem em colunas (1ª linha → 1ª coluna, 2ª linha → 2ª coluna, ..., 5ª linha → 5ª coluna) utilizando obrigatoriamente ciclos.

## Ficha 5

1. **Conversão de Case**: Crie um algoritmo em C que receba uma string e faça a conversão das minúsculas para maiúsculas e das maiúsculas para minúsculas.
2. **Substituição de Espaços**: Crie um algoritmo em C que receba uma string e faça a substituição dos espaços em branco por underscore (‘_’).
3. **Contagem de Palavras**: Crie um algoritmo em C que receba uma string e imprima a contagem das palavras existentes na string.

## Ficha 6

1. **Cálculo de Área de um Círculo**: Crie uma função em C que calcule a área (A) de um círculo. Fórmula: A = π × r².
2. **Conversão de Temperatura**: Crie uma função em C que faça a conversão de graus Celsius para Fahrenheit.
3. **Inversão de String**: Construa uma função em C que faça a inversão de uma string passada como argumento.
4. **Dimensão da Menor Palavra**: Elabore uma função em C que devolva a dimensão da menor palavra encontrada numa string passada como argumento.
5. **Movimentação em Array**: Construa uma função em C que receba um array de números inteiros e movimente os números ímpares para a esquerda e os números pares para a direita.
6. **Valor Mais Frequente**: Construa uma função em C que devolva o valor que se repete com mais frequência num array de números inteiros positivos passado como argumento. Se não existirem números repetidos, deve devolver -1.

## Ficha 7

1. **Função para Copiar Arrays**: Crie uma função que receba dois arrays de números inteiros como argumentos e copie os valores de um para o outro.
2. **Gerador de Números Aleatórios**: Crie uma função que devolva um número aleatório entre dois números inteiros passados como argumentos.
3. **Array de Dados dos Aeroportos**: Crie um array para armazenar os dados dos 30 aeroportos públicos de Portugal. O array deve utilizar a estrutura fornecida no PDF.
4. **Funções de Gestão do Array**: Crie as seguintes funções para gerir o array de aeroportos:
   - `inserir()`: Inserir um novo aeroporto.
   - `listar()`: Listar todos os aeroportos.
   - `procurar()`: Procurar um aeroporto.
   - `alterar()`: Alterar as informações de um aeroporto.

## Ficha 8

1. **Algoritmo para Array de Temperaturas**: Crie um algoritmo para inserir temperaturas num array. O array deve ser redimensionado sempre que uma nova temperatura for inserida e deve ter uma posição no final para armazenar a média das temperaturas, que deve ser atualizada sempre que uma nova temperatura for adicionada.
2. **Algoritmo para Redimensionar String**: Crie um algoritmo que redimensione uma string para se ajustar ao comprimento do nome inserido.

## Ficha 9

1. **Função para Contar Ocorrências de String**: Crie uma função que devolva o número de vezes que uma string é encontrada num ficheiro de texto.

## Trabalho Final: Gestão de Praias Portuguesas

## 1. Descrição

Este projeto consiste em uma aplicação desenvolvida em linguagem C para a gestão dos dados das praias portuguesas, organizadas por localidade. A aplicação utiliza dois ficheiros principais e oferece diversas funcionalidades para manipulação e visualização dos dados.

## 2. Estruturas de Dados

A aplicação utiliza os seguintes ficheiros:

- **Praias**: Contém informações sobre as praias, incluindo:
  - `IDPraia`: preenchido automaticamente.
  - `IDLocalidade`: deve corresponder a um IDLocalidade existente no ficheiro Localidades.
  - `Tipo`: preenchido com uma das opções "oceânica" ou "fluvial".

- **Localidades**: Contém informações sobre as localidades, incluindo:
  - `IDLocalidade`: preenchido automaticamente.

Além dos ficheiros principais, poderão ser utilizados outros ficheiros auxiliares.

## 3. Funcionalidades

A aplicação deve incluir as seguintes funcionalidades:

1. **Inserir Praia**: Permite adicionar uma nova praia ao sistema.
2. **Inserir Localidade**: Permite adicionar uma nova localidade ao sistema.
3. **Listar Praias**: Exibe todas as praias registradas.
4. **Listar Localidades**: Exibe todas as localidades registradas.
5. **Listar Praias por Localidade**: Lista as praias de uma única localidade através do `IDLocalidade`.
6. **Procurar Praia**: Permite buscar uma praia específica pelo seu nome.
7. **Alterar Localidade**: Modifica os dados de uma localidade existente utilizando o `IDLocalidade`.
8. **Alterar Praia**: Modifica os dados de uma praia existente utilizando o `IDPraia`.
9. **Exportar Praias para Ficheiro CSV**: Exporta os dados das praias para um arquivo CSV no formato "Nome Localidade;Nome Praia;Tipo Praia".
