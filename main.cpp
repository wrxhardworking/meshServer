#include "server.h"
#include "meshlog.h"
#include "meshmanger.h"
#include "fileexplore.h"

#include <hv/json.hpp>

#include <iostream>
#include <exception>


using namespace hv;

int main(int argc, char *argv[]) {

    //端口
    int port = 10011;
    //线程数量
    int threadCount = 4;
    //映射前缀
    std::string filePrefix;

    std::vector<std::string> args(argv + 1, argv + argc);

    auto it = std::find(args.begin(), args.end(), "-p");
    if (it != args.end() && ++it != args.end()) {
        port = std::stoi(*it);
    }

    it = std::find(args.begin(), args.end(), "-f");
    if (it != args.end() && ++it != args.end()) {
        filePrefix = *it;
        MeshManger::urlPrefix = std::move(filePrefix);
    } else {
        std::cerr << "Missing required argument: -f <url_prefix>" << std::endl;
        std::cerr << "Usage: " << argv[0] << " -f <url_prefix> [-p <port>] [-t <thread_count>]" << std::endl;
        return 1;
    }

    it = std::find(args.begin(), args.end(), "-t");
    if (it != args.end() && ++it != args.end()) {
        threadCount = std::stoi(*it);
    }

    if (port <= 0 || threadCount <= 0) {
        std::cerr << "Invalid port or thread count." << std::endl;
        std::cerr << "Usage: " << argv[0] << " -f <url_prefix> [-p <port>] [-t <thread_count>]" << std::endl;
        return 1;
    }

    std::cout << port << " " << filePrefix << " " << threadCount << std::endl;;

    Server server(port, threadCount);
    server.start();
    while (getchar() != '\n');
}