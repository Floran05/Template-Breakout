#pragma once

#define WIN_HEIGHT								720
#define WIN_WIDTH								1280
#define WIN_SIZE								{WIN_WIDTH, WIN_HEIGHT}
#define WIN_TITLE								"Goofy Breakout"
#define FRAMERATE_LIMIT							60

#define BALL_SPRITE_PATH						".\\assets\\benball.png"
#define BRICK_SPRITE_PATH						".\\assets\\brick.png"
#define BRICK2_SPRITE_PATH						".\\assets\\brick2.png"
#define BRICK3_SPRITE_PATH						".\\assets\\brick3.png"
#define PADDLE_SPRITE_PATH						".\\assets\\PaddleSprite.png"
#define GAMEOVER_SPRITE_PATH					".\\assets\\GameOverPanel.png"

#define DEFAULT_FONT_PATH						".\\assets\\SuperShiny.ttf"

#define BRICK_COLUMNS_COUNT						10
#define BRICK_ROWS_COUNT						3
#define BRICK_MARGIN							20.f
#define BRICK_RATIO								1065 / 553.f

#define PADDLE_RELATIVE_WIDTH					0.15f
#define PADDLE_RATIO							1500.f / 265.f

#define SPAWNER_Y_SHIFT							50.f
#define SPAWNER_START_BRICK_AMOUNT				6
#define SPAWNER_GROW_PHASE_PERCENT_LIMIT		0.6f
#define SPAWNER_GROW_PHASE_SPAWN_AMOUNT			2

#define BALL_RADIUS								25.f

#define BOUNCE_AUDIO							".\\assets\\Audio\\sfx_Ball_Bounce.wav"
#define DESTROY_AUDIO							".\\assets\\Audio\\sfx_Brick_Destroy.wav"
#define LOOSE_AUDIO								".\\assets\\Audio\\sfx_Loose.wav"
#define MUSIC_AUDIO								".\\assets\\Audio\\music_Arcade_Loop.wav"