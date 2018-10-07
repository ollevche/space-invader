// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 14:42:03 by ollevche          #+#    #+#             //
//   Updated: 2018/10/06 14:42:04 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "general.hpp"

#include "menu.hpp"

int main()
{
 	RetroGame *game;
	menu *m;

	m = new menu();
	m->start();
	delete m;
	game = new RetroGame();
	game->playGame();
	delete game;
}
