// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Missile.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 15:33:26 by ollevche          #+#    #+#             //
//   Updated: 2018/10/07 15:33:26 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "general.hpp"

# define SHAPE "'"

Missile::Missile() {
	x = 0;
	y = 0;
	shape = strdup(SHAPE);
	direction = NONEDIR;
}

Missile::Missile(int x, int y, int dir) {
	this->x = x;
	this->y = y - (dir == UPDIR ? 1 : 0) + (dir == DOWNDIR ? 1 : 0);
	direction = dir;
	shape = strdup(SHAPE);
}

Missile::~Missile() {
	delete shape;
}

void Missile::renderEntity(RetroGame & theGame) { // TODO: make it default realization
	mvwprintw(&theGame.getStage(), y, x, shape);
}

void Missile::executeEntity(RetroGame & theGame) {
	bool		isOnScreen;
	AGameEntity	*collision;

	collision = theGame.getCollision(*this);
	if (collision) {
		isDead = true;
		collision->kill();
		return;
	}
	isOnScreen = true;
	if (direction == UPDIR)
		isOnScreen = moveUp();
	else if (direction == DOWNDIR)
		isOnScreen = moveDown();
	if (!isOnScreen)
		isDead = true;
}
