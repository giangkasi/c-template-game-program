#include "title.h"
class Scene;

template<>
Scene* Scene::makeScene<TitleScene>() { return new TitleScene(commonData); }



void TitleScene::Draw() {




    return;
}

void TitleScene::Update() {


    return;
}