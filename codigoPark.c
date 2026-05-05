/*
        Para resolver o problema, foi utilizado o algoritmo de Kruskal em
    conjunto com a estrutura Union-Find (ou Disjoint Set). A ideia é
    ordenar todas as arestas pelo custo e ir escolhendo, sempre que
    possível, a mais barata que não forme ciclo com as que já foram
    selecionadas. Essa checagem é feita de maneira eficiente pelo
    Union-Find.
        Se ao final for possível selecionar exatamente (n − 1) arestas,
    temos uma árvore geradora que conecta todos os pontos e, por
    definição, ela será a de menor custo possível. Caso esse número
    não seja alcançado, significa que o grafo não é conexo e,
    portanto, não existe um planejamento viável para o cenário.

    Análise 
            O  passo mais custoso da solução é a ordenação das m arestas,
        realizada em O(m log m). Depois disso, o algoritmo de Kruskal
        utiliza a estrutura Union-Find para decidir rapidamente se uma
        aresta pode ser incluída na árvore. As operações do Union-Find,
        com compressão de caminho e união por rank, têm custo praticamente
        constante no uso prático.

        Assim, o tempo total por cenário fica dominado pela ordenação
         das arestas, resultando em O(m log m).
*/

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//Estrutura que representa uma tubulação possível entre dois pontos.

typedef struct {
    int pontoA, pontoB;
    int custo;
} Aresta;

//Funções do Union-Find (Disjoint Set)

int encontrar(int pai[], int v) {
    if (pai[v] == v) return v;
    return pai[v] = encontrar(pai, pai[v]);
}

int unir(int pai[], int nivel[], int a, int b) {
    a = encontrar(pai, a);
    b = encontrar(pai, b);

    if (a == b) return 0; //conectados

    if (nivel[a] < nivel[b]) pai[a] = b;
    else if (nivel[a] > nivel[b]) pai[b] = a;
    else {
        pai[b] = a;
        nivel[a]++;
    }
    return 1;
}

//Usada pelo qsort para ordenar arestas por custo crescente.

int compararArestas(const void *x, const void *y) {
    Aresta *A = (Aresta *)x;
    Aresta *B = (Aresta *)y;
    return A->custo - B->custo;
}

//Função principal


int main() {
    int n, m;
    int numeroCenario = 1;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        scanf("%d", &m);

        Aresta *arestas = (Aresta *)malloc(m * sizeof(Aresta));

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &arestas[i].pontoA, &arestas[i].pontoB, &arestas[i].custo);
        }

        // Ordenação das arestas por custo
        qsort(arestas, m, sizeof(Aresta), compararArestas);

        // Inicialização do Union-Find
        int *pai = (int *)malloc((n + 1) * sizeof(int));
        int *nivel = (int *)calloc((n + 1), sizeof(int));

        for (int i = 1; i <= n; i++) pai[i] = i;

        int custoTotal = 0;
        int arestasEscolhidas = 0;

        // Algoritmo de Kruskal
        for (int i = 0; i < m; i++) {
            if (unir(pai, nivel, arestas[i].pontoA, arestas[i].pontoB)) {
                custoTotal += arestas[i].custo;
                arestasEscolhidas++;

                if (arestasEscolhidas == n - 1) break;
            }
        }

        // Verifica se uma MST foi formada
        if (arestasEscolhidas != n - 1)
            custoTotal = -1;

        printf("Cenário %d: %d\n", numeroCenario, custoTotal);

        numeroCenario++;

        free(arestas);
        free(pai);
        free(nivel);
    }

    return 0;
}