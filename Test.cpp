#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("Test graph addition operator") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "[0, 3, 1]\n[3, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph addition assignment operator") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    g1 += g2;
    CHECK(g1.printGraph() == "[0, 3, 1]\n[3, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test unary plus operator") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2 = +g1;
    CHECK(g2.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test graph subtraction operator") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 3, 1},
        {3, 0, 3},
        {1, 3, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 - g2;
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 2]\n[1, 2, 0]");
}

TEST_CASE("Test graph subtraction assignment operator") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 3, 1},
        {3, 0, 3},
        {1, 3, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    g1 -= g2;
    CHECK(g1.printGraph() == "[0, 2, 1]\n[2, 0, 2]\n[1, 2, 0]");
}

TEST_CASE("Test unary minus operator") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2 = -g1;
    CHECK(g2.printGraph() == "[0, -1, 0]\n[-1, 0, -1]\n[0, -1, 0]");
}

TEST_CASE("Test graph containment") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1.isContainedIn(g2) == true);
}

TEST_CASE("Test number of edges") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    CHECK(g1.NumOfEdges() == 4);
}

TEST_CASE("Test greater than operator") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    CHECK((g2 > g1) == true);
}

TEST_CASE("Test less than operator") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    CHECK((g1 < g2) == true);
}

TEST_CASE("Test greater than or equal operator") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    CHECK((g2 >= g1) == true);
}

TEST_CASE("Test less than or equal operator") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    CHECK((g1 <= g2) == true);
}

TEST_CASE("Test pre-increment operator") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    ++g;
    CHECK(g.printGraph() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]");
}

TEST_CASE("Test post-increment operator") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    ariel::Graph g2 = g++;
    CHECK(g2.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
    CHECK(g.printGraph() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]");
}

TEST_CASE("Test multiplication by number operator") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    ariel::Graph g2 = g * 2;
    CHECK(g2.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test multiplication and equal by number operator") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    g *= 2;
    CHECK(g.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test multiplication operator between graphs") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 2, 3},
        {4, 0, 6},
        {7, 8, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 8, 7},
        {6, 0, 4},
        {3, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 * g2;
    CHECK(g3.printGraph() == "[21, 6, 8]\n[18, 44, 28]\n[48, 56, 81]");
}

TEST_CASE("Test multiplication and equal operator between graphs") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 2, 3},
        {4, 0, 6},
        {7, 8, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 8, 7},
        {6, 0, 4},
        {3, 2, 0}};
    g2.loadGraph(graph2);

    g1 *= g2;
    CHECK(g1.printGraph() == "[21, 6, 8]\n[18, 44, 28]\n[48, 56, 81]");
}

TEST_CASE("Test division by number operator") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g.loadGraph(graph);

    ariel::Graph g2 = g / 2;
    CHECK(g2.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test division and equal by number operator") {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g.loadGraph(graph);

    g /= 2;
    CHECK(g.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
        ariel::Graph g1;
        g1.loadGraph(graph);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
        ariel::Graph g2;
        g2.loadGraph(graph2);

    ariel::Graph g3 = g1 + g2;
    CHECK(ariel::Algorithms::isBipartite(g3) == "0");
}