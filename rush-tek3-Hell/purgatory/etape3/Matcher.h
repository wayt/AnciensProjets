#ifndef MATCHER_H_
# define MATCHER_H_

#include "FSA.h"

class Matcher {

    public:
        Matcher(FSA &fsa);
        bool find(std::string const &str, int &nb) const;
        bool find(std::string const &str) const;
    private:
        FSA &_fsa;
};

#endif

