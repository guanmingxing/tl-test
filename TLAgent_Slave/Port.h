//
// Created by ljw on 10/21/21.
//

#ifndef TLC_TEST_PORT_H
#define TLC_TEST_PORT_H

#include "../Utils/Common.h"
#include <cstddef>
#include <cstdint>
#include <array>

namespace tl_agent {
    //channel A
    enum {
        PutFullData = 0,
        PutPartialData,
        ArithmeticData,
        LogicalData,
        Get,
        Hint,
        AcquireBlock,
        AcquirePerm
    };

    //channel B
    enum {
        Probe = 6
    };

    //channel C
    enum {
        AccessAck = 0,
        AccessAckData,
        HintAck,
        ProbeAck = 4,
        ProbeAckData,
        Release,
        ReleaseData
    };

    //channel D
    enum {
        Grant = 4,
        GrantData,
        ReleaseAck
    };

    //channel E
    enum {
        GrantAck = 0
    };

    //Cap
    enum {
        toT = 0,
        toB,
        toN
    };

    //Grow
    enum {
        NtoB = 0,
        NtoT,
        BtoT
    };

    //Shrink and Report
    enum {
        TtoB = 0,
        TtoN,
        BtoN,
        TtoT,
        BtoB,
        NtoN
    };

    //permission
    enum {
        INVALID = 0,
        BRANCH,
        TRUNK,
        TIP
    };

    class Decoupled {
        public:
            uint8_t *valid;
            uint8_t *ready;

            bool fire() const {
                return *valid && *ready;
            }
    };

    template<class Usr, class Echo, std::size_t N>
    class ChnA : public Decoupled {
        public:
            uint8_t *opcode;
            uint8_t *param;
            uint8_t *size;
            uint8_t *source;
            uint32_t *mask;
            paddr_t *address;
            uint8_t *data;
            Usr     *usr;
            Echo    *echo;
            uint8_t *corrupt;
            uint8_t *alias;
            
            // ChnA() {
            //     opcode  = new uint8_t(0);
            //     param   = new uint8_t(0);
            //     size    = new uint8_t(0);
            //     source  = new uint8_t(0);
            //     mask    = new uint32_t(0);
            //     address = new paddr_t(0);
            //     data    = new uint8_t(0);
            //     usr     = new Usr();
            //     echo    = new Echo();
            //     corrupt = new uint8_t(0);
            //     alias   = new uint8_t(0);
            // }
    };

    class ChnB : public Decoupled {
        public:
            uint8_t *opcode;
            uint8_t *param;
            uint8_t *size;
            uint8_t *source;
            paddr_t *address;
            uint8_t *corrupt;
            uint8_t *alias;
            uint8_t *needdata;

            // ChnB() {
            //     opcode  = new uint8_t(0);
            //     param   = new uint8_t(0);
            //     size    = new uint8_t(0);
            //     source  = new uint8_t(0);
            //     address = new paddr_t(0);
            //     corrupt = new uint8_t(0);
            //     alias   = new uint8_t(0);
            //     needdata= new uint8_t(0);
            // }
    };

    template<class Usr, class Echo, std::size_t N>
    class ChnC : public Decoupled {
        public:
            uint8_t *opcode;
            uint8_t *param;
            uint8_t *size;
            uint8_t *source;
            paddr_t *address;
            Usr     *usr;
            Echo    *echo;
            uint8_t *dirty;
            uint8_t *data;
            uint8_t *corrupt;
            uint8_t *alias;

            // ChnC() {
            //     opcode  = new uint8_t(0);
            //     param   = new uint8_t(0);
            //     size    = new uint8_t(0);
            //     source  = new uint8_t(0);
            //     address = new paddr_t(0);
            //     data    = new uint8_t(0);
            //     usr     = new Usr();
            //     echo    = new Echo();
            //     corrupt = new uint8_t(0);
            //     alias   = new uint8_t(0);
            //     dirty   = new uint8_t(0);
            // }
    };

    template<class Usr, class Echo, std::size_t N>
    class ChnD : public Decoupled {
        public:
            uint8_t *opcode;
            uint8_t *param;
            uint8_t *size;
            uint8_t *source;
            uint8_t *sink;
            uint8_t *denied;
            Usr     *usr;
            Echo    *echo;
            uint8_t *dirty;
            uint8_t *data;
            uint8_t *corrupt;

            // ChnD() {
            //     opcode  = new uint8_t(0);
            //     param   = new uint8_t(0);
            //     size    = new uint8_t(0);
            //     source  = new uint8_t(0);
            //     sink    = new uint8_t(0);
            //     denied  = new uint8_t(0);
            //     usr     = new Usr();
            //     echo    = new Echo();
            //     corrupt = new uint8_t(0);
            //     data    = new uint8_t(0);
            //     corrupt = new uint8_t(0);
            // }
    };

    class ChnE : public Decoupled {
    public:
        uint8_t *sink;
        paddr_t *addr;  // used for index scoreboard
        uint8_t *alias;
    };

    template<class ReqField, class RespField, class EchoField, std::size_t N>
    class Port {
        public:
            ChnA<ReqField, EchoField, N> a;
            ChnB b;
            ChnC<ReqField, EchoField, N> c;
            ChnD<RespField, EchoField, N> d;
            ChnE e;

            // Port() {
            //     this->a = new ChnA<ReqField, EchoField, N>;
            //     this->b = new ChnB;
            //     this->c = ChnC<ReqField, EchoField, N>;
            //     this->d = ChnD<RespField, EchoField, N>;
            //     this->e = ChnE;
            // }
    };

}

#endif //TLC_TEST_PORT_H
