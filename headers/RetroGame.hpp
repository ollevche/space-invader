// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RetroGame.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 14:35:09 by ollevche          #+#    #+#             //
//   Updated: 2018/10/06 14:35:09 by ollevche         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RETROGAME_HPP
# define RETROGAME_HPP

# include "general.hpp"

# define STAGEW		75
# define STAGEH		45
# define CYCLEDELAY	20000
# define SPAWNRATE	20

class AGameEntity;
struct EntityList;

class RetroGame {

	public:

		RetroGame();
		RetroGame(RetroGame const & src);
		~RetroGame();

		RetroGame & operator=(RetroGame const & src);

		void			playGame();
		void			addEntity(AGameEntity & entity);
		WINDOW &		getStage() const;
		AGameEntity		*getCollision(AGameEntity & elem) const;


	private:

		EntityList	*pool;
		WINDOW		*gameStage;
		int			lastSpawn;
		// WINDOW		*statsBar;

		void	executeCycle();
		void	receiveInput();
		void	addEnemies();
		void	controlCycle();
		void	renderCycle();

};

#endif
