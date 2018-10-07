// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Star.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 16:11:05 by ollevche          #+#    #+#             //
//   Updated: 2018/10/07 16:11:06 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "general.hpp"

# define SHAPE "#"

void Star::setXY() { // TODO: refactor
	if (rand() % 2)
	{
		x = std::rand() % (STAGEW - 1);
		if (x == 0)
			x++;
		y = 1;
	} else {
		y = std::rand() % (STAGEW - 1);
		if (y == 0)
			y++;
		x = 1;
	}
}

Star::Star() {
	setXY();
	shape = strdup(SHAPE);
	direction = NONEDIR;
	inactive = 0;
	maxInactive = 0;
}

Star::Star(Star const & src) {
	*this = src;
}

Star::~Star() {
	delete shape;
}

void Star::renderEntity(RetroGame & theGame) {
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	wattron(&theGame.getStage(), COLOR_PAIR(1));
	mvwprintw(&theGame.getStage(), y, x, shape);
	wattroff(&theGame.getStage(), COLOR_PAIR(1));
}

void Star::executeEntity(RetroGame & theGame) {
	(void)theGame;
	if (inactive < maxInactive)
	{
		inactive++;
		return;
	}
	inactive = 0;
	if (!moveRight())
		setXY();
	if (x % 2 == 0)
		if (!moveDown())
			setXY();
}

bool Star::isCollide(AGameEntity & anotherOne) const {
	(void)anotherOne;
	return false;
}
