#include "Game.h"

#include "Globals/Time.h"
#include "Input/Input.h"
#include "Sprite/Sprite.h"

Game::Game(int windowWidth, int windowHeight) : Engine(windowWidth, windowHeight)
{
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    init();
}

Game::~Game()
{
    exit();
}

void Game::init()
{
    const char* playerPath = "../res/images/Sonic_Mania_Sprite_Sheet.png";
    const char* backgroundPath = "../res/images/parcialBackground.jpg";
    const char* filePath = "../res/images/pikachu.png";

    player2 = new Sprite(getRenderer(), { 1, 1, 1, 1 }, { 400, 400, 0.0f }, { 100, 100, 0 },
        filePath, GL_NEAREST);
    Animation idelAnimation = Animation(136, 349, 3, 1.2f, 847, 396, 39, 47);
    Animation runAnimation = Animation(536, 302, 4, 1.2f, 847, 396, 47, 39);
    Animator.insert_or_assign("IDEL", idelAnimation);
    Animator.insert_or_assign("RUN", runAnimation);

    UI1 = new Sprite(getRenderer(), { 1, 1, 1, 1 }, { (float)windowWidth - 133, 25, 0.0f }, { 266, 52, 0 },
        filePath, GL_NEAREST);
    Animation UI1Animation = Animation(580, 96, 1, 1, 847, 396, 266, 40);
    Animator.insert_or_assign("UI1", UI1Animation);

    UI2 = new Sprite(getRenderer(), { 1, 1, 1, 1 }, { 0 + 190 / 2,(float) windowHeight - 65, 0.0f }, { 191, 160, 0 },
        filePath, GL_NEAREST);
    Animation UI2Animation = Animation(350, 0, 1, 1, 847, 396, 191, 155);
    Animator.insert_or_assign("UI2", UI2Animation);

    player1 = new Sprite(getRenderer(), {1, 1, 1, 1}, {0, 0, 0.0f}, {100, 100, 0},
                         playerPath,GL_NEAREST);
    cartel = new Sprite(getRenderer(), {1, 1, 1, 1}, {windowWidth / 2.0f, windowHeight / 2.0f, 0.0f}, {100, 100, 0},
                        playerPath,GL_NEAREST);
    fondo = new Sprite(getRenderer(), {1, 1, 1, 1}, {windowWidth / 2.0f, windowHeight / 2.0f, 0.0f}, {700, 500, 0},
                       backgroundPath,GL_NEAREST);
    
    Animation animationPlayerRight = Animation(19, 205, 3, 0.5f, 830, 465, 40, 33);
    Animation animationPlayerIdle = Animation(390, 98, 3, 1.2f, 830, 465, 33, 40);
    Animation animationCartel = Animation(132, 94, 5, 0.5f, 830, 465, 49, 48);

    Animator.insert_or_assign("Right", animationPlayerRight);
    Animator.insert_or_assign("Idle", animationPlayerIdle);
    Animator.insert_or_assign("cartel", animationCartel);
    cartel->ChangeAnimation(Animator["cartel"]);
    UI1->ChangeAnimation(Animator["UI1"]);
    UI2->ChangeAnimation(Animator["UI2"]);


// animationCartel.deleteAnimation();
// animationPlayerRight.deleteAnimation();
// animationCartel.deleteAnimation();
    //delete playerPath;
    //delete backgroundPath;
}

void Game::update()
{
    Vec3 newPos = {player1->GetPosition().x, player1->GetPosition().y, player1->GetPosition().z};
    Vec3 scale = {player1->GetScale().x, player1->GetScale().y, player1->GetScale().z};

    Vec3 newPos2 = { player2->GetPosition().x, player2->GetPosition().y, player2->GetPosition().z };
    Vec3 scale2 = { player2->GetScale().x, player2->GetScale().y, player2->GetScale().z };
 

    bool hasBeenPressed = false;
    if (input->isKeyPressed(KeyKode::KEY_A))
    {
        newPos.x -= 1.0f * 2.0f;
        player1->SetPosition(newPos);

        player1->ChangeAnimation(Animator["Right"]);
        std::cout << player1->GetScale().z << endl;
        if (player1->GetScale().x > 0)
        {
            player1->SetScale({player1->GetScale().x*-1, player1->GetScale().y, player1->GetScale().z });
        }
        hasBeenPressed = true;
        if (Colitions::CheckCollitions(cartel, player1))
        {
            cout << "Collision" << endl;
        }
        if (Colitions::CheckCollitions(player1, player2))
        {
            cout << "Collision" << endl;
        }
    }
    if (input->isKeyPressed(KeyKode::KEY_W))
    {
        newPos.y += 1.0f* 2.0f;
        player1->SetPosition(newPos);
        player1->ChangeAnimation(Animator["Right"]);
        hasBeenPressed = true;
        if (Colitions::CheckCollitions(cartel, player1))
        {
            cout << "Collision" << endl;
        }
        if (Colitions::CheckCollitions(player1, player2))
        {
            cout << "Collision" << endl;
        }
    }
    if (input->isKeyPressed(KeyKode::KEY_S))
    {
        newPos.y -= 1.0f*  2.0f;
        player1->SetPosition(newPos);
        player1->ChangeAnimation(Animator["Right"]);
        hasBeenPressed = true;
        if (Colitions::CheckCollitions(cartel, player1))
        {
            cout << "Collision" << endl;
        }
        if (Colitions::CheckCollitions(player1, player2))
        {
            cout << "Collision" << endl;
        }
    }
    if (input->isKeyPressed(KeyKode::KEY_D))
    {
        newPos.x += 1.0f * 2;
        player1->SetPosition(newPos);
        player1->ChangeAnimation(Animator["Right"]);
        hasBeenPressed = true;
        
        if (player1->GetScale().x < 0)
        {
            player1->SetScale({player1->GetScale().x *-1, player1->GetScale().y, player1->GetScale().z});
        }
        if (Colitions::CheckCollitions(cartel, player1))
        {
            cout << "Collision" << endl;
        }
        if (Colitions::CheckCollitions(player1, player2))
        {
            cout << "Collision" << endl;
        }
    }

    if (input->isKeyPressed(KeyKode::KEY_LEFT))
    {
        newPos2.x -= 1.0f * 2.0f;
        player2->SetPosition(newPos2);

        player2->ChangeAnimation(Animator["RUN"]);
        std::cout << player2->GetScale().z << endl;
        if (player2->GetScale().x > 0)
        {
            player2->SetScale({ player2->GetScale().x * -1, player2->GetScale().y, player2->GetScale().z });
        }
        hasBeenPressed = true;
        if (Colitions::CheckCollitions(cartel, player2))
        {
            cout << "Collision" << endl;
        }
        if (Colitions::CheckCollitions(player1, player2))
        {
            cout << "Collision" << endl;
        }
    }
    if (input->isKeyPressed(KeyKode::KEY_UP))
    {
        newPos2.y += 1.0f * 2.0f;
        player2->SetPosition(newPos2);

        player2->ChangeAnimation(Animator["RUN"]);
        std::cout << player2->GetScale().z << endl;
        if (player2->GetScale().x > 0)
        {
            player2->SetScale({ player2->GetScale().x * -1, player2->GetScale().y, player2->GetScale().z });
        }
        hasBeenPressed = true;
        if (Colitions::CheckCollitions(cartel, player2))
        {
            cout << "Collision" << endl;
        }
        if (Colitions::CheckCollitions(player1, player2))
        {
            cout << "Collision" << endl;
        }
    }
    if (input->isKeyPressed(KeyKode::KEY_DOWN))
    {
        newPos2.y -= 1.0f * 2.0f;
        player2->SetPosition(newPos2);
        player2->ChangeAnimation(Animator["RUN"]);
        hasBeenPressed = true;
        if (Colitions::CheckCollitions(cartel, player2))
        {
            cout << "Collision" << endl;
        }
        if (Colitions::CheckCollitions(player1, player2))
        {
            cout << "Collision" << endl;
        }
    }
    if (input->isKeyPressed(KeyKode::KEY_RIGHT))
    {
        newPos2.x += 1.0f * 2;
        player2->SetPosition(newPos2);
        player2->ChangeAnimation(Animator["RUN"]);
        hasBeenPressed = true;

        if (player2->GetScale().x < 0)
        {
            player2->SetScale({ player2->GetScale().x * -1, player2->GetScale().y, player2->GetScale().z });
        }
        if (Colitions::CheckCollitions(cartel, player2))
        {
            cout << "Collision" << endl;
        }
        if (Colitions::CheckCollitions(player1, player2))
        {
            cout << "Collision" << endl;
        }
    }

    if (!hasBeenPressed)
    {
        //player1->ChangeAnimation(Animator["Idle"]);
        player2->ChangeAnimation(Animator["IDEL"]);
    }


    
    if (Colitions::CheckCollitions(player1, cartel))
    {
        cout << "Collision" << endl;
    }

    if (Colitions::CheckCollitions(player1, player2))
    {
        cout << "Collision" << endl;
    }

    fondo->Draw();
    player1->UpdateAnimation();
    player1->Draw();
    player2->UpdateAnimation();
    player2->Draw();
    UI1->Draw();
    UI1->UpdateAnimation();
    UI2->Draw();
    UI2->UpdateAnimation();
    cartel->UpdateAnimation();
    cartel->Draw();
}

void Game::exit()
{
    //Animator["Right"].deleteAnimation();
    //Animator["cartel"].deleteAnimation();
    //Animator["Idle"].deleteAnimation();
    
    delete player1;
    delete player2;
    delete UI1;
    delete UI2;
    delete obj1;
    delete obj2;
    delete fondo;
    delete cartel;
    
}
