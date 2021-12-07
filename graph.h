#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include <fstream>

// This file is for your graph implementation.
// Add everything you need in between the "ifndef and "endif" statements.
// Do not put anything outside those statements
#include <sstream>
struct Graph
{

    double **adjacency_graph;
    int size;
    Graph(std::string fname)
    {
        std::string line;
        std::ifstream input(fname);

        if (input.is_open())
        {
            std::getline(input, line);
            this->size = stoi(line) + 1;
            adjacency_graph = new double *[size];
            for (int x = 0; x < size; x++)
            {
                adjacency_graph[x] = new double[size];
            }

            while (std::getline(input, line))
            {
                std::string word;
                std::stringstream ss(line);
                ss >> word;
                int node = stoi(word);

                while (ss >> word)
                {
                    int other_node = stoi(word);
                    ss >> word;
                    double weight = stod(word);

                    // std::cout << node << " " << other_node << " " << weight << std::endl;
                    adjacency_graph[node][other_node] = weight;
                }
            }
            input.close();
        };
    };

    void testAdjacency(std::string fname)
    {
        std::string line;
        std::ifstream input(fname);

        if (input.is_open())
        {
            while (std::getline(input, line))
            {
                std::string word;
                std::stringstream ss(line);
                
                ss >> word;
                int left = stoi(word);
                
                ss >> word;
                int right = stoi(word);
                
                std::cout << left << " " << right << " " << ((adjacency_graph[left][right] > 0) ? "true":"false") << std::endl;
            }
            input.close();
        };

    }

    void printAdjacencyGraph(){
        for (int x = 1; x < size; x++)
        {
            for (int y = 1; y < size; y++)
            {
                std::cout << adjacency_graph[x][y] << " ";
            }
            std::cout << "" << std::endl;
        }
    };
};

#endif
