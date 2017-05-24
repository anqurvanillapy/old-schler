#pragma once

#include "common.h"
#include "sock.h"

/**
 *  Session is a functor (callable) that handles a single request.
 */

namespace oldschler {

class session {
public:
    explicit session(int sockfd) : conn_{sockfd} { /* nop */ }
    ~session() { /* nop */ }

    // Copy.
    session(const session&) = delete;
    void operator=(const session&) = delete;

    // Move.
    session(session&& s) { *this = std::move(s); }
    session& operator=(session&& s) noexcept;

    void operator()();
private:
    oldschler::sock conn_;
};

} /* namespace oldschler */

#include "session.tcc"
