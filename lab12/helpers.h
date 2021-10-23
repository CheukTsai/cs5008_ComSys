#ifndef HELPERS_H
#define HELPERS_H

#include "graph.h"

#define NUM_CITIES 1000


// Loads the nodes from a file into the specified graph
// Source file is hard-coded
//
// Graph graph: the graph to add the nodes to
void LoadNodes(Graph* graph);


// Loads the edges from a file into the specified graph
// Source file is hard-coded
// Graph is assumed not-null
void LoadEdges(Graph* graph);

// Converts a given number of hours, mins, and seconds to seconds.
//
// hours: number of hours
// mins: number of mins
// seconds: number of seconds
//
// Returns: the number of seconds in the specified number of hours, mins and seconds. 
int ToSeconds(int hours, int mins, int seconds);


// Helper function to print the path to a specified ndoe.
// Assumes the DoSearch algorithm has already been run over the
// graph that the specified dest node is in.
// Prints the nodes between the start/source and the specified node.
//
// Node* dest: the terminating node of the path to be printed. 
void PrintListPath(Node* dest);

// =======
// Function prototypes for the matrix implementation

void PrintPath(int source, int dest, int* parents, double* dests);

char* CreateCityNameString(char*);

void LoadGraph(double[][NUM_CITIES], char*);

double FindPath(char*, char*);

void PrintTime(int seconds);


#endif



