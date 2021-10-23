#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include "graph.h"

void LoadNodes(Graph* graph) {
  FILE* cfPtr;

  if ((cfPtr = fopen("nodes.csv", "r")) == NULL) {
    printf("File could not be opened\n");
  } else {
    char c;

    char city_name[100];
    char city_id[6]; 

    // Get rid of hte header row
    fgets(city_name, 100, cfPtr); 
    
    int result;
    int numRecordsRead = 0; 
    while (!feof(cfPtr)) {
      fgets(city_name, 100, cfPtr);
      Node* newNode = CreateNode(CreateCityNameString(&city_name[5])); 
      AddNode(graph, newNode);
      numRecordsRead++;
    }
    fclose(cfPtr);

  }
}

int ToSeconds(int hours, int mins, int seconds) {
  mins = mins + (hours * 60);
  seconds = seconds + (mins * 60);
  return seconds; 
}

void LoadEdges(Graph* graph) {
  // Open the file
  FILE *cfPtr;

  if ((cfPtr = fopen("edges.csv", "r")) == NULL) { // "edges.csv"
    printf("File could not be opened\n");
  } else {
    int result;
    char source_city[100];
    char dest_city[100];
    int hour = -1;
    int min = -1;
    int sec = -1;

    int numLinesRead = 0; 
    
    // Iterate through all the nodes in the graph
    Node* curSource = NULL;
    Node* curDest = NULL; 

      while(!feof(cfPtr)) {
        result = fscanf(cfPtr, "%s %s %d %d %d", source_city, dest_city, &hour, &min, &sec);

        curSource = FindNode(graph, source_city);
        curDest = FindNode(graph, dest_city);
        
        AddEdge(curSource, curDest, ToSeconds(hour, min, sec)); 
      }
    fclose(cfPtr);
  }
}

/*
 * Generally: Start with the destination node;
 * trace the path back using the link to the parent,
 * pushing all the city names into a stack. Then,
 * iterate through and print out the city names. 
 */
void PrintListPath(Node* dest) {
  char* stack_of_cities[NUM_CITIES]; 
  int top = 0;
  stack_of_cities[top++] = dest->data;
  
  Node* pref = dest->parent;
  while(pref != NULL) {
    stack_of_cities[top++] = pref->data; 
    pref = pref->parent; 
  }
  int i;
  for (i = top - 1; i >= 0; i--) {
    printf("%s\n", stack_of_cities[i]);
  }
}

void PrintTime(int seconds) {
  int secs = seconds % 60;
  int mins = ((seconds - secs) / 60) % 60;
  int hrs = ((seconds - secs -(mins * 60)) / 60) / 60;

  printf("%d:%d:%d", hrs, mins, secs); 
}
