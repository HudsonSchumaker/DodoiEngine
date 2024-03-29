/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Tag.h"
#include "../include/Common.h"
#include "../ecs/component/Component.h"

class Entity {
private:
	std::unordered_map<const std::type_info*, Component*> components;

public:
	unsigned long id = 0;
	Tag tag = Tag::standard;

	template<typename T>
	T* getComponent() {
		auto it = components.find(&typeid(T));
		if (it != components.end()) {
			return (T*)(it->second);
		}
		return nullptr;
	}

	template<typename T>
	T* addComponent(T* component) {
		components[&typeid(T)] = component;
		component->parentId = id;
		return component;
	}

	template<typename T>
	void removeComponent() {
		auto it = components.find(&typeid(T));
		if (it != components.end()) {
			delete it->second;
			components.erase(it);
		}
	}
};
