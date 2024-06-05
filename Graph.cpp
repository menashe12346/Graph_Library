#include "Graph.hpp"

namespace ariel {

    // Constructor definition
    Graph::Graph() {}


    void Graph::loadGraph(const vector<vector<int>> &graph) {
    vector<int> tempVector;
    int i = 0, j = 0;
    // Check if the graph is a square matrix
    if (graph.size() != graph[0].size()) {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    }
    this->matrix.clear(); // Clear the current matrix before loading the new one
    for (const auto &vector : graph) {
        tempVector.clear();
        for (const auto &element : vector) {
            if (i == j && element != 0) {
                throw std::invalid_argument("Invalid graph: cannot be edge between a vertex to itself.");
            }
            tempVector.push_back(element);
            j++;
        }
        this->matrix.push_back(tempVector);
        j = 0;
        i++;
    }
}

    string Graph::printGraph() {
        int size = this->matrix.size();
        int count = 0;
        string graph="";
        for (size_t i = 0; i < size; i++) {
            if(i!=0){graph+="\n";}
            graph+="[";
            for (size_t j = 0; j < size; j++) {
                if(j==0){
                        graph+= to_string(this->matrix[i][j]); // Print the element followed by a space
                } else{
                        graph+= ", " + to_string(this->matrix[i][j]); // Print the element followed by a space
                }
                if (this->matrix[i][j] != 0) {
                    count++;
                }
            }
            graph+="]";
        }
        cout << "Graph with " << size << " vertices and " << count << " edges." << endl;
        return graph;
    }

    Graph& Graph::operator=(const Graph& other) {
        if (this != &other) { // Check for self-assignment
            //resize the matrix and Initialize all elements to 0
            this->matrix.resize(other.matrix.size(), vector<int>(other.matrix[0].size(), 0));

            // Perform matrix assignment
            this->matrix = other.matrix;
        }
        return *this;
    }


    Graph Graph::operator+(const Graph& other) const{
        if (this->matrix.size() != other.matrix.size()) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
        //create copy graph
        Graph output;
        //resize the matrix
        output.matrix.resize(matrix.size(), vector<int>(other.matrix[0].size(), 0));

        for(size_t i=0;i<this->matrix.size();i++){
            for(size_t j=0;j<this->matrix[i].size();j++){
               output.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
            }
        }
        return output;
    }

    void Graph::operator+=(const Graph& other){
        *this = *this + other;
    }

    Graph Graph::operator+() const {
        return *this;
    }

    Graph Graph::operator-(const Graph& other) const{
        //create copy graph
        Graph output;
        //resize the matrix
        output.matrix.resize(matrix.size(), vector<int>(other.matrix[0].size(), 0));

        for(size_t i=0;i<this->matrix.size();i++){
            for(size_t j=0;j<this->matrix[i].size();j++){
            output.matrix[i][j] = this->matrix[i][j] - other.matrix[i][j];
            }
        }
        return output;
    }

    void Graph::operator-=(const Graph& other){
    *this = *this - other;
    }

    Graph Graph::operator-() const {
    Graph copy = *this; //copy of the current graph
    for (auto& vector : copy.matrix) {
        for (auto& num : vector) {
            num = -num;//unary minus operation
        }
    }
    return copy;
    }

    // Function to check if current graph is contained in another graph
    bool Graph::isContainedIn(Graph& other) const {
        if (this->matrix.size() != other.matrix.size()) {
            throw std::invalid_argument("Graphs have different sizes.");
        }
        bool isGreaterThen = false;
        for (size_t i = 0; i < this->matrix.size(); i++) {
            for (size_t j = 0; j < this->matrix[i].size(); j++) {
                if (this->matrix[i][j] != 0 && other.matrix[i][j] != this->matrix[i][j] ) {
                    return false;
                }
                //if there exist at least one edge that is in our matrix and not in the other
                if(this->matrix[i][j] == 0 && other.matrix[i][j] > 0) 
                {
                    isGreaterThen = true;
                }
            }
        }

        return isGreaterThen? true : false;
    }

    int Graph::NumOfEdges(){
        int size = this->matrix.size();
        int count = 0;
        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                if (this->matrix[i][j] != 0) {
                    count++;
                }
            }
        }
        return count;
    }

    bool Graph::operator>(Graph& other){
        //if other graph is in our graph or num of edges in our graph is bigger then other or size of our matrix is bigger then size of other matrix
        if(other.isContainedIn(*this) || this->NumOfEdges() > other.NumOfEdges() || this->matrix.size() > other.matrix.size()){
            return true;
        } 
        return false;
    }

    bool Graph::operator<(Graph& other){
        //if our graph is in other graph or num of edges in other graph is bigger then our graph or size of other matrix is bigger then size of our matrix
        if(this->isContainedIn(other) || this->NumOfEdges() < other.NumOfEdges() || this->matrix.size() < other.matrix.size()){
            return true;
        } 
        return false;
    }

    bool Graph::operator=(Graph& other){
        // if our graph is not greater and not lower then other then its equal
        if(!((*this) > other) && !((*this) < other)){
            return true;
        } 
        return false;
    }

    bool Graph::operator!=(Graph& other){
        if(!((*this)=other)){
            return true;
        } 
        return false;
    }

    bool Graph::operator>=(Graph& other){
        if(((*this) > other) || ((*this) = other)){
            return true;
        } 
        return false;
    }

    bool Graph::operator<=(Graph& other){
        if(((*this) < other) || ((*this) = other)){
            return true;
        } 
        return false;
    }

    Graph& Graph::operator++(){
        for (auto& row : matrix) {
            for (auto& weight : row) {
                ++weight; // Increase each edge weight by 1
            }
        }
        return *this;
    }
    
    Graph Graph::operator++(int){
        Graph temp = *this; //create copy
        ++(*this); // Increase each edge weight by 1
        return temp;
    }

    Graph& Graph::operator--() {
        // Decrease each edge weight by 1
        for (auto& row : matrix) {
            for (auto& weight : row) {
                --weight;
            }
        }
        return *this;
    }

    Graph Graph::operator--(int) {
        Graph temp = *this; //create copy
        --(*this); // Decrease each edge weight by 1
        return temp;
    }

    Graph Graph::operator*(int num) {

        // Create a copy of the current graph
        Graph output = *this;

        // Multiply each element by num
        for (size_t i=0;i<output.matrix.size();i++) {
            for (size_t j=0;j<output.matrix.size();j++) {
                output.matrix[i][j] *= num;
            }
        }
        return output;
    }

    void Graph::operator*=(int num) {
        *this = *this * num;
    }

    Graph Graph::operator*(const Graph& other) const {
        // Check if the num of columns in our graph is equal to the number of rows in the other matrix
        if (this->matrix.size() != other.matrix[0].size()) {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }

        Graph output;

        //resize the matrix and Initialize all elements to 0
        output.matrix.resize(matrix.size(), vector<int>(other.matrix[0].size(), 0));

        // matrix multiplication
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < other.matrix[0].size(); j++) {
                for (size_t k = 0; k < matrix[0].size(); k++) {
                    output.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        return output; 
    }

    void Graph::operator*=(const Graph& other) {
        *this = *this * other;
    }

    Graph Graph::operator/(int num) const{
        // Create a copy of the current graph
        Graph output = *this;

        // Multiply each element by num
        for (size_t i=0;i<output.matrix.size();i++) {
            for (size_t j=0;j<output.matrix.size();j++) {
                output.matrix[i][j] /= num;
            }
        }
        return output;
    }

    void Graph::operator/=(int num) {
        *this = *this / num;
    }

    Graph Graph::operator/(const Graph& other) const {
        // Check if the dimensions of the matrices match
        if (this->matrix.size() != other.matrix.size()) {
            throw std::invalid_argument("matrices must have the same dimensions");
        }

        // invert each element in the matrix
        Graph GraphAfterInvetion = other;
        for (auto& vector : GraphAfterInvetion.matrix) {
            for (auto& element : vector) {
                if (element != 0) {
                    element = 1 / element;
                } else {
                    throw std::invalid_argument("element is zero, Division by zero");
                }
            }
        }

        // same as /
        return (*this) * GraphAfterInvetion;
    }

    void Graph::operator/=(const Graph& other) {
        *this = *this / other;
    }

    /// @brief prints the graph
    /// @param os reference to an existing ostream object( in our case its std::cout for console output)
    /// @param graph prints the graph
    /// @return reference to an ostream object (ostream represent the output streams, such as writing data to the console, files, or other output devices.)
    ostream& operator<<(ostream& os, const Graph& graph) {
        int size = graph.matrix.size();

        // Loop through each vector in the matrix
        for (size_t i = 0; i < size; i++) { 
            os << "[";
            for (size_t j = 0; j < size; j++) {
                if(j==0){
                    os << graph.matrix[i][j]; // Print the element followed by a comma
                }else {
                    os << ", " << graph.matrix[i][j]; // Print the element followed by a comma
                }
            }
            os << "]" << std::endl;
        }
        os << "\n" << std::endl;

        return os;
    }



}
