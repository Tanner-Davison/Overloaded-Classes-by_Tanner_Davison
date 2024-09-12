//
// Created by Tanner on 9/8/2024.
//

#pragma once
#include <ostream>

class IBaseInterface
{
public:
    virtual void tostring(std::ostream & output)const=0;

    virtual ~IBaseInterface(){};


};
inline std::ostream& operator<<(std::ostream& output, const IBaseInterface& interface)
{
    interface.tostring(output);
    return output;
}