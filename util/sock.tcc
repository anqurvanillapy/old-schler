namespace oldschler {

sock::sock(const std::string& host, short port)
{
    const char *c_host = host.c_str();
    addr = {};

    sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_ < 0) throw std::runtime_error("socket error");

    addr.sin_family         = AF_INET;
    addr.sin_addr.s_addr    = inet_addr(c_host);
    addr.sin_port           = htons(port);

    addrlen = (socklen_t) sizeof(addr);
}

void
sock::sock_bind()
{
    if (bind(sockfd_, (struct sockaddr *) &addr, addrlen) < 0) {
        throw std::runtime_error("bind error");
    }
}

void
sock::sock_connect()
{
    if (connect(sockfd_, (struct sockaddr *) &addr, addrlen) < 0) {
        throw std::runtime_error("connect error");
    }
}

void
sock::sock_listen(int q)
{
    if (listen(sockfd_, q) < 0) {
        throw std::runtime_error("listen error");
    }
}

int
sock::sock_accept()
{
    int ret;
    if ( (ret = accept(sockfd_, (struct sockaddr *) &addr, &addrlen)) < 0) {
        throw std::runtime_error("accept error");
    }
    return ret;
}

void
sock::sock_write(const char *buf, size_t n)
{
    if (write(sockfd_, buf, n) < 0) throw std::runtime_error("write error");
}

void
sock::sock_close()
{
    if (close(sockfd_) < 0) throw std::runtime_error("close error");
}

} /* namespace oldschler */
