#include "card.h"
#include <sstream>
#include <iostream>
//using namespace std;

std::string valToStr();
std::string suitToStr();
/** 
 * Default constructor
 */
Card::Card() 
{
}
/**
 * Constructor to initialize our suit and value
 *
 * @param _suit enum of SUITS
 * @param _val  value of the card (COUNT enum)
 */
Card::Card(Card::SUITS _suit, Card::COUNT _val) 
{
    suit = _suit;
    value = _val;

}
/**
 * Get a string representation of the card.
 * @return string in the format similar to this: "10D", which would be 10
 * of diamonds
 */
std::string Card::str() 
{

   std::ostringstream os;
    os << valToStr() << suitToStr();

    return os.str();
}


/**
 * Accessor to get this card's value in string
 * @return suit of this card
 */
std::string Card::suitToStr() 
{
    switch (suit) 
    {
        case CLUBS:
            return "C";
            break;
        case DIAMONDS:
            return "D";
            break;
        case HEARTS:
            return "H";
            break;
        case SPADES:
            return "S";
            break;
        default:
            return "invalid";
            break;
    }
}
/**
 * Accessor to get this card's value in string
 * @return value of this card
 */
std::string Card::valToStr() 
{
    switch (value) 
    {
        case TWO:
            return " 2";
            break;
        case THREE:
            return " 3";
            break;
        case FOUR:
            return " 4";
            break;
        case FIVE:
            return " 5";
            break;
        case SIX:
            return " 6";
            break;
        case SEVEN:
            return " 7";
            break;
        case EIGHT:
            return " 8";
            break;
        case NINE:
            return " 9";
            break;
        case TEN:
            return "10";
            break;
        case JACK:
            return " J";
            break;
        case KING:
            return " K";
            break;
        case QUEEN:
            return " Q";
            break;
        case ACE:
            return " A";
            break;
        default:
            return "invalid";
            break;
    }
}
/**
 * Accessor to get this card's suit
 * @return value of this card's suit
 */
Card::SUITS Card::getSuit() 
{
    return suit;
}
/**
 * Accessor to get this card's value
 * @return value of this card
 */
Card::COUNT Card::getValue() 
{
    return value;
}

