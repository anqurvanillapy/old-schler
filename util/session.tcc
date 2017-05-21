namespace oldschler {

void
session::operator()()
{
    std::cout << "[request] tid=" << std::this_thread::get_id() << std::endl;
    std::string greetings = "Hello, world!";
    conn_.write(greetings.c_str(), 14);
    conn_.close();
}

} /* oldschler */
