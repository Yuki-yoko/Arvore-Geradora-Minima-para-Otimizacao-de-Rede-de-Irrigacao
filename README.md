# Arvore-Geradora-Minima-para-Otimizacao-de-Rede-de-Irrigacao
Este projeto resolve um problema de otimização em grafos voltado ao planejamento eficiente de redes de irrigação.

Dado um conjunto de pontos de plantio e possíveis conexões entre eles, o objetivo é determinar o menor custo necessário para garantir que todas as plantas estejam conectadas, permitindo o fluxo de água entre quaisquer pares.

O problema é modelado como um grafo não direcionado ponderado, onde:

- Os vértices representam pontos de plantio
- As arestas representam possíveis tubulações
- Os pesos correspondem ao custo de instalação

A solução consiste em encontrar uma estrutura que conecte todos os vértices com o menor custo total possível.

## Como funciona

O algoritmo identifica uma Árvore Geradora Mínima (Minimum Spanning Tree - MST), garantindo:

- Conectividade total entre todos os pontos
- Utilização de exatamente n - 1 conexões
- Custo total mínimo

Caso não seja possível conectar todos os pontos (grafo desconexo), o algoritmo retorna que não existe solução viável.

## Saída do algoritmo

Para cada cenário analisado, o programa retorna:

- O custo mínimo da rede de irrigação, quando existe solução viável
- -1, quando não é possível conectar todos os pontos

## Tecnologias utilizadas
- C
- Estruturas de dados (Union-Find / Disjoint Set)
- Algoritmos em grafos
- Kruskal
