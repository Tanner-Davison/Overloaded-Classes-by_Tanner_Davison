//
// Created by Tanner on 9/1/2024.
//

#pragma once
#include "Base.h"


class Derived final : public Base {
public:
	Derived();
	Derived(int xP, int yP);
	~Derived() override;
	void toString()const override;
	void specialFunc()const;
	Base* basePtr;
private:
	int y;
};

