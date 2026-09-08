#include "input.h"

std::array<bool, GLFW_KEY_LAST + 1> Input::currentKeys{};
std::array<bool, GLFW_KEY_LAST + 1> Input::previousKeys{};

std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> Input::currentMouseButtons{};
std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> Input::prevoiusMouseButtons{};

std::array<InputBinding, 7> Input::bindings{};

void Input::Update(GLFWwindow *window)
{
    previousKeys = currentKeys;
    prevoiusMouseButtons = currentMouseButtons;

    for (int key = 0; key <= GLFW_KEY_LAST; key++)
    {
        currentKeys[key] = glfwGetKey(window, key) == GLFW_PRESS;
    }
    for (int button = 0; button <= GLFW_MOUSE_BUTTON_LAST; button++)
    {
        currentMouseButtons[button] = glfwGetMouseButton(window, button) == GLFW_PRESS;
    }
}

bool Input::IsKeyDown(Key key)
{
    return currentKeys[ToGLFWKey(key)];
}

bool Input::WasKeyPressed(Key key)
{
    int glfwKey = ToGLFWKey(key);
    return currentKeys[glfwKey] && !previousKeys[glfwKey];
}

bool Input::WasKeyReleased(Key key)
{
    int glfwKey = ToGLFWKey(key);
    return !currentKeys[glfwKey] && previousKeys[glfwKey];
}

bool Input::IsMouseButtonDown(MouseButton button)
{
    return currentMouseButtons[ToGLFWMouseButton(button)];
}
bool Input::WasMouseButtonPressed(MouseButton button)
{
    int glfwButton = ToGLFWMouseButton(button);
    return currentMouseButtons[glfwButton] && !prevoiusMouseButtons[glfwButton];
}
bool Input::WasMouseButtonReleased(MouseButton button)
{
    int glfwButton = ToGLFWMouseButton(button);
    return !currentMouseButtons[glfwButton] && prevoiusMouseButtons[glfwButton];
}

bool Input::IsActionDown(Action action)
{
    InputBinding binding = GetBindingForAction(action);

    if (binding.type == BindingType::Key)
    {
        return IsKeyDown(binding.key);
    }

    if (binding.type == BindingType::MouseButton)
    {
        return IsMouseButtonDown(binding.mouseButton);
    }

    return false;
}

bool Input::WasActionPressed(Action action)
{
    InputBinding binding = GetBindingForAction(action);

    if (binding.type == BindingType::Key)
    {
        return WasKeyPressed(binding.key);
    }

    if (binding.type == BindingType::MouseButton)
    {
        return WasMouseButtonPressed(binding.mouseButton);
    }

    return false;
}

bool Input::WasActionReleased(Action action)
{
    InputBinding binding = GetBindingForAction(action);

    if (binding.type == BindingType::Key)
    {
        return WasKeyReleased(binding.key);
    }

    if (binding.type == BindingType::MouseButton)
    {
        return WasMouseButtonReleased(binding.mouseButton);
    }

    return false;
}

void Input::Bind(Action action, Key key)
{
    bindings[static_cast<int>(action)] = {BindingType::Key, key, MouseButton::Left};
}

void Input::Bind(Action action, MouseButton button)
{
    bindings[static_cast<int>(action)] = {BindingType::MouseButton, Key::W, button};
}

int Input::ToGLFWKey(Key key)
{
    switch (key)
    {
    case Key::W:
        return GLFW_KEY_W;

    case Key::A:
        return GLFW_KEY_A;

    case Key::S:
        return GLFW_KEY_S;

    case Key::D:
        return GLFW_KEY_D;

    case Key::Escape:
        return GLFW_KEY_ESCAPE;
    }
    return GLFW_KEY_UNKNOWN;
}

int Input::ToGLFWMouseButton(MouseButton button)
{
    switch (button)
    {
    case MouseButton::Left:
        return GLFW_MOUSE_BUTTON_LEFT;

    case MouseButton::Right:
        return GLFW_MOUSE_BUTTON_RIGHT;
    }
    return -1;
}

InputBinding Input::GetBindingForAction(Action action)
{
    return bindings[static_cast<int>(action)];
}