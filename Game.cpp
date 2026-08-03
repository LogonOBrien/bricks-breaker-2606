#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	Reset();
}

void Game::Reset()
{
	Console::SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	Console::CursorVisible(false);
	paddle.width = 12;
	paddle.height = 2;
	paddle.x_position = 32;
	paddle.y_position = 30;

	ball.visage = 'O';
	ball.color = ConsoleColor::Cyan;
	ResetBall();

	// TODO #2 - Add this brick and 4 more bricks to the vector
	brick[0].width = 10;
	brick[0].height = 2;
	brick[0].x_position = 0;
	brick[0].y_position = 5;
	brick[0].doubleThick = true;
	brick[0].color = ConsoleColor::DarkGreen; 
	
	brick[1].width = 10;
	brick[1].height = 2;
	brick[1].x_position = 0;
	brick[1].y_position = 5;
	brick[1].doubleThick = true;
	brick[1].color = ConsoleColor::DarkGreen;
	
	brick[2].width = 10;
	brick[2].height = 2;
	brick[2].x_position = 0;
	brick[2].y_position = 5;
	brick[2].doubleThick = true;
	brick[2].color = ConsoleColor::DarkGreen;
	
	brick[3].width = 10;
	brick[3].height = 2;
	brick[3].x_position = 0;
	brick[3].y_position = 5;
	brick[3].doubleThick = true;
	brick[3].color = ConsoleColor::DarkGreen;
	
	brick[4].width = 10;
	brick[4].height = 2;
	brick[4].x_position = 0;
	brick[4].y_position = 5;
	brick[4].doubleThick = true;
	brick[4].color = ConsoleColor::DarkGreen;

	
	
}

void Game::ResetBall()
{
	ball.x_position = paddle.x_position + paddle.width / 2;
	ball.y_position = paddle.y_position - 1;
	ball.x_velocity = rand() % 2 ? 1 : -1;
	ball.y_velocity = -1;
	ball.moving = false;
}

bool Game::Update()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x1)
		return false;

	if (GetAsyncKeyState(VK_RIGHT) && paddle.x_position < WINDOW_WIDTH - paddle.width)
		paddle.x_position += 2;

	if (GetAsyncKeyState(VK_LEFT) && paddle.x_position > 0)
		paddle.x_position -= 2;

	if (GetAsyncKeyState(VK_SPACE) & 0x1)
		ball.moving = !ball.moving;

	if (GetAsyncKeyState('R') & 0x1)
		Reset();

	ball.Update();
	CheckCollision();
	return true;
}

//  All rendering, including text, should occur in the Render function
void Game::Render() const
{
	Console::Lock(true);
	Console::Clear();
	
	paddle.Draw();
	ball.Draw();

	// TODO #3 - Update render to render all bricks
	
	brick.Draw();


	Console::Lock(false);
}

void Game::CheckCollision()
{
	// TODO #4 - Update collision to check all bricks
	
		if (brick.Contains(ball.x_position + ball.x_velocity, ball.y_position + ball.y_velocity))
		{
			brick.color = ConsoleColor(brick.color - 1);
			ball.y_velocity *= -1;

			// TODO #5 - If the ball hits the same brick 3 times (color == black), remove it from the vector
			
		}
	
	// TODO #6 - If no bricks remain, pause ball and display (render) victory text with R to reset


	if (paddle.Contains(ball.x_position + ball.x_velocity, ball.y_velocity + ball.y_position))
	{
		ball.y_velocity *= -1;
	}

	// TODO #7 - If ball touches bottom of window, pause ball and display (render) defeat text with R to reset
}
