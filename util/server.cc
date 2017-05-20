#include <iostream>
#include "server.h"

int
main(int argc, const char *argv[])
{
    oldschler::server("127.0.0.1", 2929);
    return 0;
}
