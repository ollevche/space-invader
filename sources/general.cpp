// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   general.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:30:10 by ollevche          #+#    #+#             //
//   Updated: 2018/10/06 17:30:10 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "general.hpp"

/*
**	EntityList:
*/

EntityList::EntityList(AGameEntity & elemEntity) : entity(elemEntity) {
	prev = NULL;
	next = NULL;
}

void EntityList::add(AGameEntity & elem) {
	EntityList *newElem;

	newElem = new EntityList(elem);
	newElem->setPrev(this);
	next = newElem;
}

void EntityList::setPrev(EntityList *elem) {
	prev = elem;
}

void EntityList::setNext(EntityList *elem) {
	next = elem;
}

bool EntityList::isFirst() const {
	return (prev == NULL);
}

bool EntityList::isLast() const {
	return (next == NULL);
}

EntityList *EntityList::getPrev() const {
	return prev;
}

EntityList *EntityList::getNext() const {
	return next;
}

AGameEntity & EntityList::getEntity() const {
	return entity;
}

EntityList *EntityList::unlink() {
	EntityList *retNextElem;

	retNextElem = next;
	if (prev != NULL)
		prev->setNext(next);
	if (next != NULL)
		next->setPrev(prev);
	prev = NULL;
	next = NULL;
	delete &entity;
	delete this;
	return retNextElem;
}
