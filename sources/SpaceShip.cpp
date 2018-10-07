// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpaceShip.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 21:44:12 by ollevche          #+#    #+#             //
//   Updated: 2018/10/06 21:44:12 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "general.hpp"

# define SHAPE "^"

SpaceShip::SpaceShip() {
	x = STAGEW / 2;
	y = STAGEH - STAGEH / 10;
	shape = strdup(SHAPE);
}

SpaceShip::SpaceShip(SpaceShip const & src) {
	*this = src;
}

SpaceShip::~SpaceShip() {
	delete shape;
}

void SpaceShip::renderEntity(RetroGame & theGame) {
	mvwprintw(&theGame.getStage(), y, x, shape);
}

void SpaceShip::executeEntity(RetroGame & theGame) {
	AGameEntity *entity;

	// do {
		entity = theGame.getCollision(*this); // TODO: test it
		if (entity)
			isDead = true;
	// } while (entity);
}
