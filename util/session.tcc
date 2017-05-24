namespace oldschler {

session&
session::operator=(session&& s) noexcept
{
    conn_ = std::move(s.conn_);
    return *this;
}

void
session::operator()()
{
    std::cout << "[request] tid=" << std::this_thread::get_id() << std::endl;
    std::string greetings = "HTTP/1.1 200 OK\r\n"
                            "Content-Type: text/html\r\n"
                            "Content-Length: 26\r\n"
                            "\r\n"
                            "<em>Hello, oldschler!</em>\r\n";
    conn_.write(greetings.c_str(), greetings.length());
    conn_.close();
}

} /* namespace oldschler */
