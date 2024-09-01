//
// Created by Tanner on 8/31/2024.
//

#pragma once
#include "Character.h"
// #include "Vector.h"
class Vector;

class PlayerCharacter : public Character {
public:
    PlayerCharacter();
    ~PlayerCharacter();

private:
    Vector* vec;
};




