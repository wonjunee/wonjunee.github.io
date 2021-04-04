/*

Cube Volume = side^3
Sphere Volume = (4/3) * pi * radius^3
Cone Volume = pi * radius^2 * (height/3)

*/

#include<iostream>

int main()
{
    //Dimension of the cube
    float cubeSide = 5.4;

    //Dimension of sphere
    float sphereRadius = 2.33;

    //Dimensions of cone
    float coneRadius = 7.65;
    float coneHeight = 14;
    
    float volCube, volSphere, volCone;

    float pi = 3.14;

    volCube = cubeSide * cubeSide * cubeSide;
    volSphere = 4/3 * pi * sphereRadius*sphereRadius*sphereRadius;
    volCone = pi * coneRadius*coneRadius * coneHeight/3;

    
    return 0;
}