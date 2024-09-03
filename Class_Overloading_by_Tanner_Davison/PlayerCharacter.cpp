//
// Created by Tanner on 8/31/2024.
//

#include "PlayerCharacter.h"

#include "Base.h"
#include "stdafx.h"

PlayerCharacter::PlayerCharacter()
{
	cout << "Player Character Constructed" << endl;
}

PlayerCharacter::~PlayerCharacter()
{
	cout << "Player Character Destroyed" << endl;
	delete  vec;

}
