#include "entity.h"
#include "mesh.h"
#include "material.h"
#include "transform.h"

Entity::Entity(
    std::unique_ptr<Mesh> mesh,
    std::unique_ptr<Material> material)
    : mesh(std::move(mesh)), material(std::move(material)), transform(std::make_unique<Transform>())
{
}

Entity::~Entity() = default;

Mesh &Entity::GetMesh()
{
    return *mesh;
}

Material &Entity::GetMaterial()
{
    return *material;
}

Transform &Entity::GetTransform()
{
    return *transform;
}