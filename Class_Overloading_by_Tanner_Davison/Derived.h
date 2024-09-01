//
// Created by Tanner on 9/1/2024.
//

#pragma once
#include "Base.h"


class Derived : public Base {
public:
    Derived();
    ~Derived() override;
    void toString()const override;
    Base* basePtr = new Base;
};

