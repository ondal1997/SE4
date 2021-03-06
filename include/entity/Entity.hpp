#pragma once

namespace se4 {
	class Level;
	struct Entity {
		int id;

		// To put it in maps
		friend bool operator<(const Entity& l, const Entity& r) { return l.id < r.id; }
        friend bool operator==(const Entity& l, const Entity& r) { return l.id == r.id; }
	};
}  // namespace se4

