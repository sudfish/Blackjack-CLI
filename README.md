# Black-Jack ♠️  ♥️  ♣️  ♦️

Command-line based version of the classic BlackJack card game, where the player
competes against the dealer to get a hand value as close to 21 as possible
without exceeding it.

## Requirements 
- C++ Compiler
- CMake (or other linking tool)

## Features 
* **Command Line Interface**: Simple layout. 
* **Simulated Dealer**: Dealer stands on all 17's. 

## Instructions 

Upon starting the game, you will be dealt two cards.
The dealer will also be dealt two cards, with one card face up and one card face down.
You can choose to:
* Hit: Draw another card.
* Stand: Keep your current hand.

The goal is to have a hand value as close to 21 as possible without exceeding it.
Face cards (Jack, Queen, King) are worth 10 points. Aces can be worth 1 or 11 points.
The dealer will reveal their hidden card and must hit until their hand is worth at least 17 points.
If your hand exceeds 21, you bust and lose the game. If the dealer busts, you win.
The game ends when either the player or the dealer busts, or both decide to stand.
If both stand on the same value, you push and nobody wins.


## Controls

* `1` to HIT 
* `2` to STAND
* (`yes`/`no`) to restart the game.

---

Feel free to use this however you like. 
- [@sudfish](https://github.com/sudfish)
