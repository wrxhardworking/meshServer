#include "meshmanger.h"

MeshManger::MeshManger(std::string_view fileName) :
        step(fileName),
        shapeExplore(step.Input()),
        meshExplore(map, shapeExplore) {
    url.append(urlPrefix);
    url.append(fileName);
}

const char *MeshManger::StartMesh() {
    //fixme
    try {
        //注意这里传进去的是引用 url的后缀已经改变 "/../../shape.step -> /../../shape.unv"
        meshExplore.startCompute(url);
    }
    catch (std::exception &e) {
        return e.what();
    }
    return url.c_str();
}

std::string MeshManger::urlPrefix;