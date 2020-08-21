// Include standard headers
#include <stdio.h>
#include <stdlib.h>
// Include GLM
#include <glm.hpp>
#include <iostream>
#include "Renderer.h"

class Pujipen
{
public:
	void init() 
	{
		renderer.init(1920, 1080);
		std::cout << "Advantures of Puj I Pen" << std::endl;
	}
	Graphics::Renderer renderer;
};

int main(void)
{
	Pujipen game;
	game.init();
	do
	{
		game.renderer.render();
	}
	while (game.renderer.isWorking() == 0);
}


