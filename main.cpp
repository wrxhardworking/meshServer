//
//#include "SMESH_SMESH.hxx"
//#include "SMESH_Gen.hxx"

#include <iostream>
#include "hv/TcpServer.h"
#include "hv/hfile.h"

using namespace hv;

int main() {
//    HFile hFile;
//
//    int port = atoi("10012");
//
//    hlog_set_level(LOG_LEVEL_DEBUG);
//
//    TcpServer srv;
//    int listenfd = srv.createsocket(port);
//    if (listenfd < 0) {
//        return -20;
//    }
//    printf("server listen on port %d, listenfd=%d ...\n", port, listenfd);
//    //进行连接的时候会进入到这个事件循环
//    srv.onConnection = [](const SocketChannelPtr &channel) {
//        std::string peeraddr = channel->peeraddr();
//
//        if (channel->isConnected()) {
//            printf("%s connected! connfd=%d id=%d tid=%ld\n", peeraddr.c_str(), channel->fd(), channel->id(),
//                   currentThreadEventLoop->tid());
//        } else {
//            printf("%s disconnected! connfd=%d id=%d tid=%ld\n", peeraddr.c_str(), channel->fd(), channel->id(),
//                   currentThreadEventLoop->tid());
//        }
//    };
//    srv.onMessage = [](const SocketChannelPtr &channel, Buffer *buf) {
//        // echo
//        printf("< %.*s\n", (int) buf->size(), (char *) buf->data());
//        channel->write(buf);
//    };
//    srv.setThreadNum(4);
//    srv.setLoadBalance(LB_LeastConnections);
//
//#if TEST_TLS
//    hssl_ctx_opt_t ssl_opt;
//    memset(&ssl_opt, 0, sizeof(hssl_ctx_opt_t));
//    ssl_opt.crt_file = "cert/server.crt";
//    ssl_opt.key_file = "cert/server.key";
//    ssl_opt.verify_peer = 0;
//    srv.withTLS(&ssl_opt);
//#endif
//
//    srv.start();
//
//    std::string str;
//    while (std::getline(std::cin, str)) {
//        if (str == "close") {
//            srv.closesocket();
//        } else if (str == "start") {
//            srv.start();
//        } else if (str == "stop") {
//            srv.stop();
//            break;
//        } else {
//            srv.broadcast(str.data(), str.size());
//        }
//    }
//
//    return 0;
}