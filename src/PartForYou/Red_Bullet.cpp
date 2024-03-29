//
// Created by 26963 on 2022/6/3.
//

#include "Red_Bullet.h"

Red_Bullet::Red_Bullet(int x, int y, int direction, int hit, GameWorld *world) : GameObject(IMGID_RED_BULLET, x, y,
                                                                                            direction, 1, 0.5, world) {
    hurt = hit;
}


void Red_Bullet::Update() {
    if (is_dead) {
        return;
    } else {
        if (GetY() < 0) {
            is_dead = 1;
            return;
        } else {
            if (this_world->is_crash(this, this_world->return_Dawnbreaker())) {
                this_world->return_Dawnbreaker()->life_cost(hurt);
                if (this_world->return_Dawnbreaker()->get_life() <= 0) {
                    this_world->return_Dawnbreaker()->set_dead();
                }
                is_dead = 1;
                return;
            } else {
                switch (GetDirection()) {
                    case 180:
                        MoveTo(GetX(), GetY() - 6);
                        break;
                    case 162:
                        MoveTo(GetX() + 2, GetY() - 6);
                        break;
                    case 198:
                        MoveTo(GetX() - 2, GetY() - 6);
                        break;
                    default:
                        break;
                }
                if(!this_world->return_Dawnbreaker()->check_dead()) {
                    if (this_world->is_crash(this, this_world->return_Dawnbreaker())) {
                        this_world->return_Dawnbreaker()->life_cost(hurt);
                        if (this_world->return_Dawnbreaker()->get_life() <= 0) {
                            this_world->return_Dawnbreaker()->set_dead();
                        }
                        set_dead();
                        return;
                    }
                }
            }
        }
    }
    return;
}

std::string Red_Bullet::return_type() {
    std::string type = "Red_Bullet";
    return type;
}

