#ifndef ALGORITHMS_EXCEPTIONS_H
#define ALGORITHMS_EXCEPTIONS_H

#include <exception>

using std::exception;

class NullPointerException : public exception {
    virtual const char* what() const throw() {
        return "NullPointerException";
    }
};

class EmptyException: public exception {
    virtual const char* what() const throw() {
        return "EmptyListException";
    }
};

class NotFoundException: public exception {
    virtual const char* what() const throw() {
        return "NotFoundException";
    }
};

class DoesNotExistException: public exception {
    virtual const char* what() const throw() {
        return "DoesNotExistException";
    }
};

class InvalidInputException: public exception {
    virtual const char* what() const throw() {
        return "InvalidInputException";
    }
};

class AlreadyExistException: public exception {
    virtual const char* what() const throw() {
        return "AlreadyExistException";
    }
};

#endif //ALGORITHMS_EXCEPTIONS_H
