#pragma once
#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Ispec {
	string title;
};

class Spec1 :public Ispec {

};

class IcharacterClass {
	string title;
};

class ChararcterClass1 : public IcharacterClass {

};

class IuniqueSpec {
	string title;
};

class UniqueSpec1 : public IuniqueSpec {

};

class Irace {

};

class Race1 : public Irace {

};

class Item {
	string title;

public:
	Item(string _title) {
		title = _title;
	}
};

class Inventory {
	unsigned capacity;
	vector<Item> items;


public:
	Inventory() {
		capacity = 0;
	}

	Inventory(unsigned _capacity) {
		capacity = _capacity;
	}

	void addItem(Item item) {
		if (items.size() < capacity) {
			items.emplace_back(item);
		}
	}

	Item getItem(int position) {
		return items[position];
	}
	void removeItem(int position) {
		items.erase(items.begin() + position);
	}

};


class HpComponent {
private:
	int hp;
public:
	HpComponent() {
		hp = 0;
	}

	HpComponent(int _hp) {
		hp = _hp;
	}

	void getDamage(int damage) {
		hp -= damage;
	}
};

class HitComponent {
private:
	int attack;
public:
	HitComponent() {
		attack = 0;
	}
	HitComponent(int _attack) {
		attack = _attack;
	}

	void hit(HpComponent other) {
		other.getDamage(attack);
	}
};

