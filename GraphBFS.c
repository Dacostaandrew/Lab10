/*graph.c*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int vertex;
    struct node *next;
} nodeType, *nodeP;


typedef struct adjList {
    int num_members;
    nodeType *head;
} adjListType, *adjListP;

typedef struct recList {
    int num_members;
    nodeType *head;
} recListType, *recListP;


/* Graph structure.*/
typedef struct graph {
    int num_vertices;
    adjListP adjListArr;
    recListP recListArr;
} graphT, *graphP;

inline void err_exit(char *msg) {
    printf("[Fatal Error]: %s \nExiting...\n", msg);
    exit(1);
}

/* Function to create an adjacency list node*/
nodeP createNode(int v) {
    /*

    Allocate memory space to a new node
    newNode's vertex is v
    newNode's next is NULL

    */
}

/* Function to create a graph with n vertices; */
graphP createGraph(int n) {
    /*

    Allocate memory space to a new graph
    n is the number of vertices
    Allocate memory space to each adjList
    each adjList is for a vertex

    */

    /* Create an array of adjacency lists*/

    /* Create an array of reachable node lists*/

}

/*Destroys the graph*/
void destroyGraph(graphP graph) {
    /*

    free memory spaces you have allocated

    */
    if (graph) {
        if (graph->adjListArr) {
            int v;
            /*Free up the nodes*/
            for (v = 0; v < graph->num_vertices; v++) {
                nodeP adjListPtr = graph->adjListArr[v].head;
                while (adjListPtr) {
                    nodeP tmp = adjListPtr;
                    adjListPtr = adjListPtr->next;
                    free(tmp);
                }
            }
            /*Free the adjacency list array*/
            free(graph->adjListArr);
        }
        if (graph->recListArr) {
            int i;
            for (i = 0; i < graph->num_vertices; i++) {
                nodeP recListPtr = graph->recListArr[i].head;
                while (recListPtr) {
                    nodeP tmp = recListPtr;
                    recListPtr = recListPtr->next;
                    free(tmp);
                }
            }
            free(graph->recListArr);
        }

        /*Free the graph*/
        free(graph);
    }
}

/* Adds an edge to a graph*/
void addEdge(graphT *graph, int src, int dest) {
    /* 
	Add an edge from src to dst in the adjacency list 
	*/

}

/* Find all reachable nodes for each node, and construct as list using BFS algorithm*/
/* Notice: the nodes in the reachable list should contains no duplications */
void getReachableNodes(graphT *graph) {
}

/* Function to print both the adjacency and the reachable list of graph*/
void displayGraph(graphP graph) {
    int i;
    printf("\nAdjacency List:\n");
    for (i = 0; i < graph->num_vertices; i++) {
        nodeP adjListPtr = graph->adjListArr[i].head;
        printf("\n%d-> ", i);
        int count = 0;
        while (adjListPtr) {
            if (count > 0) {
                printf(",");
            }
            printf("%d", adjListPtr->vertex);
            adjListPtr = adjListPtr->next;
            count++;
        }
        if (0 == count) {
            printf("NULL");
        }
    }

    printf("\nReachable List:\n");
    for (i = 0; i < graph->num_vertices; i++) {
        nodeP recListPtr = graph->recListArr[i].head;
        printf("\n%d-> ", i);
        int count = 0;
        while (recListPtr) {
            if (count > 0) {
                printf(",");
            }
            printf("%d", recListPtr->vertex);
            recListPtr = recListPtr->next;
            count++;
        }
        if (0 == count) {
            printf("NULL");
        }
    }
}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        fprintf(stderr, "Usage: CreateDirectedGraph data_file.txt the_number_of_vertices\n");
        return 1;
    }

    FILE *fp_data = fopen(argv[1], "rb");
    if (fp_data == NULL) {
        fprintf(stderr, "Error opening %s\n", argv[1]);
        return 1;
    }

    graphP directGraph = createGraph(atoi(argv[2]));

    int src;
    int dst;

    while (!feof(fp_data) && !ferror(fp_data)) {
        if (fscanf(fp_data, "%d %d", &src, &dst) != 2)
            continue;

        addEdge(directGraph, src, dst);
    }

    getReachableNodes(directGraph);

    printf("\nDIRECTED GRAPH");
    displayGraph(directGraph);

    destroyGraph(directGraph);

    return 0;
}
