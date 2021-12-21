// #define size 5

#include "dijkstra.h"
#include "bell.h"
// #define INFINITY 9999

int main(){
    int size = 5;
    int G[size][size]={{0,1,0,3,10}, {1,0,5,0,0}, {0,5,0,2,1}, {3,0,2,0,6}, {10,0,1,6,0}};

    int graph2[size][size] = {{0, 6, 5, 5, 0},
                        {0, 0, 0, 0, -1},
                        {0, -2, 0, 0, 1},
                        {0, 0, -2, 0, 0},
                        {0, 0, 0, 0, 0}};
    int n=5;
    int u=0;

    cout << "Dijkstra\n";
    // util(n);
    dijkstra(G,n,u);
    cout<<endl;

    cout << "Bellman Ford\n";
    bellmanFord(graph2, n, u);
    cout<<endl;
    return 0;
}