namespace oldschler {

server::server(const std::string& host, short port)
    : listen_(host, port)
{
    listen_.sock_bind();
    listen_.sock_listen(1024);
    do_accept();
}

void
server::do_accept()
{
    std::string greetings = "Hello, world!";
    oldschler::sock conn{listen_.sock_accept()};

    conn.sock_write(greetings.c_str(), 14);
    conn.sock_close();
    listen_.sock_close();
}

} /* namespace oldschler */
