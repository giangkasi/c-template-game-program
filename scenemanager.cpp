#include"scenemanager.h"

SceneManager::SceneManager() :
    m_pScene(TitleScene())
{}

SceneManager::~SceneManager() { delete m_pScene; }


void SceneManager::Update() {
    Scene* p = m_pScene->Update();         //���݂̃V�[���̍X�V�֐�
    if (p != m_pScene) {
        delete m_pScene;
        m_pScene = p;
    }
}

void SceneManager::Render() const {
    m_pScene->Draw();           //���݂̃V�[���̕`��֐�
}
