#version 330 core

in vec2 v_TexCoord;
in vec3 v_Normal;
in vec3 v_WorldPosition;

out vec4 color;

uniform sampler2D u_Texture;

uniform vec3 u_LightDirection;
uniform vec3 u_LightColor;
uniform float u_LightIntensity;
uniform float u_AmbientIntensity;
uniform vec3 u_PointLightPosition;
uniform vec3 u_PointLightColor;
uniform float u_PointLightIntensity;

uniform float u_PointLightConstant;
uniform float u_PointLightLinear;
uniform float u_PointLightQuadratic;

uniform float u_SpecularIntensity;
uniform float u_Shininess;

uniform vec3 u_Color;

uniform vec3 u_CameraPosition;


vec3 CalculateDirectionalLight(
    vec3 normal,
    vec3 viewDirection)
{
    vec3 lightDirection =
        normalize(-u_LightDirection);

    float brightness =
        max(dot(normal, lightDirection), 0.0);

    vec3 reflectionDirection =
        reflect(-lightDirection, normal);

    float specular =
        pow(
            max(dot(viewDirection, reflectionDirection), 0.0),
            u_Shininess
        ) * u_SpecularIntensity;

    return(vec3(u_AmbientIntensity) +
        vec3(brightness * u_LightIntensity) +
        vec3(specular)
    ) * u_LightColor;
}

vec3 CalculatePointLight(
    vec3 normal,
    vec3 worldPosition,
    vec3 viewDirection)
{
    vec3 toLight =
        u_PointLightPosition - worldPosition;

    float distance =
        length(toLight);

    vec3 lightDirection =
        normalize(toLight);

    float brightness =
        max(dot(normal, lightDirection), 0.0);

    vec3 reflectionDirection =
        reflect(-lightDirection, normal);

    float specular =
        pow(
            max(dot(viewDirection, reflectionDirection), 0.0),
            u_Shininess
        ) * u_SpecularIntensity;

    float attenuation =
        1.0 /
        (
            u_PointLightConstant +
            u_PointLightLinear * distance +
            u_PointLightQuadratic * distance * distance
        );

    vec3 lighting = vec3(brightness * u_PointLightIntensity) + vec3(specular);

    return lighting *
       attenuation *
       u_PointLightColor;
}

void main()
{
    vec4 textureColor =
        texture(u_Texture, v_TexCoord);

    vec3 normal =
        normalize(v_Normal);

    vec3 viewDirection =
        normalize(
            u_CameraPosition -
            v_WorldPosition
        );

    vec3 directionalLighting =
        CalculateDirectionalLight(
            normal,
            viewDirection
        );

    vec3 pointLighting =
        CalculatePointLight(
            normal,
            v_WorldPosition,
            viewDirection
        );

    vec3 lighting =
        directionalLighting +
        pointLighting;

    color =
    textureColor *
    vec4(u_Color, 1.0) *
    vec4(lighting, 1.0);
}