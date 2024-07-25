/**
  ******************************************************************************
  * @file           : mycontext.cpp
  * @author         : 28108
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/18
  ******************************************************************************
  */

#include "mycontext.h"

// fixme  不能这么做否则连接不上
MyContext::MyContext() : meshManger("../../filename") { std::cout << "Mycontext 已经构造\n"; }

const char *MyContext::handleStep(const std::string &msg) {
    //fixme
    //msg是一个json
    //1、解析json
    json = Json::parse(msg.c_str());
    //2、放入文件
    //3、创建。。
    return meshManger.StartMesh();
}

std::string MyContext::handleElse(const std::string &msg) {
    return {};
}

