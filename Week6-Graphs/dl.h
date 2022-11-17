#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
	int vertex_number;
	char name[3];
	int visit_flag;
	struct node *next;
};
typedef struct node node;

void new_edge(node *vertex, int vertex_number, char **names){ 
	node *new_node = (struct node *)(malloc(sizeof(struct node)));	
		new_node->vertex_number = vertex_number;
		strcpy(new_node->name, names[vertex_number]);
		if (vertex->next != NULL)
			new_node->next = vertex->next;
		else
			new_node->next = NULL;

		vertex->next = new_node;	
}

void traverse_adj_list(node *graph, int no_vertices){
	printf("Adjacency List\n");
	for (int i = 0; i < no_vertices; i++){ 
		node *temp = &graph[i];
		printf("%s --> ", temp->name);
		if (temp->next != NULL){
			temp = temp->next;
			while (temp != NULL){ 
				printf("%s", temp->name);
				if (temp->next != NULL){
					printf(", ");
				}
				temp = temp->next;
			}
		}
		printf("\n");
	}
	printf("\n");
}

void deadlock(node *graph, int no_processes, int no_vertices){
	node *process_vertex, *next;
	int counter = 0,deadlocked_processes[no_processes];	 
	for (int i = 0; i < no_processes; i++){ 
		process_vertex = &graph[i];
		printf("%s-->", process_vertex->name);
		process_vertex->visit_flag = 1;
		next = process_vertex->next;
		if (next != 0){
			printf("%s-->", next->name);
		}else{
			continue;
		}		
		while (next != 0){
			next = &graph[next->vertex_number];
			next = next->next;
			if (next == 0){
				break;
			}
			printf("%s-->", next->name);
			if (graph[next->vertex_number].visit_flag == 1 && next->vertex_number != process_vertex->vertex_number){
				break;
			}
			if (graph[next->vertex_number].visit_flag == 1){
				deadlocked_processes[counter] = process_vertex->vertex_number;
				counter++;
				break;
			}
			graph[next->vertex_number].visit_flag = 1;
		}
		printf("\n");
		for (int w = 0; w < no_vertices; w++){
			graph[w].visit_flag = 0;
		}
	}
	if (counter == 0){
		printf("\nNo Deadlocked Process\n");
		return;
	}
	printf("\nDeadlocked Processes: ");
	for (int t = 0; t < counter; t++){
		printf("%s ", graph[deadlocked_processes[t]].name);
	}
	printf("\n\n");
}

int resource_count(char buffer[150]){
	char *copy = malloc(sizeof(char) * 150);
	int count = 0;	
	strcpy(copy, buffer);
	for (int i = 0; i < strlen(copy); i++){
		for (int j = i + 1; copy[j] != '\0'; j++){
			if (copy[j] == copy[i]){
				for (int k = j; copy[k] != '\0'; k++){
					copy[k] = copy[k + 1];
				}
			}
		}
		if (isdigit(copy[i])){
			count++;
		}
	}
	return count;
}