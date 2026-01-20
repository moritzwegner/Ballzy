#include <math.h>
#include <raylib.h>

typedef struct Ball {
	int posX;
	int posY;
	int velocityX;
	int velocityY;
	float radius;
} Ball;

typedef struct Box {
	int posX;
	int posY;
	const int width;
	const int height;
	int count;
} Box;

typedef struct Cursor {
	double posX;
	double posY;
	double radius;
} Cursor;

int main() {
	const int screenWidth = 400;
	const int screenHeight = 800;
	const int playgroundHeight = 700;
	const int playgroundStartPosY = screenHeight - playgroundHeight;
	const int rows = 7;
	const int columns = 7;
	const int BALL_SIZE = 10;
	int BALL_INDEX = 0;
	Ball balls[BALL_SIZE] = { 0 };

	int round = 1;

	InitWindow(screenWidth, screenHeight, "Ballzy");

	SetTargetFPS(60);

	Cursor cursor;
	cursor.posX = screenWidth / 2;
	cursor.posY = playgroundHeight - 10;
	cursor.radius = 10;

	Cursor cursor2;
	cursor2.posX = screenWidth / 2;
	cursor2.posY = playgroundHeight - 25;
	cursor2.radius = 5;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		// Draw Header
		DrawRectangle(0, 0, screenWidth, screenHeight - playgroundHeight, GRAY);

		// Game Logic

		// Cursor
		DrawCircle(cursor.posX, cursor.posY, cursor.radius, WHITE);
		DrawCircle(cursor2.posX, cursor2.posY, cursor2.radius, WHITE);

		DrawCircleLines(screenWidth / 2, playgroundHeight, 100, BLUE);

		// Rows
		for (int i = playgroundStartPosY; i <= playgroundHeight; i += 50) {
			DrawLine(0, i, screenWidth, i, RED);
		}

		// Columns
		for (int i = 1; i <= columns; i++) {
			DrawLine(i * 50, screenHeight - playgroundHeight, i * 50, playgroundHeight, RED);
		}

		Vector2 mousePos = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Ball ball_temp;
			ball_temp.posX = mousePos.x;
			ball_temp.posY = mousePos.y;
			ball_temp.velocityX = 10;
			ball_temp.velocityY = 10;
			ball_temp.radius = 10;
			balls[BALL_INDEX] = ball_temp;
			BALL_INDEX++;

		}

		// Update balls
		for (int i = 0; i <= BALL_INDEX; i++) {

			balls[i].posX += balls[i].velocityX;
			balls[i].posY += balls[i].velocityY;

			if (balls[i].posX - balls[i].radius <= 0 || balls[i].posX + balls[i].radius >= screenWidth) {
				balls[i].velocityX *= -1;
			}

			if (balls[i].posY - balls[i].radius <= playgroundStartPosY || balls[i].posY + balls[i].radius >= playgroundHeight) {
				balls[i].velocityY *= -1;
			}

			DrawCircle(balls[i].posX, balls[i].posY, balls[i].radius, WHITE);
		}

		// Draw Footer
		DrawRectangle(0, playgroundHeight, screenWidth, screenHeight - playgroundHeight, GRAY);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}