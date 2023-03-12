#ifndef CHANNEL_D
#define CHANNEL_D

#include "svdpi.h"
#include "channelBase.h"

namespace tl_interface {

    class channelD: channelBase {
        protected:
            uint8_t opcode;
            uint8_t param;
            uint8_t size;
            uint8_t source;
            uint8_t sink;
            uint8_t denied;
            uint8_t *data = new uint8_t[BEATSIZE];
            uint8_t corrupt;
            uint8_t dirty;

        public:
            void signal_update(
                uint8_t opcode,
                uint8_t param,
                uint8_t size,
                uint8_t source,
                uint8_t sink,
                uint8_t denied,
                uint8_t *data,
                uint8_t corrupt,
                uint8_t dirty
            ) {
                this->opcode = opcode;
                this->param = param;
                this->size  = size;
                this->source = source;
                this->sink = sink;
                this->denied = denied;
                //this->data = data;
                memcpy(this->data, data, BEATSIZE);

                //this->data = data;
                this->corrupt = corrupt;
                this->dirty = dirty;
            }

            void tlc_agent_eval_channelD (
                svBitVecVal     *opcode,
                svBitVecVal     *param,
                svBitVecVal     *size,
                svBitVecVal     *source,
                svBitVecVal     *sink,
                svBitVecVal     *denied,
                svBitVecVal     *data,
                svBit           *corrupt,
                svBit           *dirty
            ) {
                *opcode = this->opcode;
                *param  = this->param;
                *size   = this->size;
                *source = this->source;
                *sink = this->sink;
                memcpy(data, this->data, BEATSIZE);
                *corrupt = this->corrupt;
                *dirty = this->dirty;
            }
    };

    
}

#endif