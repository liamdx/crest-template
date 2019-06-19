#include "components/lighting/PointLightComponent.h"
#include "Entity.h"

PointLightComponent::PointLightComponent(glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float intensity, float distance)
{
	this->position = position;
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->intensity = intensity;
	this->distance = distance;
}

PointLightComponent::PointLightComponent()
{
	this->position = glm::vec3(0.0f);
	this->ambient = glm::vec3(0.0f);
	this->diffuse = glm::vec3(0.0f);
	this->specular = glm::vec3(0.0f);
	this->intensity = 0.0f;
	this->distance = 1.0f;
}

void PointLightComponent::intitalize(glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float intensity, float distance)
{
	this->position = position;
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->intensity = intensity;
	this->distance = distance;
}

void PointLightComponent::Bind(std::shared_ptr<ShaderComponent> shader, unsigned int index)
{
	std::stringstream ss;
	ss << "pointLights[" << index << "].";
	std::string s = ss.str();

	shader->shader->setVec3(s + "position", position);
	shader->shader->setVec3(s + "ambient", ambient);
	shader->shader->setVec3(s + "diffuse", diffuse);
	shader->shader->setVec3(s + "specular", specular);
	shader->shader->setFloat(s + "intensity", intensity);
	shader->shader->setFloat(s + "distance", distance);
}

void PointLightComponent::Bind(std::shared_ptr<ShaderComponent> shader)
{
	std::stringstream ss;
	ss << "debugLight.";
	std::string s = ss.str();

	shader->shader->setVec3(s + "position", position);
	shader->shader->setVec3(s + "ambient", ambient);
	shader->shader->setVec3(s + "diffuse", diffuse);
	shader->shader->setVec3(s + "specular", specular);
	shader->shader->setFloat(s + "intensity", intensity);
	shader->shader->setFloat(s + "distance", distance);

}

void PointLightComponent::update(float deltaTime)
{
	this->position = attachedEntity->transform->position;
}
