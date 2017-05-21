#pragma once

#include "common.h"
#include "sock.h"

/**
 *  Session is a functor (callable) that handles a single request.
 */

namespace oldschler {

class session {
public:
    session(int sockfd) : conn_(sockfd) { /* nop */ }
    ~session() { /* nop */ }

    void operator()();
private:
    oldschler::sock conn_;
};

} /* namespace oldschler */

#include "session.tcc"
