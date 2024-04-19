# Aula 2 - Construção de Compiladores

## Introdução

Nesta aula, focamos na implementação dos tokens válidos da linguagem Pascal, um passo fundamental no desenvolvimento de um compilador. Cada token na linguagem Pascal representa uma instrução ou um elemento sintático que serve para construir o programa. Abaixo, explicarei cada um dos tokens que foram adicionados ao projeto, que são essenciais para a análise léxica do compilador.

### Tokens da Linguagem Pascal

1. **label**: Em Pascal, `label` é usado para definir um marcador que pode ser referenciado em outras partes do programa, principalmente em comandos de salto como o `goto`. Labels são úteis para controlar o fluxo do programa, especialmente em estruturas de decisão ou loops.

2. **type**: O token `type` é utilizado para definir novos tipos de dados. Por meio dele, é possível criar tipos personalizados que extendem ou modificam tipos existentes, como arrays ou registros, facilitando a manipulação de dados complexos.

3. **array**: `array` refere-se a uma estrutura de dados composta por elementos do mesmo tipo, acessados através de índices. Em Pascal, os arrays são muito utilizados para armazenar e manipular conjuntos de dados de forma eficiente.

4. **procedure**: Uma `procedure` em Pascal é uma sub-rotina que pode ser chamada em diferentes pontos do programa. Ela executa uma tarefa específica e não retorna valor, sendo útil para modularizar o código e reduzir repetições.

5. **function**: Similar a `procedure`, `function` também é uma sub-rotina, mas com uma diferença crucial: ela retorna um valor após sua execução. Isso permite que funções sejam usadas em expressões e atribuições.

6. **goto**: O comando `goto` é utilizado para alterar o fluxo de execução do programa, saltando para um `label` especificado. Apesar de útil, seu uso é desencorajado em programação moderna devido ao potencial de tornar o código mais difícil de seguir e manter.

7. **if**: O `if` é um comando de decisão que permite executar diferentes blocos de código dependendo de uma condição lógica. É um dos fundamentos da programação estruturada, permitindo a implementação de lógicas condicionais.

8. **then**: `then` é usado em conjunto com `if` para indicar o bloco de código que deve ser executado se a condição testada pelo `if` for verdadeira.

9. **else**: `else` complementa o `if`, especificando um bloco de código que é executado quando a condição do `if` não é satisfeita.

10. **while**: O loop `while` permite repetir um bloco de código enquanto uma condição específica for verdadeira. É essencial para operações repetitivas que requerem verificação de condição antes da execução.

11. **do**: Em Pascal, `do` é usado para iniciar o bloco de código que será repetido em estruturas de loop como `while` e `for`.

12. **or**: O operador lógico `or` é usado para combinar duas condições booleanas. Se qualquer uma das condições for verdadeira, o resultado será verdadeiro.

13. **div**: `div` é um operador aritmético que realiza a divisão inteira entre dois números, descartando qualquer resto.

14. **and**: Semelhante a `or`, `and` é um operador lógico que requer que ambas as condições booleanas sejam verdadeiras para que o resultado também seja verdadeiro.

15. **not**: `not` é um operador lógico que inverte o valor booleano de uma condição, transformando verdadeiro em falso e vice-versa.

Ao compreender e implementar esses tokens, avançamos significativamente na construção do nosso compilador para Pascal, preparando o terreno para as próximas etapas de análise sintática e semântica.