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

    sock(const sock&) = delete;
    void operator=(const sock&) = delete;

    void sock_bind();
    void sock_connect();
    void sock_listen(int q);
    int sock_accept();
    void sock_write(const char *buf, size_t n);
    void sock_close();
private:
    struct sockaddr_in addr;
    socklen_t addrlen;
    int sockfd_;
};

} /* namespace oldshler */

#include "sock.tcc"
