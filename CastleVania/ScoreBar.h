#pragma once

#include "GraphicsAssetsManager.h"
#include "GameTime.h"
#include "BaseObject.h";

enum SCOREBAR_ACTION
{
	SCOREBAR_ACTION_NUMBER,
	SCOREBAR_ACTION_LOST_HEART
};

struct SCORE_LOCATION
{
	int X;
	int Y;
	int MaxLength;
};

class ScoreBar
{
	BaseObject* subWeapon;
	GraphicsAssets* scorebarItemSprite;
	LPDIRECT3DTEXTURE9 scoreBar;
	void renderNumber(int num, int x, int y, int maxLength);
	void renderHealth();
	void renderBossHealth();
	void renderSubWeapon();
	static ScoreBar* instance;
	SCORE_LOCATION lifeLocation;
	SCORE_LOCATION heartLocation;
	SCORE_LOCATION stageLocation;
	SCORE_LOCATION scoreLocation;
	SCORE_LOCATION timeLocation;
	SCORE_LOCATION healthLocation;
	SCORE_LOCATION subWeaponLocation;
	SCORE_LOCATION bossHealthLocation;

	int health;
	int bossHealth;
	int maxHealth;
	int playerLife;
	int heartCount;
	int currentStageNumber=1;
	int score;
	int time;
	GameTime timeGame;
public:
	static ScoreBar* getInstance();
	ScoreBar();
	~ScoreBar();
	void render();
	void update();

	void setSubWeapon(BaseObject* subWeapon);

	void restoreHealth();
	void restoreBossHealth();

	int getPlayerLife();
	void setPlayerLife(int playerLife);
	void increasePlayerLife(int playerLife);

	int getHeartCount();
	void setHeartCount(int heartCount);
	void increaseHeartCount(int heartCount);

	int getScore();
	void setScore(int score);
	void increaseScore(int score);

	int getTime();
	void setTime(int time);
	void increaseTime(int time);

	int getHealth();
	void setHealth(int health);
	void increaseHealth(int health);

	int getBossHealth();
	void setBossHealth(int health);
	void increaseBossHealth(int health);

	int getMaxHealth();

	void setCurrentStageNumber(int currentStageNumber);
	int getCurrentStageNumber();
};

