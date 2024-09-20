#include "Character.h"
#include "raylib.h"
#include "raymath.h"

Character::Character()
{
}
void Character::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle Character::GetCollisionRec()
{
    return Rectangle
    {
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale
    };
}

Vector2 Character::getScreenPos()
{
    return Vector2();
}

void Character::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

    // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrame)
            frame = 0;
    }

    if (Vector2Length(velocity) != 0.0)
    {
        // set worldPos = worldPos + velocity

        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    velocity = {};

    // draw the character
    Rectangle sourse{ frame * width, 0.f, rightLeft * width, height };
    Rectangle dest{ getScreenPos().x, getScreenPos().y, scale * width, scale * height };
    Vector2 origin{};
    DrawTexturePro(texture, sourse, dest, origin, 0.f, WHITE);
}
