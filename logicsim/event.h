#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
<<<<<<< HEAD

=======
>>>>>>> 259bfe0f9516f8ad4b0c64298908a8ba0973172b
        bool operator()(const Event* a, const Event* b) const {
            return a->time > b->time;
        }
} EventLess;
	
#endif
