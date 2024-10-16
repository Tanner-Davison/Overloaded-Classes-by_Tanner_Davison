//
// Created by Tanner on 8/31/2024.
//

#pragma once


class Base {
public:
	Base();
	explicit Base(int xP, int xPrivate=1);
	virtual ~Base();
	virtual void toString()const;
	void printPrivateMember()const;
	string member;
protected:
	int x;
	int* privateMember;
};



