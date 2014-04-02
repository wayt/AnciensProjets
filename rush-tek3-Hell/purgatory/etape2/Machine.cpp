#include "Machine.hpp"
#include <iostream>
#include <cstring>

eAction  gActionTable[STATE_MAX][EDGE_MAX];
eState  gStateTable[STATE_MAX][EDGE_MAX];

int main(int ac, char **av) {

    if (ac != 2) {

        std::cout << "Usage : ./test_fsa string" << std::endl;
        return 1;
    }
    for (int i = 0; i < STATE_MAX; ++i) {

        for (int j = 0; j < EDGE_MAX; ++j) {

            gActionTable[i][j] = ACTION_ERROR;
            gStateTable[i][j] = STATE_ERROR;
        }
    }
    gStateTable[S0]['m'] = S1;
    gStateTable[S1]['e'] = S2;
    gStateTable[S2]['e'] = S2;
    gStateTable[S2]['c'] = S3;
    gStateTable[S3]['h'] = S4;
    gStateTable[S4]['a'] = S5;
    gStateTable[S5]['n'] = S6;
    gStateTable[S6]['t'] = S7;

    gActionTable[S0]['m'] = MA;
    gActionTable[S1]['e'] = MA;
    gActionTable[S2]['e'] = MA;
    gActionTable[S2]['c'] = MA;
    gActionTable[S3]['h'] = MA;
    gActionTable[S4]['a'] = MA;
    gActionTable[S5]['n'] = MA;
    gActionTable[S6]['t'] = MA;

    for (int i = 0; i < EDGE_MAX; ++i) {
        gActionTable[S7][i] = HR;
    }

    eState currentState = S0;
    std::string token = "";
    int i = 0;

    do {
        char iot = av[1][i];
        eAction action = gActionTable[currentState][iot];
        eState state = gStateTable[currentState][iot];

        if (action == MA && currentState != STATE_ERROR) {

            currentState = state;
            token += iot;
        }
        else if (action == HR && currentState != STATE_ERROR) {

            std::cout << "Token : " << token << std::endl;
            currentState = S0;
            token = "";
        }
        i++;
    } while (i <= strlen(av[1]));
    return 0;
}
