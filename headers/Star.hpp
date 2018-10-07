// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Star.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 16:08:25 by ollevche          #+#    #+#             //
//   Updated: 2018/10/07 16:08:26 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef STAR_HPP
# define STAR_HPP

# include "general.hpp"

class Star : public AGameEntity {

	public:

		Star();
		Star(Star const & src);
		~Star();

		void	renderEntity(RetroGame & theGame);
		void	executeEntity(RetroGame & theGame);

		bool	isCollide(AGameEntity & anotherOne) const;

	private:

		void	setXY();

};

#endif
