//
// Created by Tanner on 8/31/2024.
//

#pragma once
#include "Character.h"
// #include "Base.h"
class Base;

class PlayerCharacter : public Character {
public:
    PlayerCharacter();
    ~PlayerCharacter();

private:
    Base* vec;
};




