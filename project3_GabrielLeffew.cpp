/*
Author:           Gabriel Leffew
Major:            Computer Science
Creation Date:    April 16th, 2023
Due Date:         April 25th, 2023
Course:           CSC402 - Data Structures II
Professor Name:   Dr. Zhang
Assignment:       Project 3
Filename:         project3_GabrielLeffew.cpp
Purpose           Read in a file that contains an encode graph, perform a
                  topological sort, and output the sorted vertices.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


/*
Function name: topologicalSort
Description:   Perform a topological sort on a directed graph.
Paramters:     adjList - vector of vectors representing the adjacency list.
               inDegree - vector representing the in-degree of each vertex.
Return Value:  sortedVertices - a vector of integers respresenting the vertices in order
               of topological sort.
*/
vector<int> topologicalSort(vector<vector<int>>& adjList, vector<int>& inDegree) {
    vector<int> sortedVertices;
    queue<int> q;

    // vertices with in-degree 0
    for (int i = 0; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        sortedVertices.push_back(curr);

        // Decrement the in-degree of all adjacent vertices
        for (int i = 0; i < adjList[curr].size(); i++) {
            int neighbor = adjList[curr][i];
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return sortedVertices;
}


/*
Function name: main
Description:   Reads an input file containing a directed graph in adjacency list format, performs a
               topological sort, and outputs the sorted vertices.
Paramters:     none.
Return Value:  0 upon successful completion or 1 if an error occurs.
*/
int main() {
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Error opening file " << fileName << endl;
        return 1;
    }

    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;

    vector<vector<int>> adjList(numVertices);
    vector<int> inDegree(numVertices, 0);

   
    for (int i = 0; i < numEdges; i++) {
        int start, end;
        inputFile >> start >> end;
        adjList[start - 1].push_back(end- 1);
        inDegree[end- 1]++;
    }

    inputFile.close();

    // topological sort
    vector<int> sortedVertices = topologicalSort(adjList, inDegree);

    // Output sorted 
    cout << "Topological sort: ";
    for (int i = 0; i < sortedVertices.size(); i++) {
        cout << sortedVertices[i] + 1;
        if (i != sortedVertices.size() - 1) {
            cout << ", ";
        }
    }
    //check if there was a cycle them output error
    if (sortedVertices.size() < numVertices) {
        cout << " Error: Failed to create path." << endl;
        return 1;
    }
    cout << endl;

    return 0;
}
