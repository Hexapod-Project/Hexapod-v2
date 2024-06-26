#pragma once

#include <vector>
#include "Servo.h"
#include "Vec3.h"
#include "Mat4.h"
#include "Enums.h"

class Leg
{
private:
    Mat4 matrix;
    Vec3 currentFeetPosition;
    Mat4 *root = new Mat4();
    double baseAngle;
    Servo *coxaServo;
    Servo *femurServo;
    Servo *tibiaServo;
    double getCoxaAngle(Vec3 feetPosition);
    double getFemurAngle(Vec3 feetPosition);
    double getTibiaAngle(Vec3 feetPosition);
    double checkAngleOrientation(double angle);

public:
    Leg(double angle, Servo *coxaServo, Servo *femurServo, Servo *tibiaServo);
    void setRoot(Mat4 *root);
    void setFeetPosition(Vec3 feetPosition, bool updateCurrentFeetPosition = true);
    void translateFeetPosition(Vec3 translation, bool updateCurrentFeetPosition = true);
    void updateFeetPosition();
    void rotateFeetPosition(double angle, Vec3 offsetFeetPosition);
    double getBaseAngle();
    double getBaseAngleInRadians();
    void setJointPositions(double coxaDeg, double femurDeg, double tibiaDeg);
};