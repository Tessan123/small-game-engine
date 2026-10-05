#pragma once

#include <memory>

class Mesh;
class Material;
class Transform;

class Entity
{
public:
    Entity(std::unique_ptr<Mesh> mesh, std::unique_ptr<Material> material);
    ~Entity();

    Mesh &GetMesh();
    Material &GetMaterial();
    Transform &GetTransform();

private:
    std::unique_ptr<Mesh> mesh;
    std::unique_ptr<Material> material;
    std::unique_ptr<Transform> transform;
};