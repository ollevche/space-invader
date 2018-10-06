// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AGameEntity.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 14:45:55 by ollevche          #+#    #+#             //
//   Updated: 2018/10/06 14:45:55 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AGAMEENTITY_HPP
# define AGAMEENTITY_HPP

# include "general.hpp"

class AGameEntity {

	public:

		AGameEntity();
		AGameEntity(AGameEntity const & src);
		~AGameEntity();

		virtual void	renderEntity(RetroGame & theGame) = 0;
		virtual void	executeEntity(RetroGame & theGame) = 0;

		bool			kill();
		bool			isAlive() const;
		bool			isCollide(AGameEntity & anotherOne) const;

		AGameEntity & operator=(AGameEntity const & src);

	protected:

		int			x;
		int			y;
		int			color;
		std::string	shape;

		int		inactive;
		int		maxInactive;
		bool	isDead;

};

#endif
