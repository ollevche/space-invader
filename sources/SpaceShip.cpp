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

# define SHAPE "/^\\"

SpaceShip::SpaceShip() {
    // TODO: x and y default values based on windows size
    // color =
    shape = strdup(SHAPE); // TODO: defines
}

SpaceShip::SpaceShip(SpaceShip const & src) {
    *this = src;
}

SpaceShip::~SpaceShip() {
    /* DEFAULT DESTRUCTOR */
    delete shape;
}

void SpaceShip::renderEntity(RetroGame & theGame) {
    mvwprintw(&theGame.getStage(), y, x, shape); // DEL
    mvwprintw(&theGame.getStage(), STAGEH / 2, STAGEW / 2, "%d", x); // DEL
}
void SpaceShip::executeEntity(RetroGame & theGame) {
    (void)theGame; // TODO: this
    x++; // DEL
    if (x > STAGEW)
        isDead = true;
}
