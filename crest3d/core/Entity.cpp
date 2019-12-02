#include "Entity.h"
#include "EngineManager.h"
#include "Example.h"

Entity::Entity(const char* entityName, EngineManager* _em, std::shared_ptr<Entity> e)
{
	engineManager = _em;
	name = entityName;
	transform = std::shared_ptr<TransformComponent>(new TransformComponent());
	parent = e;
	if(parent != nullptr)
	{
		transform->setParent(parent->transform);
	}
	else
	{
		transform->setParent(nullptr);
	}
	
}

void Entity::ConsoleError(std::string error)
{

}


void Entity::AddComponent(EngineComponent* newComponent)
{
	bool canEmplace = true;
	for (unsigned int i = 0; i < components.size(); i++)
	{
		if (components[i]->name == newComponent->name)
		{
			canEmplace = false;
		}
	}
	if (canEmplace)
	{
		newComponent->SetId(engineManager->makeUniqueComponentID());
		newComponent->init();
		newComponent->start();
		components.emplace_back(newComponent);
		std::string message;
		message = "ID: " + std::to_string(id) + " successfully added a " + typeid(*newComponent).name() + "\n";
		Debug::Log<Entity>(message.c_str());
	}
	else
	{
		std::string message;
		message = "ID: " + std::to_string(id) + " could not add a " + typeid(*newComponent).name() + " to the Entity\n";
		Debug::Warn<Entity>(message.c_str());
		delete newComponent;
	}
}

void Entity::AddComponent(std::shared_ptr<EngineComponent> newComponent)
{
	bool canEmplace = true;
	for (unsigned int i = 0; i < components.size(); i++)
	{
		if (components[i]->name == newComponent->name)
		{
			canEmplace = false;
		}
	}
	if (canEmplace)
	{
		newComponent->SetId(engineManager->makeUniqueComponentID());
		newComponent->init();
		newComponent->start();
		components.emplace_back(newComponent);
		std::string message;
		message = "ID: " + std::to_string(id) + " successfully added a " + typeid(*newComponent).name() + "\n";
		Debug::Log<Entity>(message.c_str());
	}
	else
	{
		std::string message;
		message = "ID: " + std::to_string(id) + " could not add a " + typeid(*newComponent).name() + " to the Entity\n";
		Debug::Warn<Entity>(message.c_str());
		
	}
}

void Entity::initBehaviour()
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components.at(i)->init();
	}
}

void Entity::startBehaviour()
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components.at(i)->start();
	}
}

void Entity::earlyUpdateBehaviour(float deltaTime)
{
	
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components.at(i)->earlyUpdate(deltaTime);
	}
}

void Entity::fixedUpdateBehaviour()
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components.at(i)->fixedUpdate();
	}
}

void Entity::updateBehaviour(float deltaTime)
{
	transform->update(deltaTime);
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components.at(i)->update(deltaTime);
	}
}

void Entity::renderBehaviour(float deltaTime, glm::mat4 view)
{
	transform->render(deltaTime, view);
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components.at(i)->render(deltaTime, view);
	}
}

void Entity::uiBehaviour(float deltaTime)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components.at(i)->ui(deltaTime);
	}
}

void Entity::AddChild(std::shared_ptr<Entity> e)
{
	children.emplace_back(e);
	std::string message;
	message = "ID: " + std::to_string(id) + " added child with ID: " + std::to_string(e->GetID()) + "\n";
	Debug::Log<Entity>(message.c_str());
}


std::shared_ptr<Entity> Entity::GetChild(unsigned int index)
{
	if (index <= (children.size() - 1))
	{
		return(std::shared_ptr<Entity>(children.at(index)));
	}

	std::string message;
	message = "ID: " + std::to_string(id) + " could not find child at index: " + std::to_string(index) + "\n";
	Debug::Warn<Entity>(message.c_str());
	return nullptr;
}

std::shared_ptr<Entity> Entity::GetChild(const char* name)
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		if (children.at(i)->name == name)
		{
			return(std::shared_ptr<Entity>(children.at(i)));
		}
	}

	std::string message;
	message = "ID: " + std::to_string(id) + " could not find child with name: " + name + "\n";
	Debug::Warn<Entity>(message.c_str());
	return nullptr;
}