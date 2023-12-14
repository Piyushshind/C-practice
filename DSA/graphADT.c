// Write a program to create a graph ,use the map any city as a graph.Represent
// graph using adjacency list/adjacency matrix and perform DFS or BFS.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NODES 7
// Structure to represent a node in the adjacency list
struct Node
{
    int data;
    struct Node *next;
};
int i, j;
// Structure to representthe adjacency list
struct AdjList
{
    struct Node *
        head;
};
// Structure to represent the graph
struct Graph
{
    int numNodes;
    struct AdjList *array;
};
// Function to create a new graph with a given number of nodes
struct Graph *createGraph(int nodes)
{
    struct
        Graph *graph = (struct Graph *)malloc(sizeof(struct
                                                     Graph));
    graph->numNodes = nodes;
    // Allocate memory for an array of adjacency lists
    graph->array = (struct AdjList *)malloc(nodes *
                                            sizeof(struct AdjList));
    // Initialize each adjacencylist as empty
    for (i = 0; i < nodes; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}
// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add an edge from src to dest
    struct Node *
        newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head =
        newNode;
    // Add an edge from dest to src (since thegraph is undirected)
    newNode = (struct
               Node *)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
// Function to perform Depth First Search (DFS)
void dfs(struct Graph *graph, int node, bool visited[])
{
    if (!visited[node])
    {
        printf("%d", node + 1);
        visited[node] = true;
        struct Node *current = graph->array[node].head;
        while (current != NULL)
        {
            dfs(graph,
                current->data, visited);
            current = current->next;
        }
    }
}
