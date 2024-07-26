/**
  ******************************************************************************
  * @file           : MeshExplore.h
  * @author         : ethan
  * @brief          : use of mesh and gen
  * @attention      : region operation
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
    MeshExplore(std::unordered_map<std::string, std::string> map, ShapeExplore &shapeExplore, bool isDefault = true);

    void startCompute(std::string &meshFileSaveTo);

private:
    //todo 很多操作要进行
    void initAlgoAndHyp();

    int count;

    ShapeExplore &shapeExplore;

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
