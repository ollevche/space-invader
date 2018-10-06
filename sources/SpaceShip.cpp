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

SpaceShip::SpaceShip() {
    // TODO: x and y default values based on windows size
    // color =
    shape = "^"; // TODO: defines
}

SpaceShip::SpaceShip(SpaceShip const & src) {
    *this = src;
}

SpaceShip::~SpaceShip() {
    /* DEFAULT DESTRUCTOR */
}

void SpaceShip::renderEntity(RetroGame & theGame) {
    mvwprintw(&theGame.getStage(), y, x, "^");
}
void SpaceShip::executeEntity(RetroGame & theGame) {
    (void)theGame; // TODO: this
}
