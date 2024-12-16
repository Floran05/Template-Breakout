#include "ResourceManager.h"

std::unordered_map<std::filesystem::path, std::shared_ptr<sf::Texture>> ResourceManager::mTextures = {};
std::unordered_map<std::filesystem::path, std::shared_ptr<sf::Sprite>> ResourceManager::mSprites = {};

ResourceManager::~ResourceManager()
{
}

std::shared_ptr<sf::Sprite> ResourceManager::GetSprite(const std::filesystem::path& file)
{
	std::unordered_map<std::filesystem::path, std::shared_ptr<sf::Sprite>>::iterator it = ResourceManager::mSprites.find(file);
	if (it != ResourceManager::mSprites.end())
	{
		return (*it).second;
	}

	std::shared_ptr<sf::Texture> newTexture = std::make_shared<sf::Texture>();
	if (newTexture->loadFromFile(file))
	{
		newTexture->setSmooth(true);
		ResourceManager::mTextures.emplace(file, newTexture);
		std::shared_ptr<sf::Sprite> newSprite = std::make_shared<sf::Sprite>(*newTexture);
		ResourceManager::mSprites.emplace(file, newSprite);
		return newSprite;
	}

	return nullptr;
}
