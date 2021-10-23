#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "graph.h"


// Finds a path from source to dest in the provided graph.
// Prints the path out.
// 
// Graph graph: the adjacency-list graph specifying the nodes and edges.
// char* source: name of the source/starting city
// char* dest: name of the dest/ending city
//
// Returns: the time in seconds it takes to get from source to dest
int DoSearch(Graph* graph, char* source, char* dest) {
  // Implement Djikstra's! 
  // Find source node and dest node

  // STEP 0: Replace src_node and dest_node with a call using FindNode()
  Node* src_node = FindNode(graph, source);
  Node* dest_node = FindNode(graph, dest);

  src_node->time_to_node = 0;

  if (src_node == NULL) {
    printf("Couldn't find source node\n"); 
    return -1; 
  }

  Node* curNode = src_node;
  
  while (curNode != NULL) {
    // STEP 1: Mark node as visited, recall not_visited = 0, visited = 1
    curNode -> visited = 1;

    // STEP 2: Update duration to all of the nodes neighbors
    // New dist to neighbor = dist to curNode + edge weight between curNode and neighbor
    ListItem* neighbor = curNode->neighbor;
    while (neighbor != NULL) {
      int new_duration = curNode -> time_to_node + neighbor -> weight;
      int old_duration = neighbor -> orig_node -> time_to_node;
      // If the node has smaller time_to_node
      if (new_duration < old_duration) {
        // TODO: UPDATE neighbor time_to_node
        neighbor -> orig_node -> time_to_node = new_duration;
        // TODO: UPDATE neighbor parent
        neighbor -> orig_node -> parent = curNode;
      }
      neighbor = neighbor->next_list_item;
    }

    
    int minTime = 100000000;
    int minTimeInd = -1;

    // STEP 3: Find the node in the graph that has not yet 
    // been visited, and has the smallest time_to_node. 
    int i;
    for (i = 0; i < graph->num_nodes; i++) {
      // If the unvisited node has the min time_to_node
      Node* curNode = graph -> nodes[i];
      if (curNode -> visited == 0 && curNode -> time_to_node < minTime) {
        // TODO: UPDATE minTime
        minTime = curNode -> time_to_node;
        // TODO: UPDATE minTimeInd
        minTimeInd = i;
      }
    }
    
    

    // When no non-visited nodes have been found, it's time to end. 
    if (minTimeInd == -1) {
      curNode = NULL; 
    } else {
      curNode = graph->nodes[minTimeInd]; 
    }
  }

  PrintListPath(dest_node); 
  return dest_node->time_to_node; 
}


int main(){
  Graph* graph = CreateGraph();
  LoadNodes(graph);
  LoadEdges(graph);

  // Start Node: Seattle, WA
  int res = DoSearch(graph, "Seattle_WA", "Boston_MA"); 
  printf("Time from Seattle, WA to Boston, MA: "); 
  PrintTime(res);
  printf("\n\n\n"); 

  ResetGraph(graph); 
  
  res = DoSearch(graph, "Ann_Arbor_MI", "Minneapolis_MN"); 
  printf("Time from Ann Arbor, MI to Minneapolis, MN: "); 
  PrintTime(res);
  printf("\n"); 
  
  DestroyListGraph(graph);   
  
}
