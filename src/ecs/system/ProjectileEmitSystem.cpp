/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "ProjectileEmitSystem.h"
#include "../EntityManager.h"
#include "../../gfx/Animation.h"
#include "../component/Transform.h"
#include "../component/RigidBody.h"
#include "../../core/BulletFactory.h"
#include "../component/ProjectileEmitter.h"

ProjectileEmitSystem::ProjectileEmitSystem() {
    subscribeToEvents();
}

void ProjectileEmitSystem::subscribeToEvents() {
    EventBus::getInstance()->subscribeToEvent<FireEvent>(this, &ProjectileEmitSystem::onFire);
}

void ProjectileEmitSystem::onFire(FireEvent& event) {
    auto entities = EntityManager::getInstance()->getEntitiesWithTag(event.tag);
    for (auto& entity : entities) {
        Transform* transform = entity->getComponent<Transform>();
        Animation* animation = entity->getComponent<Animation>();
        ProjectileEmiter* emiter = entity->getComponent<ProjectileEmiter>();

        if (transform && animation && emiter) {
           /*  auto bullet = BulletFactory::getInstance()->createBullet(emiter->bulletType, true);
            auto bulletTransform = bullet->getComponent<Transform>();
            if (animation->flip) {
                auto bulletRigidBody = bullet->getComponent<RigidBody>();
                bulletRigidBody->velocity.x *= -1.0f;
                bulletTransform->position.x = transform->position.x - animation->getSize().w;
            } else {
                bulletTransform->position.x = transform->position.x + animation->getSize().h;
            }

            bulletTransform->position.y = transform->position.y + (animation->getSize().h /2.0f); */
        }
    }
}
