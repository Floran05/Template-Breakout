#pragma once

#include "Singleton.h"

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <filesystem>

class ResourceManager : public Singleton<ResourceManager>
{
	friend class Singleton<ResourceManager>;

private:

	ResourceManager() {};
	virtual ~ResourceManager();

protected:

	static std::unordered_map<std::filesystem::path, std::shared_ptr<sf::Texture>> mTextures;

public:

	static std::shared_ptr<sf::Texture> GetTexture(const std::filesystem::path& file);

};

