#include<iostream>
#include<stdio.h>
using namespace std;
#define INFINITY 9999
#define size 5
// const int size = 5;

/*
Algorithm:
1. Pick the shortest path
2. Perform relaxation of other nodes using shortest path node
*/
// int size;
// void util(int size){
//     size=size;
// }

void dijkstra(int G[size][size], int n, int startnode) {
    int cost[size][size]; // cost of every node from startnode
    int distance[size], path[size], visited[size]; // distance = distance of node from shortest path, path = , visited = holds visited nodes
    int count, min_distance, next_node, i, j;
    
    /* creating cost matrix 
    if there is a edge between two nodes i, j 
        then cost[i,j] = weight of the edge (i,j)
    else
        cost[i,j] = infinity
    */
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }
    
    /* initialising parameters */
    for(i=0; i<n; i++) {
        distance[i] = cost[startnode][i];
        path[i] = startnode;
        visited[i] = 0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
   
    /* finding shortest path */
    while(count<n-1) {
        min_distance=INFINITY;
        // 1. finding the node with shortest path which is not already visited
        for(i=0; i<n; i++) {
            if(distance[i] < min_distance && !visited[i] ) {
                min_distance = distance[i];
                next_node = i;
            }
        }
        visited[next_node] = 1;
        // 2. relaxation method
        for(i=0; i<n; i++){
            if(!visited[i]){
                if(min_distance + cost[next_node][i] < distance[i]) {
                    distance[i] = min_distance + cost[next_node][i];
                    path[i] = next_node;
                }
            }
        }
        count++;
    }
    
    // printing the path
    for(i=0; i<n; i++){
        if(i!=startnode) {
            cout<<"\nDistance of node " << i << " = " << distance[i];
            cout<<"\nPath = " << i;
            j=i;
            do {
                j = path[j];
                cout<<" <- "<<j;
            } while(j!=startnode);
        }
    }
}