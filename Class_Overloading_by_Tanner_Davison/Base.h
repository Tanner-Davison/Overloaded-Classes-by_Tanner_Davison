//
// Created by Tanner on 8/31/2024.
//

#pragma once


class Base {
public:
	Base();
	explicit Base(int xP);
	virtual ~Base();
	virtual void toString()const;

	string member;
protected:
	int x;
};



