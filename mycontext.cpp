#include "mycontext.h"
#include "meshmanger.h"

// fixme  不能这么做否则连接不上 测试版本
//异常：1、构造函数中 2、startMesh中的startCompute
const char *MyContext::handleStep(const std::string &msg) {
    MeshManger m(msg);
    meshManger = m;
    //fixme
    //msg是一个json
    //1、解析json
    json = Json::parse(msg.c_str());
    //2、放入文件
    //3、创建。。
    return meshManger.startMesh();
}

std::string MyContext::handleElse(const std::string &msg) {
    return {};
}

