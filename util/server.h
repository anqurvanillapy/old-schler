#pragma once

#include "common.h"
#include "sock.h"
#include "session.h"

namespace oldschler {

class server {
public:
    server(const std::string& host, short port);
    ~server() { /* nop */ };
private:
    void do_accept();
    oldschler::sock listen_;
};

} /* namespace oldschler */

#include "server.tcc"
