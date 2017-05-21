namespace oldschler {

server::server(const std::string& host, short port)
    : listen_(host, port)
{
    listen_.bind();
    listen_.listen(1024);
    do_accept();
}

void
server::do_accept()
{
    for (;;) {
        session sesh{listen_.accept()};
        std::thread t{sesh};
        t.detach();
    }

    listen_.close();
}

} /* namespace oldschler */
