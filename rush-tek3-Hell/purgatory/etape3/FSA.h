#ifndef FSA_H_
# define FSA_H_

#include <map>
#include "State.h"

class FSA {

    public:
        FSA();
        void setInitialState(State *state);
        State *getInitialState() const;
        void addState(State *state);
        State *operator[](std::string const &id);
    private:
        std::map<std::string, State *> _states;
        State *_initial;
};

#endif

