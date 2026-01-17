#include <raylib.h>

struct Ball {
	int posX;
	int posY;
	float radius;
};

struct Box {
	int posX;
	int posY;
	const int width;
	const int height;
	int count;
};

struct Cursor {
	int posX;
	int posY;
};

int main() {
	const int screenWidth = 400;
	const int screenHeight = 800;
	const int playgroundHeight = 700;
	const int playgroundStartPosY = screenHeight - playgroundHeight;
	const int rows = 7;
	const int columns = 7;

	int balls = 1;
	int round = 1;

	InitWindow(screenWidth, screenHeight, "Ballzy");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		// Draw Header
		DrawRectangle(0, 0, screenWidth, screenHeight - playgroundHeight, GRAY);

		// Game Logic
		// Rows
		for (int i = playgroundStartPosY; i <= playgroundHeight; i += 50) {
			DrawLine(0, i, screenWidth, i, RED);
		}

		// Columns
		for (int i = 1; i <= columns; i++) {
			DrawLine(i * 50, screenHeight - playgroundHeight, i * 50, playgroundHeight, RED);
		}

		Vector2 mousePos = GetMousePosition();

		// Draw Footer
		DrawRectangle(0, playgroundHeight, screenWidth, screenHeight - playgroundHeight, GRAY);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}