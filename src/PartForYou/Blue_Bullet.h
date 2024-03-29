//
// Created by 26963 on 2022/6/3.
//

#ifndef DAWNBREAKER_BLUE_BULLET_H
#define DAWNBREAKER_BLUE_BULLET_H

#include <GameObjects.h>
#include "GameWorld.h"

class GameObject;

class GameWorld;

class Blue_Bullet : public GameObject {
public:
    Blue_Bullet(int x, int y, double size, int hit, GameWorld *world);

    void Update() override;

    std::string return_type() override;

    int return_hurt() override;

private:
    int hurt;
};

#endif //DAWNBREAKER_BLUE_BULLET_H
