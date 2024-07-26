#include "meshlog.h"

MeshLog::MeshLog() {
    m_log = logger_create();
    logger_set_file(m_log, "mesh.log");
}
