#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dl.h"

int main(){
	int fd,flag = 1,no_processes = 1;
	fd = open("process.txt", O_RDONLY);
	char buffer[150],ch[2];
	while (flag > 0){
		int i = 0;
		while (1){
			flag = read(fd, ch, 1);
			if (flag <= 0){
				break;
			}
			if (ch[0] == '\n'){
				no_processes++; 
				strncat(buffer, ":\n", 3);
				continue;
			}
			if (ch[0] == 'P'){
				flag = read(fd, ch, 1);
				flag = read(fd, ch, 1);
				continue;
			}
			if (i == 0)	{ 
				strncpy(buffer, ch, 1);
				i++;
			}else{
				strncat(buffer, ch, 1);
			}
		}
	} 
	if (buffer[strlen(buffer) - 2] == ':')
        no_processes--;
	int no_resources = resource_count(buffer);
	printf("\nString read from file -- \n%s\n\n", buffer);
	printf("Number of Processes: %d\nNumber of Resources: %d\n\n",no_processes,no_resources);
	int no_vertices = no_processes + no_resources;
	char *names[no_vertices],v_name[3];	
	for (int i = 0; i <= no_processes; i++){
		sprintf(v_name, "P%d", i + 1);
		names[i] = strdup(v_name);
		memset(v_name, 0, strlen(v_name));
	}
	int z = 1;
	for (int i = no_processes; i < no_vertices; i++){
		sprintf(v_name, "R%d", z);
		names[i] = strdup(v_name);
		memset(v_name, 0, strlen(v_name));
		z++;
	}
	node graph[no_vertices];
	for (int i = 0; i < no_vertices; i++){
		graph[i].vertex_number = i;
		graph[i].visit_flag = 0;
		strcpy(graph[i].name, names[i]);
		graph[i].next = NULL;
	}
	int process_vertex = 0,swap=0;	
	for (int k = 0; k < strlen(buffer); k++){
		if (buffer[k] == ')'){
			swap = 1;
		}
		if (buffer[k] == ':'){ 
			process_vertex++;
			swap = 0;
		}
		if (isdigit(buffer[k]) && swap == 0){
			int x = buffer[k] + no_processes - 1 - '0';
			new_edge(&graph[x], process_vertex, names);
		}
		if (isdigit(buffer[k]) && swap == 1){
			int x = buffer[k] + no_processes - 1 - '0';
			new_edge(&graph[process_vertex], x, names);
		}
	}
	traverse_adj_list(graph, no_vertices);
	printf("Modified Depth First Search Traversal Path\n");	
	deadlock(graph, no_processes, no_vertices);
	return 0;
}