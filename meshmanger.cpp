/**
  ******************************************************************************
  * @file           : meshmanger.cpp
  * @author         : 28108
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/22
  ******************************************************************************
  */

#include "meshmanger.h"

MeshManger::MeshManger(std::string_view fileName) :
        step(fileName),
        shapeExplore(step.Input()),
        //prifix 也能设置一个宏定义
        meshExplore(map, shapeExplore),
        url("/prefix") {
    url += fileName;
}

const char *MeshManger::StartMesh() {
    //fixme
    try {
        meshExplore.startCompute();
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    return url.c_str();
}
