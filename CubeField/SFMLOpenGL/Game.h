#ifndef GAME_H
#define GAME_H

#include <string>
#include <sstream>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <Debug.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <GameObject.h>

#include "Goal.h"

using namespace std;
using namespace sf;
using namespace glm;

class Game
{
public:
	Game();
	Game(sf::ContextSettings settings);
	~Game();
	void run();
private:
	GameObject* game_object[290];
	RenderWindow window;
	Clock clock;
	Time time;
	Goal targetGoal;
	bool animate = false;
	vec3 animation = vec3(0.0f);
	float rotation = 0.0f;
	bool isRunning = false;
	void initialize();
	void update();
	void checkCollision();
	void render();
	void unload();

	int sizeOfArray = 290;
	float speed = 0.002f;
	float playerSpeed = 0.008f;
	int score = 0;
	float pos = -0.5f;

	bool endGame = false;
	bool goalSuccess = false;

};

#endif  // ! GAME_H