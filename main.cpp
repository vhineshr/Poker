#include "deck.h"
#include "hand.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;
/**
* The main program
* @param deck the object of deck class.
* @param players stores the number of players.
* @param seed the random seed variable.
* @param play the vector of dealt cards.
* @param hand the object of hand class. 
*/   

int main() 
{
    vector< Hand > hands;
    Deck deck;
    int players;
    int seed;
    int sizeOfHand = 5;
    std::vector< Card > play;
    cout << "Enter seed: ";
    cin >> seed;
    srand(unsigned(seed));
    cout << "Enter number of players: ";
    cin >> players;
    deck.Shuffle();
    Hand hand[players];
    int test = 1, i = 0;
    while (test) 
    {   if(i % 5 == 0)
        {
        play = deck.Deal(5);
        deck.ShowDeck();
        }
        hand[i % players].add(play[i]);
        i++;
        if (i == (players * 5)) 
        {
            break;
        }
    }
    for (int i = 0; i < players; i++)
    {
        int p = i + 1;
        cout << "Player " << p << " hand: ";
        hand[i].showHand();
        cout << " ";
        hand[i].check();
        cout << endl;

    }
   //system("PAUSE");
   return 1;
}
