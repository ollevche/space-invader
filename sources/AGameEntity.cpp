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

bool AGameEntity::isCollide(AGameEntity & anotherOne) const { // TODO: Y collisions
	if (anotherOne.x == x + 1)
		return true;
	if (anotherOne.x == x - 1)
		return true;
	return false;
}

void AGameEntity::moveUp() {
	if (y - 1 > 0)
		y--;
}

void AGameEntity::moveDown() {
	if (y + 2 < STAGEH)
		y++;
}

void AGameEntity::moveRight() {
	if (x + 2 < STAGEW)
		x++;
}

void AGameEntity::moveLeft() {
	if (x - 1 > 0)
		x--;
}

AGameEntity & AGameEntity::operator=(AGameEntity const & src) {
	x = src.x;
	y = src.y;
	shape = src.shape;
	inactive = src.inactive;
	maxInactive = src.maxInactive;
	isDead = src.isDead;
	return *this;
}
