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
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	gameStage = newwin(STAGEH, STAGEW, 0, 0);
	nodelay(gameStage, true);
	keypad(gameStage, true);
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
		renderCycle();
		controlCycle();
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
			mvwprintw(gameStage, 1, 1, "KEY PRESSED!!!");
			break;
		case KEY_DOWN :
			spaceShip.moveDown();
			mvwprintw(gameStage, 1, 1, "KEY PRESSED!!!");
			break;
		case KEY_RIGHT :
			spaceShip.moveRight();
			mvwprintw(gameStage, 1, 1, "KEY PRESSED!!!");
			break;
		case KEY_LEFT :
			spaceShip.moveLeft();
			mvwprintw(gameStage, 1, 1, "KEY PRESSED!!!");
			break;
	}
	flushinp();
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
	receiveInput(); // TODO: get input keys
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
		if (gameEntity->isCollide(elem))
			return gameEntity;
		iterator = iterator->getNext();
	}
	return NULL;
}