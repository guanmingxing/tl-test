#ifndef CHANNEL_BASE
#define CHANNEL_BASE

#include "svdpi.h"
#include "../Utils/Common.h"

namespace tl_interface {
    class channelBase {
        protected:
            uint8_t valid;
            uint8_t ready;
        
        public:
            bool fire() {
                return valid && ready;
            }

            void valid_v(uint8_t value) {
                this->valid = value;
            }

            void ready_update(const svBit ready) {
                this->ready = ready;
            }
    };
}

#endif