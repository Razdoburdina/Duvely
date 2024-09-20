#pragma once
#include "raylib.h"

class Character
{
public:
    Character();
    Vector2 getWorldPos() const { return worldPos; }
    virtual void tick(float deltaTime);
    void undoMovement();
    Rectangle GetCollisionRec();
    virtual Vector2 getScreenPos();
    bool getAlive() { return alive; }
    void setAlive(bool isAlive) { alive = isAlive; }
protected:
    Texture2D texture{ LoadTexture("characters/knight_idle_spritesheet.png") };
    Texture2D idle{ LoadTexture("characters/knight_idle_spritesheet.png") };
    Texture2D run{ LoadTexture("characters/knight_run_spritesheet.png") };
    Vector2 worldPosLastFrame{};
    Vector2 worldPos{};
    // 1: facing right, -1: facing left
    float rightLeft{ 1.f };
    // animation variables
    float runningTime{ 1.f };
    int frame{};
    int maxFrame{ 6 };
    float updateTime{ 1.f / 12.f };
    float speed{ 4.f };
    float width{};
    float height{};
    float scale{ 4.f };
    Vector2 velocity{};

private:
    bool alive{ true };

};

