#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
#define INFINITY 9999
#define size 5

// const int size = 5;

struct edge{
    int u, v;
};

void bellmanFord(int G[size][size], int n, int startnode) {
    int cost[size][size]; // cost of every node from startnode
    int distance[size], path[size]; // distance = distance of node from shortest path
    
    vector<edge*> edgeList;

    int count, min_distance, next_node, i, j;

    /* creating cost matrix and edge list
    if there is a edge between two nodes i, j 
        then cost[i,j] = weight of the edge (i,j)
    else
        cost[i,j] = infinity
    */
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(G[i][j] == 0){
                cost[i][j] = INFINITY;
            }
            else{
                cost[i][j] = G[i][j];
                // creating edge and adding in the edge list
                struct edge* ed = new edge;
                ed->u = i;
                ed->v = j;
                edgeList.push_back(ed); 
            }
        }
    }

    /*
    // printing edges
    edge* temp;
    for(int i=0; i<edgeList.size(); i++){
        temp = edgeList[i];
        cout << temp->u << " " << temp->v << endl;
    }
    */
    
    /* initialising parameters */ 
    for(i=0; i<n; i++) {
        distance[i] = INFINITY;
        path[i] = -1;
    }
    
    distance[startnode] = 0;

    int u, v;
    edge* graph_edge;

    for(int i=0; i<n; i++){
        for(int e=0; e<edgeList.size(); e++){
            graph_edge = edgeList[e];
            u = graph_edge->u;
            v = graph_edge->v;

            // relaxation
            if(distance[u] + cost[u][v] < distance[v]){
                distance[v] = distance[u] + cost[u][v];
                path[v] = u;
            }
        }
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