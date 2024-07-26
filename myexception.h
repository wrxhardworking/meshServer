/**
  ******************************************************************************
  * @file           : MyException.h
  * @author         : ethan
  * @brief          : custom exception
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

class ComputeException : public std::exception {
public:
    explicit ComputeException(const char *errorMessage) : errorMessage(errorMessage) {
    }

    virtual const char *what() const noexcept override {
        return errorMessage;
    }

private:
    const char *errorMessage;
};
