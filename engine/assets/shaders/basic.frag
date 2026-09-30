#version 330 core

in vec2 v_TexCoord;
in vec3 v_Normal;
in vec3 v_WorldPosition;

out vec4 color;

uniform sampler2D u_Texture;

uniform vec3 u_LightDirection;
uniform vec3 u_LightColor;
uniform float u_LightIntensity;
uniform float u_SpecularIntensity;

uniform vec3 u_CameraPosition;

void main()
{
    vec4 textureColor = texture(u_Texture, v_TexCoord);

    // Normal
    vec3 normal = normalize(v_Normal);

    // Diffuse lighting
    vec3 lightDirection =
        normalize(-u_LightDirection);

    float brightness =
        max(dot(normal, lightDirection), 0.0);

    // Ambient lighting
    float ambient = 0.2;

    // Direction from pixel to camera
    vec3 viewDirection =
        normalize(u_CameraPosition - v_WorldPosition);

    // Reflection of the light
    vec3 reflectionDirection =
        reflect(-lightDirection, normal);

    // Specular lighting
    float specular =
    pow(
        max(dot(viewDirection, reflectionDirection), 0.0),
        32.0
    ) * u_SpecularIntensity;

    // Combine lighting
    vec3 lighting = vec3(ambient) + vec3(brightness * u_LightIntensity) + vec3(specular);

    color =
        textureColor *
        vec4(lighting * u_LightColor, 1.0);
}