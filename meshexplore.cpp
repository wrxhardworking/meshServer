#include "meshexplore.h"
#include "myexception.h"

#include <SMESH_Gen.hxx>

#include <NETGENPlugin_NETGEN_2D.hxx>
#include <NETGENPlugin_NETGEN_3D.hxx>

#include <NETGENPlugin_Hypothesis_2D.hxx>
#include <NETGENPlugin_SimpleHypothesis_3D.hxx>

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
        //算法
        algoPtrs.emplace_back(new NETGENPlugin_NETGEN_2D(count++, genPtr.get()));
        algoPtrs.emplace_back(new NETGENPlugin_NETGEN_3D(count++, genPtr.get()));
        //假设
        auto h1 = new NETGENPlugin_Hypothesis_2D(count++, genPtr.get());
        auto h2 = new NETGENPlugin_SimpleHypothesis_3D(count++, genPtr.get());

        h1->SetMaxSize(1);
        h1->SetMinSize(0.01);
        h1->SetUseDelauney(true);
        h1->SetNbSurfOptSteps(3);
        h1->SetNbVolOptSteps(3);
        h1->SetElemSizeWeight(0.2);
        h1->SetFineness(NETGENPlugin_Hypothesis::Moderate);
        h1->SetGrowthRate(0.3);
        h1->SetOptimize(true);
        h1->SetCheckOverlapping(true);
        h1->SetCheckChartBoundary(true);
        h1->SetWorstElemMeasure(2);

        hypPtrs.emplace_back(h1);
        hypPtrs.emplace_back(h2);
    } else {
        //fixme 等后续
    }
}

//fixme 遇到边面加密该怎么处理
void MeshExplore::startCompute(std::string &meshFileSaveTo) {
    meshPtr->ShapeToMesh(shapeExplore.GetTopoDSShape());
    for (int i = 0; i < count; ++i) {
        meshPtr->AddHypothesis(shapeExplore.GetTopoDSShape(), i);
    }
    bool success = genPtr->Compute(*meshPtr, shapeExplore.GetTopoDSShape());
    if (success) {
        std::cout << "compute successful\n";
        size_t index = meshFileSaveTo.rfind('.');
        meshFileSaveTo.replace(index + 1, meshFileSaveTo.size(), "unv");
        meshPtr->ExportUNV(meshFileSaveTo.c_str());
    } else {
        //fixme 什么时候抛出异常
        std::cout << "compute failed\n";
        throw ComputeException("Compute error");
    }
}


