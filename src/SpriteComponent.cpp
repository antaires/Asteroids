#include "SpriteComponent.h"
#include "Actor.h"
#include "Game.h"
#include "Shader.h"

#include <GL/glew.h>

SpriteComponent::SpriteComponent(class Actor* owner, int drawOrder)
  : Component(owner)
  , m_Texture(nullptr)
  , m_DrawOrder(drawOrder)
  , m_TextureWidth(50) // TODO need to get this from texture !
  , m_TextureHeight(50)
  {
    m_Owner->GetGame()->AddSprite(this);
  }

SpriteComponent::~SpriteComponent()
{
  m_Owner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(Shader* shader)
{
  // scale the quad by the width/height of texture
  Matrix4 scaleMat = Matrix4::CreateScale(
    static_cast<float>(m_TextureWidth) // set width / height from texture ! 
    , static_cast<float>(m_TextureHeight)
    , 1.0f
  );
  Matrix4 world = scaleMat * m_Owner->GetWorldTransform();

  // set world transform
  shader->SetMatrixUniform("uWorldTransform", world);

  // draw quad
  glDrawElements(
    GL_TRIANGLES
    , 6                 // number of indices in index buffer
    , GL_UNSIGNED_INT   // type of each index
    , nullptr
  );
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
  m_Texture = texture;
  SDL_QueryTexture(texture, nullptr, nullptr, &m_TextureWidth, &m_TextureHeight);
}

int SpriteComponent::GetDrawOrder() const {return m_DrawOrder;}
int SpriteComponent::GetTextureHeight() const {return m_TextureHeight;}
int SpriteComponent::GetTextureWidth() const {return m_TextureWidth;}
