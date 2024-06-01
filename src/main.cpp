/*
 * Black Jack game implementation directly through the CLI.
 * Created by @sudfish 
 * Start Date - 2024-05-27
 * End Date - 2024-05-31 
*/


#include "Game.hpp"

int main (int argc, char *argv[]) {
    blackjack::Game game = blackjack::Game();
    game.Run();
    return 0;
}
