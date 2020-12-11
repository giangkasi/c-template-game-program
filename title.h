#pragma once
class Scene;
class TitleScene : public Scene {
public:
    TitleScene();
    virtual ~TitleScene();

    virtual Scene* Update() override;
    virtual void Draw() const override;



private:

};