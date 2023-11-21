
#include "TIme.h"
#include "../../Mimicry/include/glfw3.h"


double Time::oldTime = glfwGetTime();

float Time::DeltaTime()
{
    double currentTime = glfwGetTime();
    float deltaTime;
    deltaTime = currentTime - oldTime;
    oldTime = currentTime;
    return deltaTime;
}

float Time::getTime()
{
    return glfwGetTime();
}