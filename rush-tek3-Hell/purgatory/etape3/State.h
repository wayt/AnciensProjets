#ifndef STATE_H_
# define STATE_H_

#include <map>
#include <string>
#include "Edge.h"

class State {

    public:
        State(std::string const &ficelle = "");
        void setFinal(bool ing);
        bool getFinal() const;
        static State *create();
        void addLink(Edge *edge, std::string const &ip);
        std::map<Edge *, std::string> const &getLinks() const;
        std::string const &getName() const;
        bool hasEdge(char c, std::string &toto) const;

    private:
        std::string _rouge;
        bool _ing;
        std::map<Edge *, std::string> _links;
        static int _num;
};

#endif

