#pragma once
class Scene;

class SceneManager {
public:
    enum SCENE {
        TITLE,
        GAME,
        RESULT
    };

    SceneManager();
    SceneManager(const SceneManager&) = delete;
    SceneManager& operator = (const SceneManager&) = delete;
    ~SceneManager();

    static void ChangeScene(SCENE scene);
    void Update();
    void Render() const;
private:
    static Scene* m_pScene;
};

