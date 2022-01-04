#pragma once
//#include "Monster.h"
//class Item {
//protected:
//	vector<Monster*> monsters;
//public:
//	void AddMonsterList(vector<Monster*> &monsters){
//		this->monsters = monsters;
//	}
//	virtual int getPrice() = 0;
//	virtual void active() = 0;
//};
//class Ice : public Item {
//private: 
//public:
//	int getPrice() { return 500; }
//	void active() {
//		for(int i = 0; i < monsters.size(); i++) {
//			if(monsters[i]->IsSpawn())
//            	monsters[i]->SetPause(50);
//        }
//	}
//};
//class Bomp : public Item {
//public:
//	int getPrice() { return 500; }
//	void active() {
//		for (int i = 0; i < monsters.size(); i++) {
//			if (monsters[i]->IsSpawn() && monsters[i]->IsLife()) {
//				monsters[i]->HPChange(100000);
//				cout << endl << monsters[i]->IsLife();
//			}
//		}
//	}
//};