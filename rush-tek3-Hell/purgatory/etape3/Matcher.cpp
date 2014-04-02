#include <iostream>
#include "Matcher.h"

Matcher::Matcher(FSA &fsa) : _fsa(fsa) {

}


bool Matcher::find(std::string const &str, int &nb) const {

    State *currentState = _fsa.getInitialState();
    std::string toto;
    int i = 0;
    while (i < str.size())
    {
        if (currentState->hasEdge(str[i], toto)) {

            currentState = _fsa[toto];
            if (currentState->getFinal()) {

                currentState = _fsa.getInitialState();
                nb++;
            }
        }
        i++;
    }
    if (nb > 0)
        return true;
    return false;
}

bool Matcher::find(std::string const &str) const {

    int nb = 0;

    return find(str, nb);
}
