#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include "Player.h"
#include "ResourceMarket.h"
#include "PowerPlantCard.h"
#include "CardStack.h"
#include "Map.h"
#include "Config.h"

class Game {
private:

	// General attributes
	int numTurns;  // the number of turns since the beginning
	int numPlayers;
	std::vector<std::shared_ptr<Player>> players;
	std::shared_ptr<ResourceMarket> rMarket;
	CardStack cardStack;
	std::shared_ptr<Map> map;

	std::vector<std::shared_ptr<Player>> playerOrder;  // players placed in the correct turn order
	int playStep;  // current step of the turn
	std::shared_ptr<Player> currentPlayer;  // pointer to the current player
	int phase;  // phase of the game (1, 2 or 3)
	bool gameOver = false;

	// For step 2
	int currentBid;
	std::shared_ptr<Player> highestBidder;

public:
	Game();
	~Game();

	void Setup();
	void PlayGame();

	void UpdatePlayOrder(bool); // step 1
	void AuctionPlants();  // step 2
	void BuyRawMaterials(); // step 3
	void BuyCities(); // step 4
	void Bureaucracy();  // step 5
};
