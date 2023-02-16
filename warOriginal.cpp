#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;


enum class cardName{Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King}; // Assigns card name to all 13 cards
enum class Suit{S, C, D, H}; // Suits for each card

struct Card{ // Makes the card, has cardname, suit, and value
  cardName name; // cardname (ace, two, three, etc.)
  Suit suit; // suit (s, c, d, h)
  int value; // value of the card, this is essential for war game

  void printSuit(){ // calls the suit (since if we cout them they are values of #) and makes them a character so its nice to read
    if (suit == Suit::S)
      cout << "Spades";
    else if (suit == Suit::C)
      cout << "Clubs";
    else if (suit == Suit::D)
      cout << "Diamonds";
    else 
      cout << "Hearts";
  }

  void printValue(){ // this assigns the "name" to the values jack, queen, king, ace
    if (name == cardName::Jack)
      cout << "Jack";
    else if (name == cardName::Queen)
      cout << "Queen";
    else if (name == cardName::King)
      cout << "King";
    else if (name == cardName::Ace)
      cout << "Ace";
    else 
      cout << value; // otherwise it'll cout the int value from line 11
  }
  void printCard(){ // void of the cards being set (value, suit)
    printValue();
    cout << " of ";
    printSuit();
    cout << endl;
  }


};

struct Deck{ // makes the deck for all 52 cards with all 4 suits & 13 numbers
  Card arrCards[52]; // array of 52 cards, pulling "Card" from struct
  
  void printAll(){ // thing to print 
    for (int i = (int)Suit::S; i <= (int)Suit::H; i++){ // for every suit and...
      for (int j = (int)cardName::Ace; j <= (int)cardName::King; j++){ // for every card..
        int index = (13 * i) + j - 1; // explained in line 48
        arrCards[index].printCard(); // puts the card into the index AND runs line 13 (printing the suit)
      }

      cout << endl; // separates after every suit
    }

    
  }

  void setupCards(){
    for (int i = (int)Suit::S; i <= (int)Suit::H; i++){ // for every suit and..
      for (int j = (int)cardName::Ace; j <= (int)cardName::King; j++){ // for every card value
        Card c; // calls struct Card and makes it variable c, 
        c.suit = (Suit)i; // assigns variable c to suit
        c.name = (cardName)j; // assigns variable c to name 
        c.value = (int)c.name; // missed this in class, assigns variable card value to integer form of name.

        int index = (13 * i) + j - 1; // makes the index, multiplies 13 by every suit (imagine a deck of cards laid out), adds the amount of whats it in and - 1 because it starts at 0 (thats how arrays work)
        
        arrCards[index] = c; // puts the card into the index (in order)
      }
    }
  }

  void shuffleCards(){
    random_shuffle(begin(arrCards), end(arrCards)); // shuffles the beginning of the deck>array of cards and the end of deck> array of cards

  }

  void dealCards(int Player1[], int Player2[]){ // an array of 2 players
    for (int i = 0; i < 26; i++){ // for the first half of the array
      Player1[i] = i * 2; 
      Player2[i] = i * 2 + 1;
    } 
  }

  void play(){
    
  }

  void warGame(int Player1[], int Player2[]){ // the error is here somewhere
    shuffleCards();
    dealCards(Player1, Player2);
    int P1Score = 0;
    int P2Score = 0;
    for (int match = 0; match < 26; match++){
      int P1Card = Player1[match];
      int P2Card = Player2[match];
      if (P1Card > P2Card){
        cout << "Player 1 plays " << P1Card << endl;
        cout << "Player 2 plays " << P2Card << endl;
        cout << "Player 1 wins!" << endl;
        P1Score++;
      } 
      else if (P2Card > P1Card){
        cout << "Player 1 plays " << P1Card << endl;
        cout << "Player 2 plays " << P2Card << endl;
        cout << "Player 2 wins!" << endl;
        P2Score++;
      }
      else{
        cout << "It's a tie!";
      }
    }//end of the for loop
    
    if (P1Score > P2Score){
        cout << "Player 1 wins the entire game!";
      }
      else if (P2Score > P1Score){
        cout << "Player 2 wins the entire game!";
      }
      else cout << "It's a tie!"<< endl;  
  }
};



int main() {
  srand(time(0));

  Deck my_deck; // calls the struct 
  my_deck.setupCards(); // calls the void from setupCards and "makes" the deck
  int Player1[26], Player2[26]; // makes the 2 arrays for the 2 players
  my_deck.shuffleCards();
  cout << endl;
  my_deck.dealCards(Player1, Player2); // deals the cards to the 2 players in the void dealCards 
  cout << "Player 1's hand" << endl << "___________________" << endl;
  for (int i = 0; i < 26; i++){
    my_deck.arrCards[Player1[i]].printCard();
  } // this will print player 1s hand
  cout << endl;
  cout << "Player 2's hand" << endl << "___________________" << endl;
  for (int i = 0; i < 26; i++){
    my_deck.arrCards[Player2[i]].printCard();
  } // and this prints player 2s
  cout << endl << endl;
  
  my_deck.warGame(Player1, Player2);
}