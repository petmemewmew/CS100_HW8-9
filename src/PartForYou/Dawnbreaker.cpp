//
// Created by 26963 on 2022/6/3.
//

#include "Dawnbreaker.h"

Dawnbreaker::Dawnbreaker(GameWorld *world) : GameObject(IMGID_DAWNBREAKER, 300, 100, 0, 0, 1.0, world) {
    HP = 100;
    energy = 10;
    level_up = 0;
}


void Dawnbreaker::Update() {
    if (HP <= 0) {
        is_dead = 1;
        return;
    } else {
//        GameObject* crash_item1 = this_world->iterate_crash(this);
//        if(crash_item1->return_type() != "Dawnbreaker"){
//            if (crash_item1->return_type() == "Enemy"){
//                life_cost(20);
//                crash_item1->set_dead();
//            }else if(crash_item1->return_type() == "Red_Bullet"){
//                life_cost(crash_item1->return_hurt());
//                crash_item1->set_dead();
//            }else if(crash_item1->return_type()=="Goodie"){
//                crash_item1->set_dead();
//            }
//        }
//        if (HP <= 0) {
//            is_dead = 1;
//            return;
//        }
        if (this_world->GetKey(KeyCode::UP)) {
            if (GetY() + 4 <= (WINDOW_HEIGHT - 1)) {
                MoveTo(GetX(), GetY() + 4);
            }
        }
        if (this_world->GetKey(KeyCode::DOWN)) {
            if (GetY() - 4 >= 50) {
                MoveTo(GetX(), GetY() - 4);
            }
        }
        if (this_world->GetKey(KeyCode::LEFT)) {
            if (GetX() - 4 >= 0) {
                MoveTo(GetX() - 4, GetY());
            }
        }
        if (this_world->GetKey(KeyCode::RIGHT)) {
            if (GetX() + 4 <= (WINDOW_WIDTH - 1)) {
                MoveTo(GetX() + 4, GetY());
            }
        }
        if (this_world->GetKey(KeyCode::FIRE1)) {
            if (energy >= 10) {
                this_world->add_item(
                        new Blue_Bullet(GetX(), GetY() + 50, 0.5 + 0.1 * level_up, 5 + 3 * level_up, this_world));
//                std::cout<<this_world->object_num()<<std::endl;
                energy -= 10;
            }
        }
        if(this_world->GetKeyDown(KeyCode::FIRE2)){
            if(meteor_count > 0){
                meteor_count--;
                this_world->add_item(new Meteor(GetX(), GetY() + 100, this_world));
            }
        }
//        GameObject* crash_item2 = this_world->iterate_crash(this);
//        if(crash_item2->return_type() != "Dawnbreaker"){
//            if (crash_item2->return_type() == "Enemy"){
//                life_cost(20);
//                crash_item2->set_dead();
//            }else if(crash_item2->return_type() == "Red_Bullet"){
//                life_cost(crash_item2->return_hurt());
//                crash_item2->set_dead();
//            }else if(crash_item2->return_type()=="Goodie"){
//                crash_item2->set_dead();
//            }
//        }
        if (HP <= 0) {
            is_dead = 1;
            return;
        }
        if (energy < 10) {
            energy++;
        }
        return;
    }
}

void Dawnbreaker::life_cost(int hurt) {
    HP -= hurt;
}

std::string Dawnbreaker::return_type() {
    std::string type = "Dawnbreaker";
    return type;
}

int Dawnbreaker::get_life() {
    return HP;
}

void Dawnbreaker::life_increase(int amount) {
    HP += amount;
    if (HP > 100) {
        HP = 100;
    }
}

void Dawnbreaker::level_count() {
    level_up++;
}

void Dawnbreaker::get_meteor() {
    meteor_count++;
}

int Dawnbreaker::meteor_count_fun() {
    return meteor_count;
}

