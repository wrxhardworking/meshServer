


#include "server.h"
#include <iostream>

int main() {
    int port;

    std::cin >> port;

    Server server(port);

    server.start();

}