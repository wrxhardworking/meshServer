//
// Created by 28108 on 2024/7/16.
//

#pragma once

#include <TopoDS_Shape.hxx>
#include <StlAPI_Reader.hxx>
#include <STEPControl_Reader.hxx>
#include <SMESH_Gen.hxx>
#include <SMESH_SMESH.hxx>

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class FileExplore {
public:
    explicit FileExplore(std::string_view fileName) : fileName(fileName) {}

    virtual TopoDS_Shape Input() { return {}; }

    virtual void Output(std::shared_ptr<SMESH_Gen> genPtr) {}

    virtual void Output(std::shared_ptr<SMESH_Mesh> meshPtr) {}

protected:
    std::string fileName;
};


//输入文件：stp或者step文件格式
class Step : public FileExplore {
public:
    //委托构造
    explicit Step(std::string_view fileName) : FileExplore(fileName) {}

    //fixme 考虑多个shap的情况
    //注意异常处理
    TopoDS_Shape Input() override;
};

//输出文件：unv文件格式
class Unv : public FileExplore {
public:
    explicit Unv(std::string_view fileName) : FileExplore(fileName) {}

    void Output(std::shared_ptr<SMESH_Mesh> meshPtr) override;
};

class StlAscii : public FileExplore {
public:
    explicit StlAscii(std::string_view fileName) : FileExplore(fileName) {}

    TopoDS_Shape Input() override;

    void Output(std::shared_ptr<SMESH_Mesh> meshPtr) override;
};

class StlBin : public FileExplore {
public:
    explicit StlBin(std::string_view fileName) : FileExplore(fileName) {}

    TopoDS_Shape Input() override;

    void Output(std::shared_ptr<SMESH_Mesh> meshPtr) override;
};