#include "gameHeader.h"
//=====================================================
// Connor Giese
// Due: 4/17/2024
// file name: game.cpp
// Description: Alien Attack game
//=====================================================


int main()
{
	//base for rand() later on (using regular srand(time(NULL)) was causing a definable pattern) -- this version uses milliseconds
	auto now = chrono::high_resolution_clock::now();
	auto ms = chrono::time_point_cast<std::chrono::milliseconds>(now);
	srand(static_cast<unsigned int>(ms.time_since_epoch().count()));

	// Create the window for graphics. 
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Automaton Attack!");

	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	//create player
	Diver* diver = new Diver;
	//create wave of automatons
	Army army;
	//list of player missiles
	list<Missile*> PlayerMissiles;
	//list of enemy missiles
	list<Missile*> EnemyMissiles;
	//background pixie
	Pixie background("Helldiver Map.png", 0, 0, BACKGROUND_PIXIE);

	//output starting lives
	cout << "Lives: " << Diver::getLives() << endl << endl;

	//set background scale
	background.setScale(WINDOW_MULTIPLIER, WINDOW_MULTIPLIER);

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		// This while loop checks to see if anything happened since last time
		// we drew the window and all its graphics. 
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) // Did the user kill the window by pressing the "X"?
				//closes window
				window.close();
			else if (event.type == Event::KeyPressed) // did the user press a key on the keyboard?
			{
				if (event.key.code == Keyboard::Space && Missile::getCount() < DIVER_MISSLE_LIMIT) //did the user press space, and is a missile ready to fire?
				{
					//creates missile and adds it to missile list
					PlayerMissiles.push_back(new Missile(diver->getDiver(), diver)); 
				}
			}
		}
		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================
		
		//checks for missiles off screen
		MissileOutOfBounds(PlayerMissiles);
		MissileOutOfBounds(EnemyMissiles);

		//check for player hit
		if (DiverHit(diver, EnemyMissiles, army.getArmy()) && Diver::getLives() > 0) { //if player has lives left, respawns diver
			//respawns diver
			respawn(diver);
		}
		else if (Diver::getLives() <= 0){ //if no more lives left, end game
			//clears screen
			window.clear(); 
			//displays cleared screen
			window.display(); 
			//outputs lose message
			cout << endl << "You Lost!" << endl;
			//pauses game for player to read screen
			system("pause"); 
			//leaves game while loop and ends game
			break; 
		}

		//check for automaton hit
		if (army.getArmy().size() > 0) { //if there are still automatons alive
			//checks if any automaton has been hit
			army.AutomatonHit(PlayerMissiles);
		}
		else { //all automatons are dead, game end
			//clears screen
			window.clear(); 
			//displays cleared screen
			window.display();
			//displays won message
			cout << endl << "You Won!" << endl;
			//pauses game for player to read screen
			system("pause"); 
			//leaves game while loop and ends game
			break; 
		}

		//draw background
		background.draw(window);

		//chance for Automaton to shoot a missile
		army.AutomatonAttack(EnemyMissiles, diver);

		//check for player missile movement
		for (auto mis : PlayerMissiles) {
			//moves missile
			mis->move();
		}
		//draw player missiles
		for (auto mis : PlayerMissiles) {
			//draws missile
			mis->getMissile()->draw(window);
		}

		//check for enemy missile movement
		for (auto mis : EnemyMissiles) {
			//moves missile
			mis->move();
		}
		//draw enemy missiles
		for (auto mis : EnemyMissiles) {
			//draw missile
			mis->getMissile()->draw(window);
		}

		//check for diver movement
		diver->move();
		//draw diver
		diver->getDiver()->draw(window);

		//check for automaton movement
		army.move();
		//draw automatons
		for (auto automaton : army.getArmy()) { //reads army pixies
			//draws pixies
			automaton->getAutomaton()->draw(window); 
		}

		//display window
		window.display();
	} // end body of animation loop

	return 0;
}

