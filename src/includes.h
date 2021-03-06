//Forward declarations and super-useful classes.
 
#ifndef INCLUDES_H_
#define INCLUDES_H_

#include "libwittek.h"
#include <string>
#include <memory>


// forward declarations
class CApp;
class Tile;
class Label;
class GameObject;
class CompositeGameObject;
class Sprite;

class SDL_Window;
class SDL_Renderer;
class SDL_Texture;
class SDL_Surface;
class SDL_Rect;
class _TTF_Font;

typedef std::shared_ptr< SDL_Texture > TextureShared;
typedef std::weak_ptr< SDL_Texture > TextureWeak;

typedef std::shared_ptr< Tile > TileShared;
typedef std::weak_ptr< Tile > TileWeak;

// Gotta use _TTF_Font because TTF_Font is actually a typedef!
typedef std::shared_ptr< _TTF_Font > FontShared;
typedef std::weak_ptr< _TTF_Font > FontWeak;

// GameObjects
typedef std::shared_ptr< GameObject > GameObjectShared;
typedef std::weak_ptr< GameObject > GameObjectWeak;

typedef std::shared_ptr< Label > LabelShared;
typedef std::weak_ptr< Label > LabelWeak;

typedef std::shared_ptr< Sprite > SpriteShared;
typedef std::weak_ptr< Sprite > SpriteWeak;

typedef std::shared_ptr< CompositeGameObject > 
  CompositeGameObjectShared;
typedef std::weak_ptr< CompositeGameObject > 
  CompositeGameObjectWeak;


#endif
