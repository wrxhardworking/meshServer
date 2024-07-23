#pragma once

#include <hv/hlog.h>

#ifdef _ENBLE_LOG4CPLUS
#include "LogUtil.h"
#endif

#ifndef _ENBLE_LOG4CPLUS

#define logger_stream_print(level, info_ostream)\
{\
    std::stringstream ss; \
    ss << info_ostream; \
    logger_print(MeshLog::Instance().GetLogger(), level, "[%s:%d:%s] " "%s" "\n", __FILENAME__, __LINE__, __FUNCTION__,ss.str().c_str());\
}

#define MLOG_LEVEL(level) MeshLog::Instance().SetLevel(level);
//格式化日志MLOGD("123%d",123);
#define MLOGD(fmt, ...) logger_print(MeshLog::Instance().GetLogger(), LOG_LEVEL_DEBUG, "[%s:%d:%s] " fmt "\n",  __FILENAME__, __LINE__, __FUNCTION__,## __VA_ARGS__)
#define MLOGI(fmt, ...) logger_print(MeshLog::Instance().GetLogger(), LOG_LEVEL_INFO,  "[%s:%d:%s] " fmt "\n",  __FILENAME__, __LINE__, __FUNCTION__,## __VA_ARGS__)
#define MLOGW(fmt, ...) logger_print(MeshLog::Instance().GetLogger(), LOG_LEVEL_WARN,  "[%s:%d:%s] " fmt "\n",  __FILENAME__, __LINE__, __FUNCTION__,## __VA_ARGS__)
#define MLOGE(fmt, ...) logger_print(MeshLog::Instance().GetLogger(), LOG_LEVEL_ERROR, "[%s:%d:%s] " fmt "\n",  __FILENAME__, __LINE__, __FUNCTION__,## __VA_ARGS__)
#define MLOGF(fmt, ...) logger_print(MeshLog::Instance().GetLogger(), LOG_LEVEL_FATAL, "[%s:%d:%s] " fmt "\n",  __FILENAME__, __LINE__, __FUNCTION__,## __VA_ARGS__)
//流式日志 MLOGD_O("123"<<123);
#define MLOGD_O(info_ostream) logger_stream_print(LOG_LEVEL_DEBUG,info_ostream);
#define MLOGI_O(info_ostream) logger_stream_print(LOG_LEVEL_INFO,info_ostream);
#define MLOGW_O(info_ostream) logger_stream_print(LOG_LEVEL_WARN,info_ostream);
#define MLOGE_O(info_ostream) logger_stream_print(LOG_LEVEL_ERROR,info_ostream);
#define MLOGF_O(info_ostream) logger_stream_print(LOG_LEVEL_FATAL,info_ostream);
#else
#define MLOGD(...) LOG_DEBUG_F(__VA_ARGS__)
#define MLOGI(...) LOG_INFO_F(__VA_ARGS__)
#define MLOGW(...) LOG_WARN_F(__VA_ARGS__)
#define MLOGE(...) LOG_ERROR_F(__VA_ARGS__)
#define MLOGF(...) LOG_FATAL_F(__VA_ARGS__)

#define MLOGD_O(info_ostream) LOG_DEBUG(__VA_ARGS__);
#define MLOGI_O(info_ostream) LOG_INFO(__VA_ARGS__);
#define MLOGW_O(info_ostream) LOG_WARN(__VA_ARGS__);
#define MLOGE_O(info_ostream) LOG_ERROR(__VA_ARGS__);
#define MLOGF_O(info_ostream) LOG_FATAL(__VA_ARGS__);
#endif


class MeshLog {
public:
    static MeshLog &Instance() {
        static MeshLog instance;
        return instance;
    }

    logger_t *GetLogger() {
        return m_log;
    }

    void SetLevel(int log_level = LOG_LEVEL_DEBUG) {
        logger_set_level(m_log, log_level);
    }

protected:
    MeshLog();

private:
    logger_t *m_log = nullptr;
};

