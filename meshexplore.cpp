/**
  ******************************************************************************
  * @file           : MeshExplore.cpp
  * @author         : 28108
  * @brief          : 关于网格的操作
  * @attention      : None
  * @date           : 2024/7/17
  ******************************************************************************
  */

#include "meshexplore.h"
#include <SMESH_Gen.hxx>
#include <NETGENPlugin_NETGEN_2D3D.hxx>

MeshExplore::MeshExplore(std::unordered_map<std::string, std::string> map, ShapeExplore &shapeExplore, bool isDefault) :
        genPtr(new SMESH_Gen()),
        meshPtr(genPtr->CreateMesh(true)),
        map(std::move(map)),
        isDefault(isDefault),
        shapeExplore(shapeExplore),
        count(0) {
    initAlgoAndHyp();
}

void MeshExplore::initAlgoAndHyp() {
    if (isDefault) {
        this->algoPtrs.emplace_back(new NETGENPlugin_NETGEN_2D3D(count++, genPtr.get()));
    } else {
        //fixme 等后续
    }
}

//fixme 遇到边面加密该怎么处理
void MeshExplore::startCompute() {
    meshPtr->ShapeToMesh(shapeExplore.GetTopoDSShape());
    for (int i = 0; i < count; ++i) {
        meshPtr->AddHypothesis(shapeExplore.GetTopoDSShape(), i);
    }
    bool success = genPtr->Compute(*meshPtr, shapeExplore.GetTopoDSShape());
    if (success) {
        std::cout << "compute successful\n";
    } else {
        //fixme 什么时候抛出异常
        //这个并不是程序出现的错误
        std::cout << "compute failed\n";
    }
}


