#pragma once

#include "vec2.h"
#include "texture.h"

class Sprite
{
public:
    Sprite(Texture *texture);

    void SetPosition(const Vec2 &position);
    void SetSize(const Vec2 &size);
    void SetRotation(float rotation);

    const Vec2 &GetPosition() const;
    const Vec2 &GetSize() const;
    float GetRotation() const;

    Texture *GetTexture() const;

private:
    Texture *texture;
    Vec2 position;
    Vec2 size;
    float rotation;
};