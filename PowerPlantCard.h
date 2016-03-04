#pragma once

#include "Resource.h"
#include "Card.h"
#include <set>
#include <map>

class PowerPlantCard : public Card {
private:
	int price = 0;
	int power = 0;
	int capacity = 0;
	std::set<Resource> activeResources;
	std::map<Resource, int> placedResources;

public:
	PowerPlantCard() {}
	PowerPlantCard(int price, int power, int capacity) : price(price), power(power), capacity(capacity) {}
	~PowerPlantCard();
	
	void AddActiveResource(Resource resource) { activeResources.insert(resource); }
	void AddActiveResource(string resourceName) { AddActiveResource(GetResourceByName(resourceName)); }
	void PlaceResource(Resource resource, int amount) { placedResources[resource] += amount; }
	void PlaceResource(string resourceName, int amount) { PlaceResource(GetResourceByName(resourceName), amount); }

	std::set<Resource> const& GetResources() const { return activeResources; }
	std::map<Resource, int> const& GetPlacedResources() const { return placedResources; }
	int GetPrice() const { return price; }
	int GetPower() const { return power; }
	int GetCapcity() const { return capacity; }
};

