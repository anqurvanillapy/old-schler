namespace oldschler {

response&
response::operator=(response&& r) noexcept
{
    body = std::move(r.body);
    status = r.status;
    headers = std::move(r.headers);
    completed_ = r.completed_;
    return *this;
}

}
