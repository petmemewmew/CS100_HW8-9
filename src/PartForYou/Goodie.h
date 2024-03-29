//
// Created by 26963 on 2022/6/8.
//

#ifndef ALPHATRON_CPP_GOODIE_H
#define ALPHATRON_CPP_GOODIE_H
#include "GameObjects.h"
#include "GameWorld.h"

class Goodie: public GameObject{
public:
    Goodie(int IMGID, int x, int y, GameWorld* world);

    void Update() override;

    void set_dead() override;

    virtual void crash() = 0;

    std::string return_type() override;

};


#endif //ALPHATRON_CPP_GOODIE_H
