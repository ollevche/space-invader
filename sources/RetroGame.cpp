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
	AGameEntity* spaceShip = new SpaceShip();
	pool = new EntityList(*spaceShip);
	lastSpawn = 0;

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	gameStage = newwin(STAGEH, STAGEW, 0, 0);
	nodelay(gameStage, true);
	keypad(gameStage, true);

	std::srand(time(NULL));
}

RetroGame::RetroGame(RetroGame const & src) {
	*this = src;
}

RetroGame::~RetroGame() {
	EntityList *iterator;

	iterator = pool;
	while (iterator)
		iterator = iterator->unlink();
	delwin(gameStage);
	endwin();
}

RetroGame & RetroGame::operator=(RetroGame const & src) {
	EntityList *elem;

	elem = src.pool;
	pool = new EntityList(elem->getEntity());
	elem = elem->getNext();
	while (elem && !elem->isLast()) {
		pool->add(elem->getEntity());
		pool = pool->getNext();
		elem = elem->getNext();
	}
	gameStage = newwin(STAGEH, STAGEW, 0, 0);
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
		wrefresh(gameStage);
		refresh();
		usleep(CYCLEDELAY);
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

void RetroGame::receiveInput() {
	int				key;
	AGameEntity &	spaceShip = pool->getEntity();

	key = wgetch(gameStage);
	switch(key) {
		case KEY_UP :
			spaceShip.moveUp();
			break;
		case KEY_DOWN :
			spaceShip.moveDown();
			break;
		case KEY_RIGHT :
			spaceShip.moveRight();
			break;
		case KEY_LEFT :
			spaceShip.moveLeft();
			break;
	}
}

void RetroGame::addEnemies() {
	EntityList *list = pool;
	AGameEntity *boulder;

	if (lastSpawn < SPAWNRATE)
	{
		lastSpawn++;
		return;
	}
	lastSpawn = 0;
	while (!list->isLast())
		list = list->getNext();
	boulder = new Boulder();
	list->add(*boulder);
}

void RetroGame::controlCycle() {
	EntityList	*iterator;
	AGameEntity	*gameEntity;

	iterator = pool->getNext();
	while (iterator) {
		gameEntity = &(iterator->getEntity());
		if (!gameEntity->isAlive())
			iterator = iterator->unlink();
		else
			iterator = iterator->getNext();
	}
	receiveInput();
	addEnemies();
}

void RetroGame::renderCycle() {
	EntityList	*iterator;
	AGameEntity	*gameEntity;

	wclear(gameStage);
	box(gameStage, 0, 0);
	iterator = pool;
	while (iterator) {
		gameEntity = &(iterator->getEntity());
		gameEntity->renderEntity(*this);
		iterator = iterator->getNext();
	}
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
		if (gameEntity != &elem)
			if (gameEntity->isCollide(elem))
				return gameEntity;
		iterator = iterator->getNext();
	}
	return NULL;
}
