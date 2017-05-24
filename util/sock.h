#pragma once

#include "common.h"

/**
 *  Socket class wrapping BSD APIs.
 */

namespace oldschler {

class sock {
public:
    sock() { /* nop */ }
    explicit sock(int fd) : sockfd_(fd) { /* nop */ }
    sock(const std::string& host, short port);
    ~sock() { /* nop */ }

    // Copy.
    sock(const sock&) = delete;
    void operator=(const sock&) = delete;

    // Move.
    sock(sock&& s) { *this = std::move(s); }
    sock& operator=(sock&& s) noexcept;

    void bind();
    void connect();
    void listen(int q);
    int accept();
    void write(const char *buf, size_t n);
    void close();
private:
    struct sockaddr_in addr_;
    socklen_t addrlen_;
    int sockfd_{-1};
};

} /* namespace oldshler */

#include "sock.tcc"
