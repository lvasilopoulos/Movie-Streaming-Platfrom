#include <iostream>
#include <random>
#include <string>

#include <graphics.h>
#include "MainPanel.h"
#include "Main.h"

static MainPanel mainPanel;

void draw() {
	mainPanel.draw();
}

void update(float ms) {
	mainPanel.update(ms);
}

int main() {
	mainPanel.init();

	const auto assets = graphics::preloadBitmaps("assets/fonts");
	for (const auto asset : assets) {
		std::cout << "PRELOADING : " << asset << std::endl;
	}

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::startMessageLoop();
	graphics::destroyWindow();

	return 0;
}
