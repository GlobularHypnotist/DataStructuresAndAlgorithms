//program to draw a graph
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

#define Max_Vertices 10

typedef struct{
	int x, y;
}Point;
//function to draw vertices
void drawVertex(int x, int y){
	circle(x, y, 2);
	floodfill(x, y, WHITE);
}
//function to draw edges
void drawEdge(Point vertices[], int start, int end){
	line(vertices[start].x, vertices[start].y, vertices[end].x, vertices[end].y);
}

int main(){
	int i, numVertices, numEdges;
	Point vertices[Max_Vertices];
	//initialize graphics
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	//input the number of vertices in the graph
	printf("Enter the number of vertices: ");
	scanf("%d", &numVertices);
	//input the coordinates of each vertex
	printf("Enter the coordinates of each vertex (x, y): \n");
	for(i = 0; i < numVertices; i++){
		scanf("%d%d", &vertices[i].x, &vertices[i].y);
		//draw the vertex on screen
		drawVertex(vertices[i].x, vertices[i].y);
	}
	//input the number of edges in the graph
	printf("Enter the number of edges: ");
	scanf("%d", &numEdges);
	//input the vertices that each edge connects
	printf("Enter the vertices connecting each edge: \n");
	for(i = 0; i < numEdges; i++){
		int start, end;
		scanf("%d%d", &start, &end);
		//draw the edge on screen
		drawEdge(vertices, start - 1, end - 1);
	}
	getch();
	closegraph();
	return 0;
}
