#pragma once

#include <bitset>
#include <vector>
#include <functional>
#include "component/ComponentMask.hpp"
#include "entity/Entity.hpp"

namespace se4 {
    class Level;

    class Updater {
    public:
        Updater() = default;

        virtual ~Updater() = default;

        Updater(const Updater &) = default;

        Updater &operator=(const Updater &) = default;

        Updater(Updater &&) = default;

        Updater &operator=(Updater &&) = default;

        /*
         * Called before the game starts but after the world initializes
         */
        virtual bool init() { return true; };

        /*
         * Called every game update
         */
        virtual void update(int dt) {};

        /*
         * When a Updater is added to the world, the world will register itself
         */
        void registerWorld(Level *world);

        /*
         * When a component is added such that this Updater should begin acting on it,
         * register will be called.
         */
        void registerEntity(Entity const &entity);

        /*
         * If a component is removed from an entity such that the Updater should stop
         * acting on it, unRegister will be called.
         */
        void unRegisterEntity(Entity const &entity);

        ComponentMask& getSignature();

    protected:
        std::vector<Entity> registeredEntities;
        Level *parentWorld;
        ComponentMask signature;
    };
}
