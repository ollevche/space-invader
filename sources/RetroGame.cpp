// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RetroGame.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 16:06:33 by ollevche          #+#    #+#             //
//   Updated: 2018/10/06 16:06:33 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "general.hpp"

/*
**	constructors, destructor and operator=
*/

RetroGame::RetroGame() {
	AGameEntity* spaceShip = new SpaceShip(); // TODO: delete it
	pool = new EntityList(*spaceShip); // TODO: delete it
	initscr();
	gameStage = newwin(100, 500, 0, 0); // TODO: defines
	statsBar = newwin(100, 50, 0 + 100, 0 + 500); // TODO: test sizes
}

RetroGame::RetroGame(RetroGame const & src) {
	*this = src;
}

RetroGame::~RetroGame() {
	delwin(gameStage);
	delwin(statsBar);
}

RetroGame & RetroGame::operator=(RetroGame const & src) {
	EntityList *elem;

	elem = src.pool;
	pool = new EntityList(elem->getEntity()); // TODO: delete it
	elem = elem->getNext();
	while (elem && !elem->isLast()) {
		pool->add(elem->getEntity());
		pool = pool->getNext();
		elem = elem->getNext();
	}
	gameStage = src.gameStage; // TODO: check this (gameStage and statsBar will be killed with destructor)
	statsBar = src.statsBar; // it should be done by creating new windows
	return *this;
}

/*
**	methods:
*/

void RetroGame::playGame() {
	AGameEntity & spaceShip = pool->getEntity();

	while (spaceShip.isAlive()) {
		executeCycle();
		controlCycle();
		renderCycle();
	}
}

void RetroGame::executeCycle() {
	EntityList	*iterator;
	AGameEntity	*gameEntity;

	iterator = pool;
	while (iterator) {
		gameEntity = &(iterator->getEntity());
		gameEntity->executeEntity(*this);
		iterator = iterator->getNext();
	}
}

void RetroGame::controlCycle() {
	EntityList	*iterator;
	AGameEntity	*gameEntity;

	iterator = pool->getNext();
	while (iterator) {
		gameEntity = &(iterator->getEntity());
		if (gameEntity->isAlive())
			iterator = iterator->unlink();
		else
			iterator = iterator->getNext();
	}
	// TODO: get input keys
}

void RetroGame::renderCycle() {
	EntityList	*iterator;
	AGameEntity	*gameEntity;

	wclear(gameStage);
	box(gameStage, '|', '-');
	iterator = pool;
	while (iterator) {
		gameEntity = &(iterator->getEntity());
		gameEntity->renderEntity(*this);
		iterator = iterator->getNext();
	}
	wrefresh(gameStage);
	while (true);
	// TODO: statsBar update
}

WINDOW & RetroGame::getStage() const {
	return *gameStage;
}

AGameEntity *RetroGame::getCollision(AGameEntity & elem) const {
	EntityList	*iterator;
	AGameEntity	*gameEntity;

	iterator = pool;
	while (iterator) {
		gameEntity = &(iterator->getEntity());
		if (gameEntity->isCollide(elem))
			return gameEntity;
		iterator = iterator->getNext();
	}
	return NULL;
}
