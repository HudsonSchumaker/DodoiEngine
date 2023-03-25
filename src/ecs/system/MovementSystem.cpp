/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#include "MovementSystem.h"
#include "../EntityManager.h"
#include "../component/Transform.h"
#include "../component/RigidBody.h"

void MovementSystem::update(float dt) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<RigidBody>();

	for (auto& entity : entities) {
		RigidBody* rigidBody = entity->getComponent<RigidBody>();
		Transform* transform = entity->getComponent<Transform>();

		if (rigidBody && transform) {
			transform->position.x += rigidBody->velocity.x * dt;
			transform->position.y += rigidBody->velocity.y * dt;
		}
	}
}