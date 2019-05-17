#version 440

struct Material {
	sampler2D m_Diffuse;
};

uniform Material mat;

in vec3 normal;
in vec3 fragPosition;
in vec2 vTexCoords;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main()
{
	FragColor = vec4(texture(mat.m_Diffuse, vTexCoords).rgb, 1.0);
}
