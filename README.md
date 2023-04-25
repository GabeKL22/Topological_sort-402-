# Topological_sort-402-
## Description
- This a program to perform the topological sort algorithm on a directed graph.
- The files `graph1.dat`, `graph2.dat`, `graph3.dat` contain the `numVertices` and `numEdges` on the first line.. and then vertices to build the graph
- i.e  
14 10 (14 vertices, 10 edges)   
1 3 (signifies an edge from vertex 1 to 3)  
1 4 (signifies an edge from vertex 1 to 4)
## Runnning
- clone the repository `git clone https://github.com/GabeKL22/Topological_sort-402-`
- run the command `g++ project3_GabrielLeffew.cpp -o topological` this will create an executable called topological
- enter `./topological` to run the program
- The program will ask for a file to read in the graph, use any of the `graph.dat` files or feel free to make your own
- If a topological sort can be made (there is not a cycle) it will print out the vertices in order. 
- If it cannot be done (there is a cycle) it will spew out an error. 
