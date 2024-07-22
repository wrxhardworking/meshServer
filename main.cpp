


#include "server.h"
#include <iostream>

int main() {
    int port;
    Server server(11122);
    server.start();
    while (getchar() != '\n');
}