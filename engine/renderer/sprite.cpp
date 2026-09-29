#include "sprite.h"

Sprite::Sprite(Texture *texture)
    : texture(texture), position(0.0f, 0.0f), size(1.0f, 1.0f), rotation(0.0f)
{
}

void Sprite::SetPosition(const Vec2 &newPosition)
{
    position = newPosition;
}

void Sprite::SetSize(const Vec2 &newSize)
{
    size = newSize;
}

void Sprite::SetRotation(float newRotation)
{
    rotation = newRotation;
}

const Vec2 &Sprite::GetPosition() const
{
    return position;
}

const Vec2 &Sprite::GetSize() const
{
    return size;
}

float Sprite::GetRotation() const
{
    return rotation;
}

Texture *Sprite::GetTexture() const
{
    return texture;
}