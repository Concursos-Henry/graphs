#include <stdio.h>
#include <stdlib.h>

int main() {
    char **nomes = (char**)malloc(sizeof(char*) * 3);
    nomes[0] = "Santa Maria";
    nomes[1] = "Cachoeira do Sul";
    nomes[2] = "Frederico Westphalen";

    int n_nos = 3;

    int matrix[3][3];

    matrix[0][0] = 0;
    matrix[0][1] = 122;
    matrix[0][2] = 290;
    matrix[1][0] = 122;
    matrix[1][1] = 0;
    matrix[1][2] = -1;  // sem conexão
    matrix[2][0] = 290;
    matrix[2][1] = -1;  // sem conexão
    matrix[2][2] = 0;

    for(int i = 0; i < n_nos; i++) {
        printf("O no %d se chama %s\n", i, nomes[i]);
        int n_vizinhos = 0;
        for(int j = 0; j < n_nos; j++) {
            if(matrix[i][j] > 0) {
                printf(
                    "\tO vizinho %d do no %s se chama %s e fica a %dkm\n",
                    n_vizinhos, nomes[i], nomes[j], matrix[i][j]
                );
                n_vizinhos += 1;
            }
        }
    }
    return 0;
}