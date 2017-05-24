#pragma once

#include "common.h"
#include "sock.h"
#include "session.h"

namespace oldschler {

class server {
public:
    server(const std::string& host, short port);
    ~server() { /* nop */ };

    // Copy.
    server(const server&) = delete;
    void operator=(const server&) = delete;

    // Move.
    server(server& s) { *this = std::move(s); }
    server& operator=(server&& s) noexcept;
private:
    void do_accept();
    oldschler::sock listen_;
};

} /* namespace oldschler */

#include "server.tcc"
