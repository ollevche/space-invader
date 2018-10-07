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

# define NONEDIR	0
# define UPDIR		1
# define DOWNDIR	2

class AGameEntity {

	public:

		AGameEntity();
		AGameEntity(AGameEntity const & src);
		virtual ~AGameEntity();

		virtual void	renderEntity(RetroGame & theGame) = 0;
		virtual void	executeEntity(RetroGame & theGame) = 0;

		bool			kill();
		bool			isAlive() const;
		virtual bool	isCollide(AGameEntity & anotherOne) const;

		bool			moveUp();
		bool			moveDown();
		bool			moveRight();
		bool			moveLeft();

		void			shot(RetroGame & theGame);

		AGameEntity & operator=(AGameEntity const & src);

	protected:

		int		x;
		int		y;
		char	*shape;

		int		inactive;
		int		maxInactive;
		bool	isDead;
		int		direction;

};

#endif
