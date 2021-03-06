#pragma once

#include "Level.hpp"

#include <map>
#include <string>
#include <any>
#include <vector>
#include "EngineConfig.h"

namespace se4 {
    class LevelManager {
    public:
        LevelManager() = default;

        virtual ~LevelManager() = default;

        auto loadLevel(LevelID key) -> void;
        auto deleteLevel(LevelID key) -> void;

        auto addLevel(LevelID key, std::function<std::unique_ptr<se4::Level>()>&& func) -> void;

        auto activateLevel(LevelID key) -> void;
        auto deactivateLevel(LevelID key) -> void;
        [[nodiscard]]
        auto activatedLevelId() const -> std::vector<LevelID> const &;

        std::map<LevelID, std::unique_ptr<se4::Level>> levelList;
        std::map<std::string, std::any> sharedData;
        std::map<LevelID, std::function<std::unique_ptr<se4::Level>()>> funcList;

    private:
        std::vector<LevelID> activatedId;
    };
}	