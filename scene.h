#pragma once

class TitleScene : public BaseScene {
public:
    void Update();  
    void Draw();      
private:
    
};

class GameScene : public BaseScene {
public:
    void Update();
    void Draw();
private:

};

class ResultScene : public BaseScene {
public:
    void Update();  
    void Draw();     
private:
   
};

class BaseScene {
public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
};

class SceneManager {
public:
    enum SCENE {
        TITLE,
        GAME,
        RESULT
    };
    static void ChangeScene(SCENE scene);
    static void Update();
    static void Render();
private:
    static BaseScene* m_pScene;
};

BaseScene* SceneManager::m_pScene = nullptr;      


















