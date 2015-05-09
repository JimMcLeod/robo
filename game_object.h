#ifndef _GAMEOBJECT_INCLUDED__
#define _GAMEOBJECT_INCLUDED__

struct GameObject
{
    bool active;
    int id;
    int type;

    bool senseless; // if true input is igmored
    bool thrustAvailable; // if true player can move using thrust
    bool verticalMovement; // if true up/down moves player

    float x;
    float y;
    float width;
    float height;

    float direction;
    float turnRate;
    float noOfDirections;

    float speed;
    float topSpeed;
    float acceleration;
    float friction;

    float animFrame;
    float animUpdate;
    float animNoOfFrames;

    void (*render)(GameObject&);
    void (*update)(GameObject&);
};
#endif

