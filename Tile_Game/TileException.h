#ifndef TILEEXCEPTION_H
#define TILEEXCEPTION_H
#include <string>
class TileException{
    private:
        std::string message;
    public:
        TileException(const std::string& message);
        std::string getMessage() const;
};

#endif