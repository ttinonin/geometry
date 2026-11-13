#pragma once

#include <components/Components.h>
#include <string>
#include <utility>

class Entity {
private:
	ComponentTuple m_Components;
	bool m_Alive = true;
	std::string m_Tag = "default";
	size_t m_Id = 0;
public:
	Entity() {}
	Entity(const std::string& tag, const size_t& id) : m_Tag(tag), m_Id(id) {}

	template <typename T, typename... TArgs>
	T& Add(TArgs&&... args) {
		auto& component = std::get<T>(m_Components);

		component = T(std::forward<TArgs>(args)...);
		component.Exists = true;

		return component;
	}

	template <typename T>
	T& Get() {
		return std::get<T>(m_Components);
	}

	template <typename T>
	bool Has() const {
		return std::get<T>(m_Components).Exists;
	}

	template <typename T>
	void Remove() {
		auto& component = std::get<T>(m_Components);
		component = T{};
		component.Exists = false;
	}
	
	size_t GetId() const { return m_Id; };
	bool IsAlive() const { return m_Alive; };
	void Destroy() { m_Alive = false; };
	const std::string& GetTag() const { return m_Tag; };
	virtual void Draw() = 0;
};