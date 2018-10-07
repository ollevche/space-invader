// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   menu.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 12:47:53 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/07 12:47:54 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define STARHEIGHT 3
#define STARWIDTH 2

#ifndef MENU_HPP
# define MENU_HPP


class menu {

	public:

		WINDOW*	win;
		menu();
		~menu();
		void	start();
		int del;
		int pos;
		int posb;
		int	heightw;
		int	widthw;
		int x;
		int y;
		int	posx;
		int posy;
		int posyb;
		void	moves();
		void	info();
		const char *point;

};

#endif
