#ifndef CHANNEL_B
#define CHANNEL_B

#include "svdpi.h"
#include "channelBase.h"

namespace tl_interface {

    class channelB: channelBase {
        protected:
            uint8_t opcode;
            uint8_t param;
            uint8_t size;
            uint8_t source;
            paddr_t address;
            uint8_t corrupt;
            uint8_t alias;
            uint8_t needdata;
            uint8_t *data;

        public:
            void signal_update(
                uint8_t opcode,
                uint8_t param,
                uint8_t size,
                uint8_t source,
                paddr_t address,
                uint8_t corrupt,
                uint8_t alias,
                uint8_t needdata,
                uint8_t *data
            ) {
                this->opcode = opcode;
                this->param = param;
                this->size  = size;
                this->source = source;
                this->address = address;
                this->corrupt = corrupt;
                this->alias = alias;
                this->needdata = needdata;
                this->data = data;
            }

            void tlc_agent_eval_channelB (
                svBitVecVal     *opcode,
                svBitVecVal     *param,
                svBitVecVal     *size,
                svBitVecVal     *source,
                svBitVecVal     *address,
                svBitVecVal     *mask,
                svBitVecVal     *data,
                svBit           *corrupt,
                svBit           *valid
            ) {
                *opcode = this->opcode;
                *param  = this->param;
                *size   = this->size;
                *source = this->source;
                *address = this->address;
                *mask   = 0xffffffff;
                memcpy(data, this->data, BEATSIZE);
                *corrupt = corrupt;
                *valid  = valid;
            }
    };

    
}

#endif