/**
  ******************************************************************************
  * @file           : MeshExplore.h
  * @author         : 28108
  * @brief          : 完成mesh和gen的各种工作
  * @attention      : None
  * @date           : 2024/7/17
  ******************************************************************************
  */

#pragma once

#include "shapeexplore.h"
#include <SMESH_Mesh.hxx>
#include <SMESH_Hypothesis.hxx>
#include <SMESH_Algo.hxx>

#include <unordered_map>
#include <memory>
#include <vector>
#include <string>


class MeshExplore {
public:
    MeshExplore(std::unordered_map<std::string, std::string> map, TopoDS_Shape &shape, bool isDefault);

private:
    int count;

    void initAlgoAndHyp();

    void startCompute();

    TopoDS_Shape &shape;

    std::shared_ptr<SMESH_Gen> genPtr;

    std::shared_ptr<SMESH_Mesh> meshPtr;

    //假设集合
    std::vector<std::shared_ptr<SMESH_Hypothesis>> hypPtrs;
    //算法集合
    std::vector<std::shared_ptr<SMESH_Algo>> algoPtrs;

    //假设和算法的映射 fixme
    std::unordered_map<std::string, std::string> map;

    //判断是否为默认选择
    bool isDefault;

};
