#pragma once
#include"DxLib.h"
#include"chracter.h"

class Data;

class Scene {

protected:
    //Scene() {};
    Scene(Data* const commonData) :
        m_Data(commonData) {}


public:
    virtual Scene *Update() = 0;
    virtual void Draw() const = 0;
public :
    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;

    virtual ~Scene() = default;

protected:
    Data* const m_Data;
    template<typename T>
    Scene* makeScene();
};





























