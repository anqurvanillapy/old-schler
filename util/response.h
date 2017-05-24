#pragma once

#include "common.h"

namespace oldschler {

class response {
public:
    int status{200};
    std::string body;
    std::unordered_map<std::string, std::string> headers;

    response() { /* nop */ }
    explicit response(int status) : status(status) { /* nop */ }
    explicit response(std::string& body) : body(std::move(body)) { /* nop */ }
    ~response();

    // Copy.
    response(const response&) = delete;
    void operator=(const response&) = delete;

    // Move.
    response(response&& r) { *this = std::move(r); }
    response& operator=(response&& r) noexcept;
private:
    bool completed_{};
};

} /* namespace oldschler */

#include "response.tcc"
