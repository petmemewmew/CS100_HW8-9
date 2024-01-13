//
// Created by 26963 on 2022/6/3.
//

#include "Explosion.h"

Explosion::Explosion(int x, int y, GameWorld* world): GameObject(IMGID_EXPLOSION, x, y, 0, 3, 4.5, world) {
    tick = 0;
}

void Explosion::Update() {
    SetSize(GetSize() - 0.2);

    if (tick == 20){
        is_dead = 1;
    }
    tick++;
}

std::string Explosion::return_type() {
    std::string type = "Explosion";
    return type;
}


