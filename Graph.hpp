#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

namespace ariel {
    class Graph {
    public:
        vector<vector<int>> matrix;

        // Constructor
        Graph();

        // Function to load the graph
        void loadGraph(const vector<vector<int>> &graph);

        //Function to print the number of vertices and edges in the graph
        string printGraph();

        // Assignment operator
        Graph& operator=(const Graph& other);

        //plus operator
        Graph operator+(const Graph& other) const;

        //plus and equal operator
        void operator+=(const Graph& other);

        //unari plus operator
        Graph operator+() const;

        //minux operator
        Graph operator-(const Graph& other) const;

        //minux and equal operator
        void operator-=(const Graph& other);

        //unari minux operator
        Graph operator-() const;

        // Function to check if current graph is contained in another graph
        bool isContainedIn(Graph& other) const;

        //calculate the number of edges in a graph
        int NumOfEdges();

        //greater then operator
        bool operator>(Graph& other);

        //lower then operator
        bool operator<( Graph& other);

        //equal operator
        bool operator=( Graph& other);

        //not equal operator
        bool operator!=( Graph& other);

        //greater then or equal operator
        bool operator>=( Graph& other);

        //lower then or equal operator
        bool operator<=( Graph& other);

        // Pre-increment (++graph): Increments the value of x and returns a reference to x itself after the increment.
        Graph& operator++();
        
        // Post-increment (graph++): Increments the value of x but returns a copy of x as it was before the increment.
        Graph operator++(int);

        // Pre-decrement (--graph): Decrements the value of x and returns a reference to x itself after the decrement.
        Graph& operator--();
        
        // Post-decrement (graph--): Decrements the value of x but returns a copy of x as it was before the decrement.
        Graph operator--(int);

        //multiply by num operator 
        Graph operator*(int num);

        //multiply and equal each element by num
        void operator*=(int num);

        // Multiplication operator between graphs
        Graph operator*(const Graph& other) const;

        // Multiplication and equal operator between graphs
        void operator*=(const Graph& other);

        //multiply by num operator 
        Graph operator/(int num) const;

        //multiply and equal each element by num
        void operator/=(int num);

        // Multiplication operator between graphs
        Graph operator/(const Graph& other) const;

        // Multiplication and equal operator between graphs
        void operator/=(const Graph& other);
    };
        // << operator to print the graph matrix
        std::ostream& operator<<(std::ostream& os, const Graph& graph);
}

#endif
