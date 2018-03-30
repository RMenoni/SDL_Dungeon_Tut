#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <map>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID get_component_type_id() {
	static ComponentID last_id = 0;
	return last_id++;
}

template <typename T>
inline ComponentID get_component_type_id() noexcept {
	static_assert(std::is_base_of<Component, T>::value, "");
	static ComponentID type_id = get_component_type_id();
	return type_id;
}

constexpr std::size_t max_components = 32;

using ComponentBitSet = std::bitset<max_components>;
using ComponentMap = std::map<ComponentID, std::shared_ptr<Component>>;

class Component {

public:
	Entity *entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	Component() {}
	virtual ~Component() {}

};

class Entity {

private:
	bool active = true;
	ComponentBitSet component_bitset;
	ComponentMap component_map;

public:
	~Entity() {}

	void update() {
		for (auto&[k, v] : component_map) { v->update(); (void)k; }
	}
	void draw() {
		for (auto&[k, v] : component_map) { v->draw(); (void)k; }
	}
	bool is_active() const { return active; }
	void destroy() { active = false; }

	template <typename T>
	bool has_component() const {
		return component_bitset[get_component_type_id<T>()];
	}

	template <typename T, typename... TArgs>
	T& add_component(TArgs&&... m_args) {
		const ComponentID id = get_component_type_id<T>();
		auto new_component = std::make_unique<T>(std::forward<TArgs>(m_args)...);
		std::cout << "this == " << this << std::endl;
		new_component->entity = this;
		std::cout << "new component entity == " << new_component->entity << std::endl;
		component_map[id] = std::move(new_component);
		component_bitset[id] = true;

		component_map[id]->init();
		return get_component<T>();
	}

	template <typename T>
	T& get_component() const {
		auto &component = component_map.at(get_component_type_id<T>());
		T *t_ptr = static_cast<T*>(component.get());
		if (t_ptr == NULL) {
			std::cout << "COULD NOT DYNAMIC CAST" << std::endl;
		}
		return *t_ptr;
	}

};

class Manager {

private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	Manager() {}
	~Manager() {}
	void update() {
		for (auto &e : entities) e->update();
	}
	void draw() {
		for (auto &e : entities) e->draw();
	}
	void refresh() {
		entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](auto &e) { return !e->is_active(); }), std::end(entities));
	}
	Entity& add_entity() {
		auto new_entity = std::make_unique<Entity>();
		entities.emplace_back(std::move(new_entity));
		return *entities.at(entities.size() - 1);
	}
};












