#pragma once

#include "Gaits.h"
#include "Vec3.h"
#include <vector>
#include "Enums.h"

class Hexapod;

struct WalkTranslations
{
    std::vector<LegType> legs;
    Vec3 feetTranslation;
    Vec3 bodyTranslation;

    WalkTranslations(std::vector<LegType> legs,
                     Vec3 feetTranslation,
                     Vec3 bodyTranslation)
    {
        this->legs = legs;
        this->feetTranslation = feetTranslation;
        this->bodyTranslation = bodyTranslation;
    }
};

struct Rotations
{
    std::vector<LegType> legs;
    double bodyDeltaAngle;
    double feetDeltaAngle;
    double feetZ;

    Rotations(std::vector<LegType> legs,
                       double bodyDeltaAngle,
                       double feetDeltaAngle,
                       double feetZ)
    {
        this->legs = legs;
        this->bodyDeltaAngle = bodyDeltaAngle;
        this->feetDeltaAngle = feetDeltaAngle;
        this->feetZ = feetZ;
    }
};

class GaitsManager
{
private:
    static GaitsManager *instance;
    Hexapod *hexapod = NULL;

    GaitsManagerStates state = GaitsManagerStates::STOPPED;

    std::vector<std::vector<LegType>> selectedGait;

    double walkDirection;
    double newWalkDirection = -1;

    RotateDirection rotateDirection;
    RotateDirection newRotateDirection;
    
    int stepsCount;
    int stepFrame;

    // Walk functions
    static void updateWalkStep(void *parameter);
    void _updateWalkStep();
    void checkWalkDirection();

    // Rotate functions
    static void updateRotateStep(void *parameter);
    void _updateRotateStep();
    void checkRotateDirection();

    void checkStepState();
    void onStopped();

public:
    GaitsManager();
    void init(Hexapod *hexapod);
    void selectGait(GaitType type);
    void startWalk(double walkDirection);
    void startRotate(RotateDirection rotateDirection);
    void stop();
};