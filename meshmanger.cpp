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
        meshExplore.startCompute();
    }
    catch (std::exception &e) {
        return e.what();
    }
    return url.c_str();
}

std::string MeshManger::urlPrefix;