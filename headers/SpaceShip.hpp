// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpaceShip.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 15:49:04 by ollevche          #+#    #+#             //
//   Updated: 2018/10/06 15:49:04 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPACESHIP_HPP
# define SPACESHIP_HPP

# include "general.hpp"

class SpaceShip : public AGameEntity {

	public:

		SpaceShip();
		SpaceShip(SpaceShip const & src);
		~SpaceShip();

		void	renderEntity(RetroGame & theGame);
		void	executeEntity(RetroGame & theGame);

};

#endif
