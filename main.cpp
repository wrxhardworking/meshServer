#include "server.h"
#include <exception>
#include "meshlog.h"
#include "fileexplore.h"
#include <hv/json.hpp>
#include <iostream>

using namespace hv;

int main() {

    int port;
    Server server(11122);
    server.start();
    while (getchar() != '\n');
}