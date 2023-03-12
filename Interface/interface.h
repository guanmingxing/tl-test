#ifndef INTERFACE
#define INTERFACE

//#include "channelB.h"
#include "channelD.h"

using namespace tl_interface;

class interface {
    public:
        //channelB chnb = new channelB();
        channelD *chnD = new channelD();
};

#endif