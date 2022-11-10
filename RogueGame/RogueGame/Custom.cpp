/*
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class custom
{
    public:
        string name;
};

void main()
{
    vector<custom> weaponList; //create array called weaponList

    custom weapon; //custom class called weapon now

    weapon.name = "Knife";

    //adds "Knife" to the array
    weaponList.push_back(weapon);
    weaponList.push_back(weapon);
    weaponList.push_back(weapon);
    weaponList.push_back(weapon);
	weaponList.push_back(weapon);
	weaponList.push_back(weapon);

	vector<custom>::iterator it; //iterator called it

	it = weaponList.begin(); //put iterator at the begining of vector

	it += 3; // 4th index of the vector

	it = weaponList.insert(it, "Gun"); //adds bat in 4th index

	it = weaponList.begin(); //put iterator at the begining of vector

	it += 4; // 5th index of the vector

	weaponList.erase(it); // delete where iterator is

	weaponList.erase(weaponList.end() - 1); // delete last element

}*/