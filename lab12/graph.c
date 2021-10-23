#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

char* CreateCityNameString(char* name) {
  char* ptr = (char*)malloc(sizeof(char)*(strlen(name)));
  name[strlen(name)-1] = '\0';
  strcpy(ptr, name);
  return ptr; 
}

void DestroyCityNameString(char* name) {
  free(name); 
}

ListItem* CreateListItem(){
  ListItem* item = (ListItem*)malloc(sizeof(ListItem));
  item->orig_node = NULL;
  item->next_list_item = NULL;
  return item; 
}

void DestroyListItem(ListItem *item) {
  if (item == NULL) return; 
  DestroyListItem(item->next_list_item);
  item->next_list_item = NULL; 
  item->orig_node = NULL; 
  free(item); 
}

Node* CreateNode(char* data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data; 
	
  newNode->neighbor = NULL; 
  newNode->node_id = -1;
  newNode->time_to_node = 10000000;
  newNode->visited = 0;
  newNode->parent = NULL; 
  return newNode; 
}

void DestroyNode(Node *node){
  if (node == NULL) return; 
  DestroyListItem(node->neighbor);
  free(node->data); 
  free(node);
}

Graph* CreateGraph(){
  Graph* out = (Graph*)malloc(sizeof(Graph));
  int i;
  for (i = 0; i < MAX_NUM_NODES; i++){
    out->nodes[i] = NULL; 
  }
  out->num_nodes = 0; 

  return out; 
}

void DestroyListGraph(Graph* graph) {
  int i;
  for (i = 0; i < graph->num_nodes; i++) {
    DestroyNode(graph->nodes[i]); 
  }
  free(graph); 
}

void ResetGraph(Graph* graph) {
  int i;
  for (i = 0; i < graph->num_nodes; i++) {
    graph->nodes[i]->parent = NULL;
    graph->nodes[i]->visited = 0;
    graph->nodes[i]->time_to_node = 10000000;
  }
}

void AddNode(Graph* graph, Node* node){
  node->node_id = graph->num_nodes;
  graph->nodes[graph->num_nodes++] = node; 
}

void AddEdge(Node* u, Node* v, int weight){
  ListItem* listItem = CreateListItem();

  listItem->orig_node = v;
  listItem->next_list_item = u->neighbor;
  listItem->weight = weight; 
  u->neighbor = listItem; 
}

Node* FindNode(Graph* graph, char* city) {
  int i;
  for (i = 0; i < graph->num_nodes; i++) {
    if (strcmp(graph->nodes[i]->data, city) == 0) {
      return graph->nodes[i]; 
    }
  }
  
  Node* newNode = CreateNode(CreateCityNameString(city));
  AddNode(graph, newNode);
  return newNode; 
}
