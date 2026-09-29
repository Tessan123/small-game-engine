#version 330 core

in vec2 v_TexCoord;
in vec3 v_Normal;

out vec4 color;

uniform sampler2D u_Texture;
uniform vec3 u_LightDirection;
uniform vec3 u_LightColor;
uniform float u_LightIntensity;

void main()
{
    vec4 textureColor = texture(u_Texture, v_TexCoord);

    vec3 normal = normalize(v_Normal);

    vec3 lightDirection =
        normalize(u_LightDirection);

    float brightness =
        max(dot(normal, -lightDirection), 0.0) * u_LightIntensity;

    float ambient = 0.2;

    color = textureColor * (ambient + brightness) * vec4(u_LightColor, 1.0);
}