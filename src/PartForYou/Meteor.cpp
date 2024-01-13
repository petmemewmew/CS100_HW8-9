//
// Created by 26963 on 2022/6/3.
//

#include "Meteor.h"

Meteor::Meteor(int x, int y, GameWorld *world) : GameObject(IMGID_METEOR, x, y, 0, 1, 2.0, world) {
    is_dead = 0;
}

void Meteor::Update() {
    if (is_dead == 1) {
        return;
    }
    if (GetY() >= WINDOW_HEIGHT) {
        set_dead();
        return;
    }
//    GameObject *crash_item1 = this_world->iterate_crash(this);
//    if (crash_item1 != nullptr) {
//        if (crash_item1->return_type() == "Enemy") {
//            crash_item1->set_dead();
////            std::cout << "22" << std::endl;
//        }
//    }
    MoveTo(GetX(), GetY() + 2);
    SetDirection(GetDirection() + 5);

//    if (GetY() >= WINDOW_HEIGHT) {
//        set_dead();
//        return;
//    }

    GameObject *crash_item = this_world->iterate_crash(this);
    if (crash_item != nullptr) {
        if (crash_item->return_type() == "Enemy") {
            crash_item->set_dead();
//            std::cout << "11" << std::endl;
        }
    }
}

std::string Meteor::return_type() {
    std::string type = "Meteor";
    return type;
}

int Meteor::return_hurt() {
    return 0;
}
