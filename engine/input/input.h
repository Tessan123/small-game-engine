#pragma once

#include <GLFW/glfw3.h>
#include <array>

enum class Key
{
    W,
    A,
    S,
    D,
    Escape
};

enum class MouseButton
{
    Left,
    Right
};

enum class Action
{
    MoveForvard,
    MoveBackward,
    MoveLeft,
    MoveRight,
    Shoot,
    Aim,
    Exit,
    ZoomIn,
    ZoomOut
};

enum class BindingType
{
    Key,
    MouseButton
};

struct InputBinding
{
    BindingType type;
    Key key;
    MouseButton mouseButton;
};

class Input
{
public:
    static void Update(GLFWwindow *window);

    static bool IsKeyDown(Key key);
    static bool WasKeyPressed(Key key);
    static bool WasKeyReleased(Key key);

    static bool IsMouseButtonDown(MouseButton button);
    static bool WasMouseButtonPressed(MouseButton button);
    static bool WasMouseButtonReleased(MouseButton button);

    static bool IsActionDown(Action action);
    static bool WasActionPressed(Action action);
    static bool WasActionReleased(Action action);

    static double GetMouseX();
    static double GetMouseY();

    static double GetMouseDeltaX();
    static double GetMouseDeltaY();

    static double GetScrollDelta();
    static void AddScroll(double amount);
    static void ResetScroll();

    static void Bind(Action action, Key key);
    static void Bind(Action action, MouseButton button);

private:
    static int ToGLFWKey(Key key);
    static int ToGLFWMouseButton(MouseButton button);
    static InputBinding GetBindingForAction(Action action);

    static std::array<bool, GLFW_KEY_LAST + 1> currentKeys;
    static std::array<bool, GLFW_KEY_LAST + 1> previousKeys;

    static std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> currentMouseButtons;
    static std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> prevoiusMouseButtons;

    static double mouseX;
    static double mouseY;
    static double previousMouseX;
    static double previousMouseY;

    static double scrollDelta;

    static std::array<InputBinding, 9> bindings;
};

void ScrollCallback(GLFWwindow *window, double xOffset, double yOffset);