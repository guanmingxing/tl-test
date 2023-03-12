//
// Created by wkf on 2021/11/2.
//

#include "CAgent.h"



namespace tl_agent {

    int capGenPriv(int param) {
        switch (param) {
            case toT: return TIP;
            case toB: return BRANCH;
            case toN: return INVALID;
            default:
                tlc_assert(false, "Invalid param!");
        }
    }

    int shrinkGenPriv(int param) {
        switch (param) {
            case TtoT: return TIP;
            case BtoB:
            case TtoB: return BRANCH;
            case TtoN:
            case BtoN:
            case NtoN: return INVALID;
            default:
                tlc_assert(false, "Invalid param!");
        }
    }

    CAgent::CAgent(int id, interface *intf): BaseAgent(), pendingA(), pendingB(), pendingC(), pendingD(), pendingE()
    {
        //this->globalBoard = gb;
        this->id = id;
        //this->localBoard = new ScoreBoard<paddr_t , C_SBEntry>();
        //this->idMap = new ScoreBoard<int, C_IDEntry>();

        this->intf = intf;
    }

    Resp CAgent::send_b(std::shared_ptr<ChnB> &b) {
        // *this->port->b.opcode   = *b->opcode;
        // *this->port->b.param    = *b->param;
        // *this->port->b.size     = *b->size;
        // *this->port->b.source   = *b->source;
        // *this->port->b.address  = *b->address;
        // *this->port->b.corrupt  = *b->corrupt;
        // *this->port->b.alias    = *b->alias;
        // *this->port->b.needdata = *b->needdata;
        //channelb.signal_update()
        
    }

    Resp CAgent::send_d(std::shared_ptr<ChnD<RespField, EchoField, DATASIZE>> &d) {
        // *this->port->d.opcode   = *d->opcode;
        // *this->port->d.param    = *d->param;
        // *this->port->d.size     = *d->size;
        // *this->port->d.source   = *d->source;
        // *this->port->d.sink     = *d->sink;
        // *this->port->d.denied   = *d->denied;
        // *this->port->d.data     = *d->data;
        // *this->port->d.corrupt  = *d->corrupt;
        // *this->port->d.echo     = *d->echo;
        intf->chnD->signal_update(
            *d->opcode,
            *d->param,
            *d->size,
            *d->source,
            *d->sink,
            *d->denied,
            d->data,
            *d->corrupt,
            *d->dirty
        );

    }

    void CAgent::fire_a() {

    }

    void CAgent::fire_b() {
        
    }

    void CAgent::fire_c() {
        
    }

    void CAgent::fire_d() {
        // if(this->port->d.fire()) {
        //     auto chnD = this->port->d;
        //     *chnD.valid = false;
        //     //tlc_assert(pendingD.is_pending(), "No pending D but D fired!");
        // }
        if()
    }

    void CAgent::fire_e() {
        
    }

    //TODO
    bool CAgent::do_probe() {
        std::shared_ptr<ChnB> msg_b(new ChnB());
        msg_b->address = new paddr_t(0xabcd);
        pendingB.init(msg_b, 1);
    }

    bool CAgent::do_grantData(int address, int param, int size, int source, uint8_t *data, int dirty) {
        std::shared_ptr<ChnD<RespField, EchoField, DATASIZE>> msg_d(new ChnD<RespField, EchoField, DATASIZE>());
        msg_d->opcode   = new uint8_t(GrantData);
        msg_d->param    = new uint8_t(param);
        msg_d->size     = new uint8_t(size);
        msg_d->source   = new uint8_t(source);
        msg_d->sink     = new uint8_t(this->id);
        msg_d->dirty    = new uint8_t(dirty);
        msg_d->denied   = new uint8_t(0);
        msg_d->corrupt  = new uint8_t(0);
        msg_d->data     = new uint8_t[DATASIZE];
        memcpy(msg_d->data, data, DATASIZE);
        pendingD.init(msg_d, DATASIZE/BEATSIZE);

        return OK;
    }

    void CAgent::handle_channel() {
        // Constraint: fire_e > fire_d, otherwise concurrent D/E requests will disturb the pendingE
        fire_a();
        fire_b();
        fire_c();
        fire_e();
        fire_d();
    }

    void CAgent::update_signal() {
        //*this->port->d.ready = true; // TODO: do random here
        //*this->port->b.ready = !(pendingB.is_pending());
        //this->intf->chnD->valid_v(1);
        if (pendingA.is_pending()) {
            // TODO: do delay here
            //send_a(pendingA.info);
        }
        if (pendingB.is_pending()) {
            send_b(pendingB.info);
        }
        if (pendingC.is_pending()) {
            //send_c(pendingC.info);
        }
        if (pendingD.is_pending()) {
            send_d(pendingD.info);
        }
        if (pendingE.is_pending()) {
            //send_e(pendingE.info);
        }
        // do timeout check lazily
        // if (*this->cycles % TIMEOUT_INTERVAL == 0) {
        //     this->timeout_check();
        // }
        //idpool.update();
        //probeIDpool.update();
    }


}
