#include <SFML-Book/server/Game.hpp>

#include <SFML-Book/server/Client.hpp>
#include <SFML-Book/server/Team.hpp>

#include <SFML-Book/common/Packet.hpp>

#include <iostream>

namespace book
{
    int Game::_numberOfCreations = 0;
    
    Game::Game() : _running(false), _thread(&Game::_run,this), _id(++_numberOfCreations)
    {
    }

    Game::~Game()
    {
        for(Client* client: _clients)
            delete client;

        for(Team* team : _teams)
            delete team;
    }

    int Game::getTeamCount()
    {
        sf::Lock guard(_teamMutex);
        return _teams.size();
    }

    int Game::getPalyersCount()
    {
        sf::Lock guard(_clientsMutex);
        return _clients.size();
    }

    int Game::id()const
    {
        return _id;
    }

    void Game::addClient(Client* client)
    {
        //send map informations

        std::cout<<"Add client to game"<<std::endl;
        sf::Packet response;
        response<<packet::JoinGameConfirmation();
        client->send(response);

        sf::Lock guard(_clientsMutex);
        _clients.emplace_back(client);
    }

    void Game::run()
    {
        _running = true;
        _thread.launch();
    }

    void Game::stop()
    {
        _running = false;
    }

    void Game::_run()
    {
        sf::Clock clock;        
        while(_running)
        {
            processNetworkEvents();
            update(clock.restart());
        }
    }

    void Game::processNetworkEvents()
    {
        sf::Lock guard(_clientsMutex);
        for(auto it = _clients.begin(); it != _clients.end();++it)
        {
            Client* client = *it;
            packet::NetworkEvent* msg;
            while(client and client->pollEvent(msg))
            {
                switch(msg->type())
                {
                    case FuncIds::IdCreateEntity :
                    {
                    }break;
                    case FuncIds::IdDestroyEntity :
                    {
                    }break;
                    case FuncIds::IdDisconnected :
                    {
                        it = _clients.erase(it);
                        --it;
                        client = nullptr;
                    }break;
                    default : break;
                }
            }
        }
    }

    void Game::update(sf::Time deltaTime)
    {
    }
}
