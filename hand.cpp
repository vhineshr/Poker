#include "hand.h"
#include <iostream>
#include <algorithm>
/**
 * Add in individual card to a player's hand 
 */
void Hand::add(Card card) 
{
    cards.push_back(card);
}
/**
 * Dump out a user's hand to STDOUT
 */
void Hand::showHand() 
{
    for (unsigned int i(0); i < cards.size(); i++)
    {
        std::cout << cards[i].str() << " ";

    }
}
 /**
  * Dump out the current user's hand. We check for the following
  * combinations:
  *    Four of a kind
  *    Flush (all cards the same suit)
  *    Three of a kind
  *    Two pair
  *    One pair
  *
  *@param value stores value of cards.
  *@param suit stores the suit of cards.
  *@param a1 boolean varaiable.
  *@param a2 boolean varaiable.
  *@param b1 boolean varaiable.
  *@param b2 boolean varaiable.
  *@param b3 boolean varaiable.
  */
void Hand::check() 
{

    std::vector<int> value;
    std::vector<int> suit;
    bool a1, a2, b1, b2, b3;
    int count1 = 0, count2 = 0, count3 = 0;

    for (int i = 0; i < cards.size(); i++) 
    {
        value.push_back(cards[i].getValue());
        suit.push_back(cards[i].getSuit());
    }
    for (int i=0; i < cards.size(); i++) 
    {

        for (int j = i + 1; j < cards.size(); j++) 
        {
            if (cards[i].getValue() == cards[j].getValue()) 
            {
                count1++;
            }
        }

    }
    sort(value.begin(), value.end());
    sort(suit.begin(), suit.end());

    if (suit[0] == suit[4]) 
    {
        count1 = 5;
    }

   
    b1 = ((value[0] == value[1]) && (value[1] == value[2]) && (value[3] != value[0]) &&
            (value[4] != value[0]) && (value[3] != value[4]));
    b2 = ((value[1] == value[2]) && (value[2] == value[3]) && (value[0] != value[1]) &&
            (value[4] != value[1]) && (value[0] != value[4]));
    b3 = ((value[2] == value[3]) && (value[3] == value[4]) && (value[0] != value[2]) &&
            (value[1] != value[2]) && (value[0] != value[1]));

    if (b1 || b2 || b3) 
    {
        count1 = 3;
    }
    
    a1 = ((value[0] == value[1]) && (value[1] == value[2]) && (value[2] == value[3]));
    a2 = ((value[1] == value[2]) && (value[2] == value[3]) && (value[3] == value[4]));
    if (a1 || a2) 
    {
        count1 = 4;
    }
    switch (count1) 
    {
        case 1:
            std::cout << "  One Pair";
            break;
        case 2:
            std::cout << "  Two Pair";
            break;
        case 3:
            std::cout << "  Three of A Kind";
            break;
        case 4:
            std::cout << "  Four of A Kind";
            break;
        case 5:
            std::cout << "  Flush";
            break;
    }
}

