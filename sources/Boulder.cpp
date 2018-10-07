// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Boulder.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 13:39:29 by ollevche          #+#    #+#             //
//   Updated: 2018/10/07 13:39:30 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "general.hpp"

# define SHAPE "O"

Boulder::Boulder() {
	x = std::rand() % (STAGEW - 1);
	if (x == 0)
		x++;
	y = 0;
	shape = strdup(SHAPE);
	inactive = 0;
	maxInactive = 10;
	direction = DOWNDIR;
}

Boulder::Boulder(Boulder const & src) {
	*this = src;
}

Boulder::~Boulder() {
	delete shape;
}

void Boulder::renderEntity(RetroGame & theGame) {
	mvwprintw(&theGame.getStage(), y, x, shape);
}

void Boulder::executeEntity(RetroGame & theGame) {
	(void)theGame;
	inactive++;
	if (inactive > maxInactive)
	{
		if (!moveDown())
			isDead = true;
		inactive = 0;
	}
}
