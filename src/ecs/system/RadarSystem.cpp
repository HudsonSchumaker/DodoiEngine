/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "RadarSystem.h"
#include "../EntityManager.h"
#include "../component/Radar.h"
#include "../../physics/DMath.h"
#include "../../event/EventBus.h"
#include "../component/Callback.h"
#include "../component/Transform.h"
#include "../../event/CollisionEvent.h"

void RadarSystem::update() {
    auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Radar>();

    for (auto& entity : entities) {
        Radar* radar = entity->getComponent<Radar>();
        Transform* transform = entity->getComponent<Transform>();

        if (radar && transform) {
            float radarX = transform->position.x + radar->offset.x;
            float radarY = transform->position.y + radar->offset.y;
            float radarRadius = radar->r;

            auto enemies = EntityManager::getInstance()->getEntitiesWithTag(radar->tag);
            for (auto& enemy : enemies) {
                if(enemy->tag == radar->tag) {
                    Transform* enemyTransform = enemy->getComponent<Transform>();

                    // Calculate the distance between the radar and the other entity
                    float dx = enemyTransform->position.x - radarX;
                    float dy = enemyTransform->position.y - radarY;
                    float distance = DMath::rootf(dx * dx + dy * dy);

                    // Check if the other entity is within the radar area
                    if (distance <= radarRadius) {
                        Callback* callback = entity->getComponent<Callback>();
                        callback->call(entity->id, enemy->id);

                        //TODO: this for test
                    // EventBus::getInstance()->emitEvent<CollisionEvent>(entity, enemy);
                    }
                }
            }
        }    
    }
}
