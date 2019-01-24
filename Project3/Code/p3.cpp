#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <limits.h>


using namespace std;
int noOfComponents;
struct adjNode{
	int val;
	struct adjNode *next;
};

struct adjVerticeList{
	struct adjNode *vertexHead;
};

struct adjVerticeList* init(int verticesCount) {
	struct adjVerticeList *verticesList = new adjVerticeList[verticesCount];
	for(int i = 0 ; i< verticesCount ; ++i) {
		verticesList[i].vertexHead = NULL;
	}
	return verticesList;
}

struct adjNode* createNode(int value) {
	struct adjNode* newNode = new adjNode;
	newNode->val = value;
	newNode->next = NULL;
	return newNode;
}

void addEdge(adjVerticeList* adjacencyList,int vertex1,int vertex2) {
	if(vertex1!=vertex2) {
		adjNode *node1 = createNode(vertex1);
		adjNode *node2 = createNode(vertex2);
		adjNode *temp = new adjNode;

		if(adjacencyList[vertex1].vertexHead == NULL){
			adjacencyList[vertex1].vertexHead = node1;
			node1->next = node2;
		}else{
			temp = adjacencyList[vertex1].vertexHead->next;
			adjacencyList[vertex1].vertexHead->next = node2;
			node2->next = temp;

		}
		node1 = createNode(vertex1);
		node2 = createNode(vertex2);

		if(adjacencyList[vertex2].vertexHead == NULL){
			adjacencyList[vertex2].vertexHead = node2;
			node2->next = node1;
		}else{
			temp = adjacencyList[vertex2].vertexHead->next;
			adjacencyList[vertex2].vertexHead->next = node1;
			node1->next = temp;

		}
	}
}

void printAdjList(adjVerticeList* source, int vertices){
	for (int i = 0; i < vertices; ++i)
	{
		adjNode *temp = source[i].vertexHead;
		while(temp != NULL) {
			if(temp->next==NULL){
				cout << temp->val;
			}
			else {
				cout << temp->val << "->";
			}
			temp = temp->next;		
		}
		cout << endl;
	}
}
void DFS(adjVerticeList* adjList, bool* visited, int vertex, int* components,int count) {
    visited[vertex] = true;
    noOfComponents++;
    adjNode *temp= adjList[vertex].vertexHead;
    while(temp != NULL) {
        if(visited[temp->val] == false) {
            DFS(adjList,visited,temp->val,components,count);
        }
        temp = temp->next;
    }
    components[count] = noOfComponents;
}

void findComponents(adjVerticeList* adjList, int vertices, bool* visited, int* components){
    int count = 0;
    for(int i = 0; i<vertices;i++) {
        visited[i] = false;
    }
    for(int i = 0; i<vertices; i++) {
        
        if(visited[i] == false) {
            noOfComponents = 0;
            DFS(adjList,visited,i,components,count);
            count++;
        }
    }
    for(int i = 0 ; i< count ; i++){
        cout<< "Component " << i+1 << " : " << components[i] << endl; 
    }
}

void DFSForList(adjVerticeList* adjList, bool* visited, int vertex, int* components,int count,bool* connectedVertices) {
    visited[vertex] = true;
    connectedVertices[vertex] = true;
    noOfComponents++;
    adjNode *temp= adjList[vertex].vertexHead;
    while(temp != NULL) {
        if(visited[temp->val] == false) {
            DFSForList(adjList,visited,temp->val,components,count,connectedVertices);
        }
        temp = temp->next;
    }
    components[count] = noOfComponents;
}

void printSpanningTree(int* parent, int noOfNodes,int** space){
	cout<< "Minimum Spanning tree :";
	for(int i=0;i<noOfNodes;i++){
		if(parent[i]!= INT_MAX && parent[i] !=-1) {
			cout<< parent[i] << "->"<<i << endl;
		}
	
	}
	
//	for(int i=1;i<noOfNodes;i++){
//		if(parent[i]!= INT_MAX) {
//			if(space[parent[i]][i] == 1) {
//				cout<< i << "->"<< parent[i] << endl;
//			}
//		}
//	
//	}
//	for(int i=0;i<noOfNodes;i++){
//		if(space[i][parent[i]] == 1){
//			cout<< i << "->"<< parent[i];
//		}
//	}
	cout<<"*********************************" << endl;
}

void spanningTree(adjVerticeList* adjList, int vertices, bool* connectedVertices) {
	int **space = new int*[vertices];
	bool spanningTree[vertices];
	int parent[vertices];
	for(int i = 0 ; i<vertices; i++) {
		space[i] = new int[vertices];
	}
	for(int i = 0; i< vertices; i++) {
		for(int j = 0; j< vertices; j++) {
			space[i][j] = INT_MAX;
		}
		space[i][i] = 0;
	}
	int noOfNodes = 0;
	int rootVertex = 0;
	for (int i = 0; i < vertices; ++i) {
		spanningTree[i] = true;
		parent[i] = INT_MAX;
		if(connectedVertices[i]) {
			noOfNodes++;
			spanningTree[i] = false;
			//cout<< i ;
			adjNode *temp = adjList[i].vertexHead;
			while(temp != NULL) {
			space[i][temp->val] = 1;
			rootVertex = i;
			//cout<< " I existed";
			temp = temp->next;		
			}
		}
	}

	int pivot[vertices];

	for(int i = 0; i< vertices; i++) {
		pivot[i] = INT_MAX;
		spanningTree[i] = false;
	}
	pivot[rootVertex] = 0; 
	parent[rootVertex] = -1;
	
	for(int i = 0; i< vertices-1; i++) {
		int min = INT_MAX; 
		int minIndex;
		for(int j = 0; j< vertices ; j++) {
			if(spanningTree[j]==false && pivot[j]< min) {
				min = pivot[j];
				minIndex = j;
			} 
		}
		spanningTree[minIndex] = true;
		for(int k = 0; k< vertices ; k++) {
			if(space[minIndex][k] && !spanningTree[k] && space[minIndex][k] < pivot[k]) {
				parent[k] = minIndex;
				pivot[k] = space[minIndex][k];
			}
		}
	}
	printSpanningTree(parent,vertices,space);
	
}

bool checkSAndTargetConnection(adjVerticeList* adjList,int vertices,int sourceVertex,int destinationVertex) {
	int count = 0;
	bool *visited = new bool[vertices];
	bool *connectedVertices = new bool[vertices];
    for(int i = 0; i<vertices;i++) {
        visited[i] = false;
         connectedVertices[i] = false;
    }
    int *components = new int[vertices];
    DFSForList(adjList,visited,sourceVertex,components,count,connectedVertices);
    return connectedVertices[destinationVertex];
}
void findComponentList(adjVerticeList* adjList, int vertices, bool* visited, int* components,bool* connectedVertices){
    int count = 0;
    for(int i = 0; i<vertices;i++) {
        visited[i] = false;
    }
    for(int i = 0; i<vertices; i++) {
        
        if(visited[i] == false) {
            noOfComponents = 0;
            for(int j = 0; j<vertices;j++) {
        		connectedVertices[j] = false;
    		}
            DFSForList(adjList,visited,i,components,count,connectedVertices);
            count++;
//            for(int k = 0 ; k<vertices ; k++) {
//            	if(connectedVertices[k]) {
//            		cout<< k <<" ";
//				}
//			}
            spanningTree(adjList,vertices,connectedVertices);
            //cout<< "imout" ;
        }
    }
}
void degreeDistribution(adjVerticeList* adjList, int vertices) {
    int *degree = new int[vertices];
    for(int i = 0; i<vertices;i++) {
    	degree[i] = 0;
	}
    
    for(int i = 0; i<vertices ; i++) {
        int sum = -1; 
        adjNode *tempNode = adjList[i].vertexHead;
        while(tempNode!=NULL) {
            sum++;
            tempNode = tempNode->next;
            
        }
        degree[sum] = degree[sum] + 1 ;
    }
//    	for (int i = 0; i < vertices; i++) {
//				cout << "Degree of " << i << ": " << degree[i] << "\n";
//			}

    int x = vertices;
    int y = 0;
    for(int i = vertices-1 ; i>=0 ; i--) {
        if(degree[i]>y) {
            y = degree[i];
        } else if(degree[i] == 0) {
            x = x-1;
        }
    }
    for(int i=y ;i>=0;i--) {
        cout<< i << '\t';
        for(int j=0; j<vertices;j++) {
        	if(degree[j] ==0){
        		continue;
			}
            if(degree[j]>=i) {
                //U+2591
                cout<<"\u2588";
            } else{
                cout<< ' ';
            }
        }
        cout<< endl;
    }
     cout<<'\t';
    for(int i = 0 ; i<vertices; i++) {
    	if(degree[i] !=0){
    		 cout<< i ;
		}
    }
    cout<<endl;
}

void printShortestPath(int shortestPath[], int vertices,int sourceVertex,int destinationVertex) {
	bool stop = true;
	int path[vertices];
	cout<< "The shortest path is given: " << "->" ;
	int index = destinationVertex;
	path[0] = destinationVertex;
	int i = 1;
	while(stop) {
		index = shortestPath[index];
		path[i] = index;
		if(index == sourceVertex) {
			stop = false;
		}
		i++;
	}
	i--;
	while(i>0){
		cout<< path[i] << "->";
		i--;
	}
	cout<< path[0] ;
	cout<< endl;
}

bool complete(bool visited[], int vertices) {
	for(int i = 0 ; i< vertices; i++) {
		if(!visited[i]) {
			return false;
		}
	}
	return true;
}
void findShortestPath (adjVerticeList* adjList, int vertices, int sourceVertex, int destinationVertex) {
	bool visited[vertices];
	int cost[vertices];
	int shortestPath[vertices];
	int source = sourceVertex;
	
	for(int i = 0 ; i<vertices; i++) {
		cost[i] = INT_MAX;
		visited[i] = false;
	}
	cost[sourceVertex] = 0;
	bool notFoundPath = true;
	while(!complete(visited,vertices) && notFoundPath) {
		int closestVertex;
		int smallestValue = INT_MAX;
		for(int i = 0 ; i< vertices; i++) {
			if(!visited[i] && cost[i] <=smallestValue) {
				closestVertex = i;
				smallestValue = cost[closestVertex];
			}
		}
		
		adjNode* tempNode = adjList[closestVertex].vertexHead;
		while(tempNode) {
			if(!visited[tempNode->val] && (cost[closestVertex]+1 < cost[tempNode->val])){
				cost[tempNode->val] = cost[closestVertex] + 1;
				shortestPath[tempNode->val] = closestVertex;
				//visited[tempNode->val] = true;
			}
			tempNode = tempNode->next;
		}
		visited[closestVertex] = true;
		if(cost[destinationVertex] != INT_MAX) {
			notFoundPath = false;
		}
	}
	//for(int i = 0 ; i< vertices; i++) {
	//	cout<< shortestPath[i] << "  "<<endl;
	//}
	cout<< "Length of shortest path from s to t: " << cost[destinationVertex] << endl;
	printShortestPath(shortestPath,vertices,sourceVertex,destinationVertex);
	
}

void findDiameter(adjVerticeList* adjList, int vertices) {
	int **space= new int*[vertices];
	for(int i = 0; i< vertices; i++) {
		space[i] = new int[vertices];
	}
	for(int i = 0; i< vertices; i++) {
		for(int j = 0; j< vertices; j++) {
			space[i][j] = INT_MAX;
		}
		space[i][i] = 0;
	}
	//cout<< " Please execute" ;
	for (int i = 0; i < vertices; ++i)
	{
		adjNode *temp = adjList[i].vertexHead;
		while(temp != NULL) {
			space[i][temp->val] = 1;
			//cout<< " I existed";
			temp = temp->next;		
		}
	}
	int diameter = INT_MIN;
	for(int k = 0 ; k< vertices; k++) {
		for(int i = 0; i< vertices; i++) {
			for(int j= 0 ; j<vertices; j++) {
				if( space[i][k] != INT_MAX && space[k][j] != INT_MAX && space[i][k]+space[k][j] < space[i][j]) {
					space[i][j] = space[i][k]+space[k][j];
					if(diameter < space[i][j]) {
						diameter = space[i][j];
					}
				}
			}
		}
	}
   cout<< "Diameter : " << diameter << endl;
}
int main(){
	int vertices;
	int edges;
	cin>> vertices;
	cin>> edges;

	int vertex1;
	int vertex2;
	
	adjVerticeList *adjList = init(vertices);
	for (int i = 0; i< edges; i++) {
		cin>>vertex1;
		cin>> vertex2;
		addEdge(adjList,vertex1,vertex2);
	}
	//printAdjList(adjList, vertices);
	int noOfCommands;
	cin>>noOfCommands;
	string command;
	while(noOfCommands>0){
	    cin>>command;
	    if(command == "degree-distribution") {
	        degreeDistribution(adjList,vertices);
	    } else if(command == "components") {
	        bool *visited = new bool[vertices];
	        int *components = new int[vertices];
	        findComponents(adjList,vertices,visited,components);
	    } else if(command == "shortest-path") {
	    	int sourceVertex;
	    	int destinationVertex;
	    	cin>>sourceVertex;
	    	cin>>destinationVertex;
	    	//cout<< "Before the source target";
	    	if(checkSAndTargetConnection(adjList,vertices,sourceVertex,destinationVertex)) {
	    		findShortestPath(adjList,vertices,sourceVertex,destinationVertex);
			} else {
				cout << "Source and Target does not belong to same component. Hence, shortest path can not be computed for given S and T"<<endl;
			}
	    	
		} else if(command == "diameter") {
//			cout<< "Im here" ;
	    	findDiameter(adjList,vertices);
	    	//cout<< endl;
		} else if(command == "spanning-tree") {
			bool *visited = new bool[vertices];
	        int *components = new int[vertices];
	        bool *connectedVertices = new bool[vertices];
			findComponentList(adjList,vertices,visited,components,connectedVertices);
		} 
	    noOfCommands--;
	}
	return 0;
}

