#ifndef MACHINE_H_
# define MACHINE_H_

#define EDGE_MAX 128

enum eState {
    S0,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
    STATE_ERROR,
    STATE_MAX
};

enum eAction {
    MA,
    HR,
    ACTION_ERROR
};

extern eAction  gActionTable[STATE_MAX][EDGE_MAX];
extern eState  gStateTable[STATE_MAX][EDGE_MAX];

#endif
