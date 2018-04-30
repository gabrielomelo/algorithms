/*
 *      Author: Gabriel Melo.
 *      License: MIT.
 *      Link: github.com/gabrielomelo
 *
 *      Algoritmo de Dijkstra.
 *      Implementação em C++ sem POO.
 *
 *      Esta implementação utiliza-se de uma matriz de adjacência para
 *      representar o grafo. O objetivo é computar o menor caminho para todos
 *      os vértices.
 * 
 *      Entrada: grafo e origem.
 *      Saída: Menor Caminho para os vértices adjacentes.
 *
 *      Para mais informações mande um e-mail para: dev.gabrielomelo@gmail.com.
 * */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define GRAPH_SIZE 5
#define INFINITY INT_MAX / 2

int* dijkstra(int graph[GRAPH_SIZE][GRAPH_SIZE], int dist[GRAPH_SIZE], int origin) {
    
    //Inicializa as variaveis de localização.
    int remains = GRAPH_SIZE, anchor;
    int checked[GRAPH_SIZE];

    for (int i = 0; i < GRAPH_SIZE; i++) {
        dist[i] = INFINITY;
        checked[i] = false;
    }
    dist[origin] = 0;

    //Itera dentro de todos os vértices e descobre a menor distância
    while (remains != 0) {
        anchor = -1;
        
        for (int i = 0; i < GRAPH_SIZE; i++)
            if(!checked[i] && (anchor == -1 || dist[i] < dist[anchor]))
                anchor = i;
        
        checked[anchor] = true;

        if(dist[anchor] == INFINITY) break;
        
        for(int i = 0; i < GRAPH_SIZE; i++)
            if((dist[i] > dist[anchor] + graph[anchor][i]) && (graph[anchor][i] != 0))
                dist[i] = dist[anchor] + graph[anchor][i];

        remains--;
    }
    
    return dist;
}


int main(void) {

    int graph[GRAPH_SIZE][GRAPH_SIZE] = {
        {0, 4, 0, 3, 0},
        {4, 0, 9, 0, 0},
        {0, 9, 0, 7, 4},
        {3, 0, 7, 0, 2},
        {0, 0, 4, 2, 0}
    }, dist[GRAPH_SIZE];
    
    dijkstra(graph, dist, 4);
    
    for (int i = 0; i < GRAPH_SIZE; i++)
        printf("%d\n", dist[i]);

    return 0;
}
