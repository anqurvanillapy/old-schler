namespace oldschler {

sock::sock(const std::string& host, short port)
{
    const char *c_host = host.c_str();
    addr_ = {};

    sockfd_ = ::socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_ < 0) throw std::runtime_error("socket error");

    addr_.sin_family         = AF_INET;
    addr_.sin_addr.s_addr    = inet_addr(c_host);
    addr_.sin_port           = htons(port);

    addrlen_ = (socklen_t) sizeof(addr_);
}

sock&
sock::operator=(sock&& s) noexcept
{
    addr_ = std::move(s.addr_);
    addrlen_ = s.addrlen_;
    sockfd_ = s.sockfd_;
    return *this;
}

void
sock::bind()
{
    if (::bind(sockfd_, (struct sockaddr *) &addr_, addrlen_) < 0) {
        throw std::runtime_error("bind error");
    }
}

void
sock::connect()
{
    if (::connect(sockfd_, (struct sockaddr *) &addr_, addrlen_) < 0) {
        throw std::runtime_error("connect error");
    }
}

void
sock::listen(int q)
{
    if (::listen(sockfd_, q) < 0) {
        throw std::runtime_error("listen error");
    }
}

int
sock::accept()
{
    int ret;
    if ( (ret = ::accept(sockfd_, (struct sockaddr *) &addr_, &addrlen_)) < 0) {
        throw std::runtime_error("accept error");
    }
    return ret;
}

void
sock::write(const char *buf, size_t n)
{
    if (::write(sockfd_, buf, n) < 0) throw std::runtime_error("write error");
}

void
sock::close()
{
    if (::close(sockfd_) < 0) throw std::runtime_error("close error");
}

} /* namespace oldschler */
