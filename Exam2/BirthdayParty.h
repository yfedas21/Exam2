#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
private:
	std::list<std::string> room;

	BirthdayParty() {} 
	
	/** Only the PartyFactory can create a BirthdayParty 
	* because the constructor is private and PartyFactory
	* is a friend class of BirthdayParty
	*/
	friend class PartyFactory; 

public:
	/**
	* Add a person to the pary
	* @param name the name of the party goer
	*/
	PartyTicket *add(std::string name) {
		room.push_front(name);
		std::list<std::string>::iterator i = room.begin();
		return new BirthdayPartyTicket(this, i);
	}

	/**
	* List all the persons currently at the party
	*/
	void list() {
		for (auto i : room)
			std::cout << i << std::endl;
	}

	/**
	* Remove the person identified by the iterator from the party
	*/
	void remove(std::list<std::string>::iterator it) {
		room.erase(it);
	}
};

#endif