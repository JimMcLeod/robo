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

    bool asteroidStyle; //  if true asyeroids style movement
    bool thrustActivated; // if true thrust was pressed
    float xVector;
    float yVector;

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

    float fireReady;
    float fireRate;
    float fireReset;

    void (*render)(GameObject&);
    void (*update)(GameObject&);
};
#endif

