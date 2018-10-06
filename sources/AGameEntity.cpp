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
    x = 0; // TODO: default random x based on windows size
    color = 0;
    shape = "§"; // TODO: defines
    inactive = 0;
    maxInactive = -1;
    isDead = false;
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

AGameEntity & AGameEntity::operator=(AGameEntity const & src) {
    x = src.x;
    y = src.y;
    color = src.color;
    shape = src.shape;
    inactive = src.inactive;
    maxInactive = src.maxInactive;
    isDead = src.isDead;
    return *this;
}
