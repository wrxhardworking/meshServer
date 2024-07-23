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

MyContext::MyContext() : meshManger("../../filename") {}

const char *MyContext::handleStep(const std::string &msg) {
    //fixme
    //msg是一个json
    //1、解析json
    //2、放入文件
    //3、创建。。
    return meshManger.StartMesh();
}

std::string MyContext::handleElse(const std::string &msg) {
    return {};
}

