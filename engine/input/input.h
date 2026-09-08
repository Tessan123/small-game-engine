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
    Exit
};

enum class BindingType
{
    Key,
    MouseButton
};

struct InputBinding {
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

    static void Bind(Action action, Key key);
    static void Bind(Action action, MouseButton MouseButton);

private:
    static int ToGLFWKey(Key key);
    static int ToGLFWMouseButton(MouseButton button);
    static InputBinding GetBindingForAction(Action action);

    static std::array<bool, GLFW_KEY_LAST + 1> currentKeys;
    static std::array<bool, GLFW_KEY_LAST + 1> previousKeys;

    static std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> currentMouseButtons;
    static std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> prevoiusMouseButtons;

    static std::array<InputBinding, 7> bindings;
};