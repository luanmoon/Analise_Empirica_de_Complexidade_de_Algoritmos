# Análise Empírica de Complexidade de Algoritmos

Este repositório contém implementações de algoritmos de ordenação e busca, juntamente com funções para a análise empírica de sua complexidade.

## Algoritmos

### Bubble Sort (Ordenação por Bolha)
O Bubble Sort é um algoritmo de ordenação simples que percorre repetidamente a lista, compara elementos adjacentes e os troca se estiverem na ordem errada. A passagem pela lista é repetida até que a lista esteja ordenada.

- **Complexidade de Tempo:**
    - **Pior Caso:** $O(n^2)$
    - **Caso Médio:** $O(n^2)$
    - **Melhor Caso:** $O(n)$
- **Complexidade de Espaço:** $O(1)$

### Insertion Sort (Ordenação por Inserção)
O Insertion Sort é um algoritmo de ordenação que constrói a matriz ordenada final um item de cada vez. É muito menos eficiente em listas grandes do que algoritmos mais avançados, como quicksort, heapsort ou merge sort.

- **Complexidade de Tempo:**
    - **Pior Caso:** $O(n^2)$
    - **Caso Médio:** $O(n^2)$
    - **Melhor Caso:** $O(n)$
- **Complexidade de Espaço:** $O(1)$

### Busca Sequencial
A Busca Sequencial é um método para encontrar um elemento em uma lista. Ela verifica sequencialmente cada elemento da lista até que uma correspondência seja encontrada ou a lista inteira tenha sido pesquisada.

- **Complexidade de Tempo:**
    - **Pior Caso:** $O(n)$
    - **Caso Médio:** $O(n)$
    - **Melhor Caso:** $O(1)$
- **Complexidade de Espaço:** $O(1)$

### Busca Binária
A Busca Binária é um algoritmo de busca eficiente que encontra a posição de um valor alvo dentro de uma matriz ordenada. A busca binária compara o valor alvo com o elemento do meio da matriz. Se não forem iguais, a metade em que o alvo não pode estar é eliminada e a busca continua na metade restante, novamente pegando o elemento do meio para comparar com o valor alvo e repetindo isso até que o valor alvo seja encontrado.

- **Complexidade de Tempo:**
    - **Pior Caso:** $O(\log n)$
    - **Caso Médio:** $O(\log n)$
    - **Melhor Caso:** $O(1)$
- **Complexidade de Espaço:** $O(1)$

## Funções

### `Normalizar`
A função `Normalizar` é usada para escalar os dados de tempo de execução ou tamanho de entrada para um intervalo padrão, como entre 0 e 1. A normalização é útil ao comparar o desempenho de diferentes algoritmos ou ao preparar dados para visualização.

### `calcular erro`
A função `calcular erro` é usada para calcular a diferença entre os tempos de execução observados e os tempos de execução previstos por um modelo de complexidade teórica. Isso ajuda a avaliar o quão bem o modelo teórico se ajusta aos dados empíricos.

### `melhorAjuste`
A função `melhorAjuste` implementa um método de ajuste de curva para encontrar a função que melhor descreve a relação entre o tamanho da entrada e o tempo de execução. Isso pode ser usado para determinar empiricamente a complexidade de tempo de um algoritmo.
