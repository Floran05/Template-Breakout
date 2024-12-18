#pragma once

#define WIN_HEIGHT						720
#define WIN_WIDTH						1280
#define WIN_SIZE						{WIN_WIDTH, WIN_HEIGHT}
#define WIN_TITLE						"SFML"
#define FRAMERATE_LIMIT					60

#define BALL_SPRITE_PATH				".\\assets\\benball.png"
#define BRICK_SPRITE_PATH				".\\assets\\brick.png"
#define PADDLE_SPRITE_PATH				".\\assets\\PaddleSprite.png"

#define BRICK_COLUMNS_COUNT 10
#define BRICK_ROWS_COUNT 3
#define BRICK_MARGIN 20.f
#define BRICK_RATIO 1065 / 553.f

#define PADDLE_RELATIVE_WIDTH 0.15f
#define PADDLE_RATIO 1500.f / 265.f

#define SPAWNER_START_BRICK_AMOUNT 3
#define SPAWNER_GROW_PHASE_PERCENT_LIMIT 0.7f
#define SPAWNER_GROW_PHASE_SPAWN_AMOUNT 2