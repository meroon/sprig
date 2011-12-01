

#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "MathUtil.h"
#include "SprigSpriteAtlas.h"
#include "Constants.h"
#include "SprigApplication.h"

using std::string;
using std::cout;
using std::endl;



void Game::Init()
{		
    srand ( time(NULL) );
    
    
    _renderer.backgroundColor = Color(1.0, 1.0, 1.0, 1.0);
	_renderer.Setup(Screen::getInstance()->dimensions, Renderer::Orthographic);

    
    string imagePath = Application::getInstance()->getBasePath() + "/run_test.png"; 
    string xmlPath = Application::getInstance()->getBasePath() + "/run_test.xml";
    
    
    _sprite.setPosition(60, 300);
    _sprite.LoadSheet(xmlPath, imagePath);
    _sprite.showBackground = false;
    _sprite.backgroundColor = Color(1.0, 0.0, 0.0, 1.0);
    
    _ground.showBackground = true;
    _ground.backgroundColor = Color(1.0, 0.0, 0.0, 1.0);
    _ground.setPosition(0, 390);
    _ground.setSize(320, 10);
   
}

void Game::Update()
{	    
    
    
	
    
    //trace("the y: %f   velocity: %f\n", _sprite._y, _velocity);
    
    
    //gameplay
    
    if (_isJumping)
    {
        _sprite.setPosition(_sprite._x, _sprite._y + _velocity);
        _velocity += _gravity;
        
        if(_sprite._y > 345)
        {
            _sprite.setPosition(_sprite._x, 345);
            _isJumping = false;
        }
    }
    else
    {
        _sprite.Update();
    }
    
    if(input.GetPressed() && !_isJumping)
    {
        trace("mouse was pressed: %f, %f", input.GetLastX(), input.GetLastY());
        
        _sprite.GotoFrame(1);
        _isJumping = true;
        _velocity = -14;
    }
    
    input.Reset();
    
    
    //draw
    
    _renderer.Clear();
    
    _ground.Draw(_renderer);
    _sprite.Draw(_renderer);
    
    
}


