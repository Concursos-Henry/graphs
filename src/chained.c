#include <stdio.h>
#include <stdlib.h>

struct Node {
    char *nome;
    int n_vizinhos;
    int *custos;
    struct Node* vizinhos;
};

struct Graph {
    int n_nos;
    struct Node* nos;
};

int main() {
    struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
    g->n_nos = 3;

    // aloca três nós
    g->nos = (struct Node*) malloc(sizeof(struct Node) * 3);
    g->nos[0].nome = "Santa Maria";
    g->nos[1].nome = "Cachoeira do Sul";
    g->nos[2].nome = "Frederico Westphalen";

    g->nos[0].n_vizinhos = 2;
    g->nos[1].n_vizinhos = 1;
    g->nos[2].n_vizinhos = 1;

    g->nos[0].vizinhos = (struct Node*) malloc(sizeof(struct Node) * g->nos[0].n_vizinhos);
    g->nos[1].vizinhos = (struct Node*) malloc(sizeof(struct Node) * g->nos[1].n_vizinhos);
    g->nos[2].vizinhos = (struct Node*) malloc(sizeof(struct Node) * g->nos[2].n_vizinhos);

    g->nos[0].custos = (int*) malloc(sizeof(int) * g->nos[0].n_vizinhos);
    g->nos[1].custos = (int*) malloc(sizeof(int) * g->nos[1].n_vizinhos);
    g->nos[2].custos = (int*) malloc(sizeof(int) * g->nos[2].n_vizinhos);

    g->nos[0].custos[0] = 122;  // cachoeira do sul
    g->nos[0].custos[1] = 290;  // frederico westphalen
    g->nos[1].custos[0] = g->nos[0].custos[0];  // santa maria
    g->nos[2].custos[0] = g->nos[0].custos[1];  // santa maria

    g->nos[0].vizinhos[0] = g->nos[1];  // cachoeira do sul
    g->nos[0].vizinhos[1] = g->nos[2];  // frederico westphalen
    g->nos[1].vizinhos[0] = g->nos[0];  // santa maria
    g->nos[2].vizinhos[0] = g->nos[0];  // santa maria

    for(int i = 0; i < g->n_nos; i++) {
        printf(
            "O no %d se chama %s e possui %d vizinhos\n", i,
            g->nos[i].nome, g->nos[i].n_vizinhos
        );
        for(int j = 0; j < g->nos[i].n_vizinhos; j++) {
            printf(
                "\tO vizinho %d do no %s se chama %s e fica a %dkm\n", j,
                g->nos[i].nome, g->nos[i].vizinhos[j].nome, g->nos[i].custos[j]
            );
        }
    }

    return 0;
}