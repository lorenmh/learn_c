#include <vector>

class Vertex {
  private:
    int value;
    std::vector<Vertex *> edges;
  public:
    int getValue();
    std::vector<Vertex *> getEdges();
    void connectTo(Vertex *);
    void disconnectFrom(Vertex *);
};

class Graph {
  private:
    std::vector<Vertex *> vertices;
  public:
    std::vector<Vertex *> getVertices();
    std::vector< std::vector<Vertex *> > getAllEdges();
};

int main( int argc, char *argv[] ) {

}
