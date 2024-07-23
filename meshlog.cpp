/**
  ******************************************************************************
  * @file           : meshlog.cpp
  * @author         : 28108
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/23
  ******************************************************************************
  */

#include "meshlog.h"

MeshLog::MeshLog() {
    m_log = logger_create();
    logger_set_file(m_log, "mesh.log");
}
