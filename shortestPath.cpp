#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

#define INFINITY 9999 
const int size = 5;

/* =================== BELLMAN FORD =================== */
struct edge{
    int u, v;
};
void bellmanFord(int G[size][size], int n, int startnode) {
    int cost[size][size]; // cost of every node from startnode
    int distance[size], path[size]; // distance = distance of node from shortest path
    int i,j;
    vector<edge*> edgeList;

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

/* ================== DIJKSTRA ================ */
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

/* =================== MAIN =================== */


int main(){
    // int size = 5;
    int G[size][size]={{0,1,0,3,10}, {1,0,5,0,0}, {0,5,0,2,1}, {3,0,2,0,6}, {10,0,1,6,0}};

    int graph2[size][size] = {{0, 6, 5, 5, 0},
                        {0, 0, 0, 0, -1},
                        {0, -2, 0, 0, 1},
                        {0, 0, -2, 0, 0},
                        {0, 0, 0, 0, 0}};
    int startNode = 0;

    cout << "========== Dijkstra ==========";
    auto start = high_resolution_clock::now();
    dijkstra(G, size, startNode);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by Dijkstra: "  << duration.count() << " microseconds" << endl;
    cout << endl;

    cout << "\n========== Bellman Ford ==========";
    start = high_resolution_clock::now();
    bellmanFord(graph2, size, startNode);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by Bellman Ford: "  << duration.count() << " microseconds" << endl;
    cout << endl;

    
    return 0;
}