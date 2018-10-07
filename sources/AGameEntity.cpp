// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AGameEntity.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 21:44:03 by ollevche          #+#    #+#             //
//   Updated: 2018/10/06 21:44:04 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "general.hpp"

AGameEntity::AGameEntity() {
	y = 0;
	x = 0;
	shape = NULL;
	inactive = 0;
	maxInactive = -1;
	isDead = false;
	direction = NONEDIR;
}

AGameEntity::AGameEntity(AGameEntity const & src) {
	*this = src;
}

AGameEntity::~AGameEntity() {
	/* DEFAULT DESTRUCTOR */
}

bool AGameEntity::kill() {
	if (isDead)
		return false;
	isDead = true;
	return true;
}

bool AGameEntity::isAlive() const {
	return !isDead;
}

bool AGameEntity::isCollide(AGameEntity & anotherOne) const {
	if (anotherOne.direction == NONEDIR || direction == anotherOne.direction)
		return false;
	if (anotherOne.x != x)
		return false;
	if (anotherOne.y == y + 1)
		return true;
	if (anotherOne.y == y - 1)
		return true;
	return false;
}

bool AGameEntity::moveUp() {
	if (y - 1 > 0) {
		y--;
		return true;
	}
	return false;
}

bool AGameEntity::moveDown() {
	if (y + 2 < STAGEH) {
		y++;
		return true;
	}
	return false;
}

bool AGameEntity::moveRight() {
	if (x + 2 < STAGEW) {
		x++;
		return true;
	}
	return false;
}

bool AGameEntity::moveLeft() {
	if (x - 1 > 0) {
		x--;
		return true;
	}
	return false;
}

AGameEntity & AGameEntity::operator=(AGameEntity const & src) {
	x = src.x;
	y = src.y;
	shape = strdup(src.shape);
	inactive = src.inactive;
	maxInactive = src.maxInactive;
	isDead = src.isDead;
	return *this;
}

void AGameEntity::shot(RetroGame & theGame) {
	AGameEntity *missile;

	missile = new Missile(x, y, direction);
	theGame.addEntity(*missile);
}
