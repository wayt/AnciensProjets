#include "Edge.h"

Edge::Edge(char bon) : _bon(bon) {
}

bool Edge::operator==(Edge const &bon) const {

    return _bon == bon._bon;
}

bool Edge::operator==(char bon) const {

    return _bon == bon;
}

bool Edge::operator()(char bon) const {

    return _bon == bon;
}
