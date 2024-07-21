
# Graph Implementation Repository 🌐

Welcome to the **Graph Implementation** repository! This repository focuses on providing capabilities for working with graphs, including loading, printing, and performing various algorithms on graphs.

## Table of Contents 📑

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Graph Class](#graph-class)
- [Algorithms Class](#algorithms-class)
- [Implementation Details](#implementation-details)
- [Contact](#contact)

## Introduction 📝

The Graph Operations Library offers a comprehensive set of tools to work with graphs in C++. It includes functionalities for loading graphs, printing graphs, and performing various algorithms.

## Installation 🛠️

To use this library, include the provided header files (`Graph.hpp` and `Algorithms.hpp`) in your C++ project:

```cpp
#include "Graph.hpp"
#include "Algorithms.hpp"
```

## Usage 🚀

Here's a brief overview of how to use the library:

1. **Loading a Graph**: Use the `loadGraph` function of the `Graph` class to load a graph.

    ```cpp
    ariel::Graph graph;
    graph.loadGraph(/* Your graph data */);
    ```

2. **Printing a Graph**: After loading a graph, you can print it using the `printGraph` function.

    ```cpp
    graph.printGraph();
    ```

3. **Performing Algorithms**: Utilize the functions provided by the `Algorithms` class to perform various graph algorithms.

    ```cpp
    ariel::Algorithms::isConnected(graph);
    ariel::Algorithms::shortestPath(graph, source, destination);
    ariel::Algorithms::isContainsCycle(graph);
    ariel::Algorithms::isBipartite(graph);
    ariel::Algorithms::negativeCycle(graph);
    ```

## Graph Class 🌲

The `Graph` class provides functionality for representing and working with graphs. It includes methods for loading and printing graphs, as well as various operators for graph manipulation:

- `operator=`: Assignment operator for assigning one graph to another.
- `operator+`: Addition operator for adding two graphs.
- `operator+=`: Addition and assignment operator for adding another graph to the current graph.
- `operator+()`: Unary plus operator for returning a copy of the graph.
- `operator-`: Subtraction operator for subtracting one graph from another.
- `operator-=`: Subtraction and assignment operator for subtracting another graph from the current graph.
- `operator-()`: Unary minus operator for returning the negation of the graph.
- `isContainedIn`: Function to check if the current graph is contained in another graph.
- `NumOfEdges`: Function to calculate the number of edges in a graph.
- Comparison Operators (`>, <, ==, !=, >=, <=`): Comparison operators for comparing graphs.
- Increment and Decrement Operators (`++, --`): Pre-increment, post-increment, pre-decrement, and post-decrement operators for incrementing and decrementing graph values.
- Multiplication and Division Operators (`*, *=, /, /=`): Operators for multiplying and dividing graphs by scalar values and other graphs.
- `operator<<`: Output stream operator to print the graph matrix.

## Algorithms Class 🔍

The `Algorithms` class contains static methods for performing various graph algorithms, including:

- Connectivity checks (`isConnected`)
- Shortest path finding (`shortestPath`)
- Cycle detection (`isContainsCycle`)
- Bipartiteness check (`isBipartite`)
- Negative cycle detection (`negativeCycle`)

## Implementation Details 🛠️

- **Graph.cpp**: Contains the `Graph` class, which includes methods like `loadGraph` and `printGraph`.
- **Algorithms.cpp**: Contains implementations for various graph algorithms, such as `isConnected`, `shortestPath`, `isContainsCycle`, `isBipartite`, and `negativeCycle`.

## Contact 📧

If you have any questions or suggestions, feel free to reach out!

- **GitHub**: [menashe12346](https://github.com/menashe12346)
- **Email**: [your-email@example.com](mailto:menashe7676@gmail.com)

Thank you for visiting our repository! We hope you find it useful and informative. Happy coding! 😊
