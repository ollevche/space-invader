// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Boulder.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 15:43:35 by ollevche          #+#    #+#             //
//   Updated: 2018/10/06 15:43:36 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BOULDER_HPP
# define BOULDER_HPP

# include "general.hpp"

class Boulder : public AGameEntity {

	public:

		Boulder();
		Boulder(Boulder const & src);
		~Boulder();

		void	renderEntity(RetroGame & theGame);
		void	executeEntity(RetroGame & theGame);

};

#endif
