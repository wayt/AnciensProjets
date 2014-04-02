#include <iostream>
#include "Matcher.h"
#include "FSA.h"

int main(int ac, char **av) {

    if (ac != 2) {

        std::cout << "Usage ; " << av[0] << " string" << std::endl;
        return 0;
    }

    FSA fsa;

    State *start = State::create();
    State *m = State::create();
    start->addLink(new Edge('m'), m->getName());
    State *e = State::create();
    m->addLink(new Edge('e'), e->getName());
    State *c = State::create();
    e->addLink(new Edge('c'), c->getName());
    c->setFinal(true);

    fsa.setInitialState(start);
    fsa.addState(m);
    fsa.addState(e);
    fsa.addState(c);

    Matcher matcher(fsa);
    int count = 0;

    if (matcher.find(av[1], count))
        std::cout << "Total : " << count << std::endl;

    return 0;
}
