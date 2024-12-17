#include "ResourceManager.h"

std::unordered_map<std::filesystem::path, std::shared_ptr<sf::Texture>> ResourceManager::mTextures = {};

ResourceManager::~ResourceManager()
{
}

std::shared_ptr<sf::Texture> ResourceManager::GetTexture(const std::filesystem::path& file)
{
	std::unordered_map<std::filesystem::path, std::shared_ptr<sf::Texture>>::iterator it = ResourceManager::mTextures.find(file);
	if (it != ResourceManager::mTextures.end())
	{
		return (*it).second;
	}

	std::shared_ptr<sf::Texture> newTexture = std::make_shared<sf::Texture>();
	if (newTexture->loadFromFile(file))
	{
		newTexture->setSmooth(true);
		ResourceManager::mTextures.emplace(file, newTexture);
		return newTexture;
	}

	return nullptr;
}
