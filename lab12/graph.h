

#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NUM_NODES 10000

#define VISITED 1
#define NOT_VISITED 0

// ==============================================
// Structs and prototypes.

typedef struct listItem ListItem;

typedef struct node Node; 

// A node in the list that represents neighbors of a current node
struct node{
  // The data of that node (the city name)
  char* data;
  // The next item in this linked list
  ListItem* neighbor;
  // Helper field for algorithms using this node
  int node_id;
  // Shortest time to get to this node
  int time_to_node;
  // Whether the node has been visited in this traversal yet
  int visited;
  // The parent that gives this node it's time_to_node
  Node* parent;
}; 

// An adjacency-list representation of a graph
struct graph{
  Node* nodes[MAX_NUM_NODES];
  int num_nodes;
};

typedef struct graph Graph;


struct listItem{
  Node* orig_node;
  int weight; 
  ListItem* next_list_item; 
};




// Creates a new graph, mallocing the required space.
// Caller is responsible for freeing the graph later by
// calling DestroyListGraph()
//
// Returns: a pointer to the new graph
Graph* CreateGraph();

void DestroyGraph(Graph* graph); 

// Creates a new list item, mallocing the required space.
// Caller is responsible for freeing the list item by
// calling DestoryListItem()
//
// Returns: a pointer to a list item
ListItem* CreateListItem();

// Destroys a specified listItem. Cleans up any pointers
// and memory allocated for this listItem.
//
void DestroyListItem(ListItem *item);

// Creates a new node, mallocing the required space.
// Caller is responsible for freeing the node later
// by calling DestroyNode()
//
// Returns: a pointer to the new node
Node* CreateNode(char* data);

// Destroys a specified node
//
void DestroyNode(Node *node);

// Destroys the adjacency-list graph provided. 
void DestroyListGraph(Graph* graph);


// Finds a node in the given graph with the specified name
// Graph graph: a created graph
// char* city: the name of the city to find
//
// Returns: a link to the node with city name
Node* FindNode(Graph* graph, char* city);


void AddNode(Graph* graph, Node* node);


void AddEdge(Node* u, Node* v, int weight);

void ResetGraph(Graph* graph);

#endif
