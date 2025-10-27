#include "TileException.h"



TileException::TileException(const std::string& message){
this->message=message;

}
std::string TileException::getMessage() const{
    return message;
}