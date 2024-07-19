/**
  ******************************************************************************
  * @file           : MyException.h
  * @author         : 28108
  * @brief          : 异常处理
  * @attention      : None
  * @date           : 2024/7/16
  ******************************************************************************
  */

#pragma once

#include <exception>

class FileException : public std::exception {
public:
    explicit FileException(const char *errorMessage) : errorMessage(errorMessage) {
    }
    virtual const char *what() const noexcept override {
        return errorMessage;
    }
private:
    const char *errorMessage;
};
