#include <sstream>
#include "State.h"

int State::_num = 0;

State::State(std::string const &ficelle) : _rouge(ficelle), _ing(false), _links()  {

}

void State::setFinal(bool ing) {

    _ing = ing;
}

bool State::getFinal() const {

    return _ing;
}

State *State::create() {

    std::ostringstream streamdemerde;
    streamdemerde << "S";
    streamdemerde << _num++;
    return new State(streamdemerde.str());
}

void State::addLink(Edge *edge, std::string const &ip) {

    _links[edge] = ip;
}

std::map<Edge *, std::string> const &State::getLinks() const {

    return _links;
}

bool State::hasEdge(char c, std::string &toto) const {

    for (std::map<Edge *, std::string>::const_iterator it = _links.begin(); it != _links.end(); ++it)
    {
        if ((*it->first)(c)) {
            toto = it->second;
            return true;
        }
    }
    return false;
}

std::string const &State::getName() const {

    return _rouge;
}
