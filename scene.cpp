#include "scene.h"


#define TITLE_IMAGE  ",\\image/titleimage.png" 

void SceneManager::ChangeScene(SCENE scene) {

    if (m_pScene != nullptr) {
        delete m_pScene;
    }

    switch (scene) {
    case SCENE::TITLE:
        m_pScene = new TitleScene();
        break;
    case SCENE::GAME:
        m_pScene = new GameScene();
        break;
    case SCENE::RESULT:
        m_pScene = new ResultScene();
        break;
    default:
        break;
    }

}

void SceneManager::Update() {
    m_pScene->Update();         //���݂̃V�[���̍X�V�֐�
}

void SceneManager::Render() {
    m_pScene->Draw();           //���݂̃V�[���̕`��֐�
}

void TitleScene::Draw() {

}