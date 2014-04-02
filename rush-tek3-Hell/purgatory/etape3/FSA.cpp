#include "FSA.h"

FSA::FSA() : _states(), _initial(NULL) {

}

void FSA::setInitialState(State *state) {

    _initial = state;
    addState(state);
}

State *FSA::getInitialState() const {

    return _initial;
}

void FSA::addState(State *state) {

    _states[state->getName()] = state;
}

State *FSA::operator[](std::string const &id) {

    return _states[id];
}
