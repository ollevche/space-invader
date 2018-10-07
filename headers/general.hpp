// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   general.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 14:40:58 by ollevche          #+#    #+#             //
//   Updated: 2018/10/06 14:40:59 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GENERAL_HPP
# define GENERAL_HPP

# include <ncurses.h>
# include <string>
# include <unistd.h>
# include "RetroGame.hpp"
# include "AGameEntity.hpp"
# include "Boulder.hpp"
# include "SpaceShip.hpp"
# include "Missile.hpp"
# include "Star.hpp"

# define KEY_SPACE ' '

struct EntityList {

	public:

		EntityList(AGameEntity & elemEntity);

		void			add(AGameEntity & elemEntity);
		void			setPrev(EntityList *elem);
		void			setNext(EntityList *elem);
		bool			isFirst() const;
		bool			isLast() const;
		EntityList		*getPrev() const;
		EntityList		*getNext() const;
		AGameEntity &	getEntity() const;
		EntityList		*unlink(); // returns next elem

	private:

		EntityList		*prev;
		AGameEntity &	entity;
		EntityList		*next;
};

#endif
