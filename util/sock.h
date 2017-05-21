#pragma once

#include "common.h"

/**
 *  Socket class wrapping BSD APIs.
 */

namespace oldschler {

class sock {
public:
    sock(int fd) : sockfd_(fd) { /* nop */ }
    sock(const std::string& host, short port);
    ~sock() { /* nop */ }

    void bind();
    void connect();
    void listen(int q);
    int accept();
    void write(const char *buf, size_t n);
    void close();
private:
    struct sockaddr_in addr;
    socklen_t addrlen;
    int sockfd_;
};

} /* namespace oldshler */

#include "sock.tcc"
