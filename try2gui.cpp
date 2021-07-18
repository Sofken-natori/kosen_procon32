# include <Siv3D.hpp>

void Main()
{
    Scene::SetBackground(ColorF(0.8, 0.9, 1.0));

    const Texture textureWindmill(U"example/windmill.png");

    while (System::Update())
    {
        // 画像の (0, 0) から幅 200, 高さ 200 の長方形部分
        textureWindmill(0, 0, 200, 200).draw(35, 20);    
        textureWindmill(0, 200, 200, 200).draw(35, 225);   
        textureWindmill(200, 0, 200, 200).draw(240, 20);
        textureWindmill(200, 200, 200, 200).draw(240, 225);
    }
}
