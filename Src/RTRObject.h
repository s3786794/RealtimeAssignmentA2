//-----------------------------------------------------------------------------
// RTRObject.h
//-----------------------------------------------------------------------------
// RMIT University, COSC1226: Real-Time Rendering and 3D Game Programming
//-----------------------------------------------------------------------------
#pragma once
#include "RTRLighting.h"
#include "RTRShader.h"
#include "RTRBoundingVolume.h"
#include "stb/stb_image.h"
#include <vector>

struct RTRPoint_t5 {
    float x, y, z, tex1, tex2;
};

struct RTRPoint_t3 {
    float x, y, z;
};

struct RTRFace_t {
    unsigned int v0, v1, v2;
};

//-----------------------------------------------------------------------------
class RTRObject
{
public:
    RTRObject(glm::vec3 translation, glm::vec3 scale, glm::vec3 rotation, glm::mat4 modelMatrix, float angle) {
        m_Translation = translation;
        m_Scale = scale;
        m_Rotation = rotation;
        m_TransformMatrix = modelMatrix;
        m_Angle = angle;
    }
    ~RTRObject() {}
    virtual void Init(std::string textureName, std::string textureName2);
    virtual void Render(RTRShader* shader);
    virtual void End();
    void SetMaterial(RTRMaterial_t mat) { m_Material = mat; }
    virtual const char* GetName() { return "RTRObject"; }
    virtual void SetPosition(glm::vec3 position) { m_Position = position; };
    virtual glm::vec3 GetPosition() { return m_Position; };
    virtual void SetTransformMatrix(glm::mat4 transformMatrix) { m_TransformMatrix = transformMatrix; };
    virtual glm::mat4 GetTransformMatrix() { return m_TransformMatrix; };
    virtual void SetTranslation(glm::vec3 translation) { m_Translation = translation; };
    virtual glm::vec3 GetTranslation() { return m_Translation; };
    virtual void SetScale(glm::vec3 scale) { m_Scale = scale; };
    virtual glm::vec3 GetScale() { return m_Scale; };
    virtual void SetRotation(glm::vec3 rotation) { m_Rotation = rotation; };
    virtual glm::vec3 GetRotation() { return m_Rotation; };
    virtual unsigned int LoadTexture(std::string textureFile);
    virtual void SetAngle(float angle) { m_Angle = angle; };
    virtual float GetAngle() { return m_Angle; };

public:
    unsigned int m_NumVertices{ 0 };
    unsigned int m_NumFaces{ 0 };
    RTRPoint_t5* m_VertexPoints{ nullptr };
    RTRFace_t* m_Faces{ nullptr };
    RTRMaterial_t m_Material{ {0.19225, 0.19225, 0.19225 }, { 0.50754, 0.50754, 0.50754 }, { 0.508273, 0.508273, 0.508273 }, 128.0 };
    unsigned int m_VertexBuffer{ 0 };
    unsigned int m_VertexArray{ 0 };
    unsigned int m_FaceElementBuffer{ 0 };
    glm::mat4 m_TransformMatrix{ 0 };
    glm::vec3 m_Position{ 0 };
    glm::vec3 m_Translation{ 0 };
    glm::vec3 m_Scale{ 0 };
    glm::vec3 m_Rotation{ 0 };
    float m_Angle{ 0 };
    unsigned int texture{ 0 };
    unsigned int texture2{ 0 };
};

//-----------------------------------------------------------------------------
class RTRCube : public RTRObject
{
public:
    RTRCube(glm::vec3 translation, glm::vec3 scale, glm::vec3 rotation, glm::mat4 modelMatrix, float angle) :
        RTRObject(translation, scale, rotation, modelMatrix, angle) {}
    ~RTRCube() {}
    virtual void Init(std::string textureName, std::string textureName2);
    virtual const char* GetName() { return "RTRCube"; }
};

class RTRSphere : public RTRObject {
public:
    RTRSphere(glm::vec3 translation, glm::vec3 scale, glm::vec3 rotation, glm::mat4 modelMatrix, float angle) :
        RTRObject(translation, scale, rotation, modelMatrix, angle) {}
    ~RTRSphere() {}
    virtual void Init(std::string textureName);
    virtual void Render(RTRShader* shader);
    virtual const char* GetName() { return "RTRSphere"; }
    virtual void InitSphere(std::vector<RTRPoint_t5> vertices, std::vector<int> indices);
    virtual std::vector<RTRPoint_t5> MakeSphereVertices(float radius, int stacks, int slices);
    virtual std::vector<int> MakeSphereIndex(int stacks, int slices);
    virtual void SetVelocity(glm::vec3 velocity) { m_Velocity = velocity; };
    virtual glm::vec3 GetVelocity() { return m_Velocity; };
    virtual void SetPower(float power) { m_Power = power; };
    virtual float GetPower() { return m_Power; };
    virtual void SetMovingForward(bool move) { m_MovingForward = move; };
    virtual bool GetMovingForward() { return m_MovingForward; };

private:
    glm::vec3 m_Velocity{ 0 };
    float m_Power{ 0 };
    bool m_MovingForward{ true };
};

class RTRCylinder : public RTRObject {
public:
    RTRCylinder(glm::vec3 translation, glm::vec3 scale, glm::vec3 rotation, glm::mat4 modelMatrix, float angle) :
        RTRObject(translation, scale, rotation, modelMatrix, angle) {}
    ~RTRCylinder() {}
    virtual void Init(std::string textureName, std::string textureName2);
    virtual const char* GetName() { return "RTRCylinder"; }
};

class RTRPrism : public RTRObject {
public:
    RTRPrism(glm::vec3 translation, glm::vec3 scale, glm::vec3 rotation, glm::mat4 modelMatrix, float angle) :
        RTRObject(translation, scale, rotation, modelMatrix, angle) {}
    ~RTRPrism() {}
    virtual void Init(std::string textureName, std::string textureName2);
    virtual const char* GetName() { return "RTRPrism"; }
};

class RTRGrid : public RTRObject
{
public:
    RTRGrid(glm::vec3 translation, glm::vec3 scale, glm::vec3 rotation, glm::mat4 modelMatrix, float angle) :
        RTRObject(translation, scale, rotation, modelMatrix, angle) {}
    virtual void Init();
    virtual void InitGrid();
    virtual void Render(RTRShader* shader);
    virtual void End();
    virtual const char* GetName() { return "RTRGrid"; }

private:
    std::vector<glm::vec3> VerticesPoints;
    std::vector<glm::vec2> IndicesPoints;
    int m_Length{ 0 };
    RTRPoint_t3* m_VertexPoints3{ nullptr };
};