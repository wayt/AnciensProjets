#ifndef EDGE_H_
# define EDGE_H_

class Edge {
 public:
    Edge(char bon);
    bool operator==(Edge const &) const;
    bool operator==(char) const;
    bool operator()(char bon) const;
 private:
    char _bon;
};

#endif

