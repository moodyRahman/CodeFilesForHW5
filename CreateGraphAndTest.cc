#include <iostream>
#include <vector>
#include <string>

#include "graph.h"

using namespace std;

int graphTestDriver(int argc, char **argv) {

    Graph m = Graph(std::string(argv[1]));

    m.testAdjacency(argv[2]);


    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_File>" << "<ADJACENCY_QUERYFILE>" << endl;
		return 0;
    }

    graphTestDriver(argc, argv);

    return 0;
}
