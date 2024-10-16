//
// Created by Tanner on 9/8/2024.
//

#pragma once
#include "IBaseInterface.h"


class InterfaceDerived :public IBaseInterface {
public:
    InterfaceDerived()=default;
    virtual~InterfaceDerived();
    void tostring(std::ostream& output) const override;

};



