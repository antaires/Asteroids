#include "VertexArray.h"

VertexArray::VertexArray(const float* verts, unsigned int numVerts, const unsigned int* indices, unsigned int numIndices)
  :m_NumVerts(numVerts)
  , m_NumIndices(numIndices)
{}

VertexArray::~VertexArray()
{}

void VertexArray::SetActive()
{}

unsigned int VertexArray::GetNumIndices() const
{
  return m_NumIndices;
}

unsigned int VertexArray::GetNumVertices() const
{
  return m_NumVerts;
}
