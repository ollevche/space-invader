// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Missile.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 14:57:14 by ollevche          #+#    #+#             //
//   Updated: 2018/10/07 14:57:14 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MISSILE_HPP
# define MISSILE_HPP

# include "general.hpp"

class Missile : public AGameEntity {

	public:

		Missile(int x, int y, int dir);
		Missile(Missile const & src);
		~Missile();

		void	renderEntity(RetroGame & theGame);
		void	executeEntity(RetroGame & theGame);

	private:

		Missile();
};

#endif
