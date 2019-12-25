
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Components.cpp"

using namespace std;

class Entity {

public:
	string title;
	HpComponent hpComponent;
	HitComponent hitComponent;

	void hit(Entity other) {
		hitComponent.hit(other.hpComponent);
	}
	void getDamage(int damage) {
		hpComponent.getDamage(damage);
	}


};


class Character : public Entity {

	vector<Ispec> specs;
	IcharacterClass characterClass;
	IuniqueSpec uniqueSpec;
	Irace race;
	Inventory inventory;

public:
	Character(string _name) {
		title = _name;
		specs.emplace_back(Spec1());
		race = Race1();
		inventory = Inventory(10);
		uniqueSpec = UniqueSpec1();

		hpComponent = HpComponent(100);
		hitComponent = HitComponent(20);
	}

};

class Enemy : public Entity {

public:
	Enemy(string _name) {
		title = _name;

		hpComponent = HpComponent(100);
		hitComponent = HitComponent(10);
	}
};