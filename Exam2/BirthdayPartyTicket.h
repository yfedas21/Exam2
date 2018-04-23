#ifndef _BIRTHDAY_PARTY_TICKET_H_
#define _BIRTHDAY_PARTY_TICKET_H_

#include <list>
#include <string>
#include "Party.h"
#include "PartyTicket.h"

class BirthdayPartyTicket : public PartyTicket
{
private: 

	Party * the_party; // The party this ticket is associated with
	std::list<std::string>::iterator me; // My location in the BirthdayParty list

public:
	/**
	* Constructor for creating a BirthdayPartyTicket.
	* @param the_party party to which this ticket belongs
	* @param me		   party goer to which this ticket is associated with
	*/
	BirthdayPartyTicket(Party *the_party, std::list<std::string>::iterator &me) :
		the_party(the_party), me(me) {}

	/**
	* Allows the partygoer (me) to leave the party "the_party"
	* The implementation for this is in BirthdayPartyTicket.cpp.
	*/
	void leave();
};

#endif