#include <SFML-Book/server/EntityData.hpp>
#include <SFML-Book/server/Entity.hpp>


REGISTER_AND_CONSTRUCT(EntityData,"EntityData",\
         _game,"game_id",\
         _coordX,"coordX",\
         _coordY,"coordY",\
         _type,"type",\
         _AIMain,"AIMain",\
         _AIWarrior,"AIWarrior",\
         _AIDefender,"AIDefender",\
         _AISpawner,"AISpawner",\
         _AIWalker,"AIWalker",\
         _AIFlyer,"AIFlyer",\
         _team,"team",\
         _skin,"skin",\
         _hp,"hp")

EntityData::type_ptr EntityData::createFromEntity(Entity& entity,Game::type_ptr game)
{
    sf::Vector2i coords = entity.getCoord();


    EntityData::type_ptr e = EntityData::create();

    e->_game = game;
    e->_coordX = coords.x;
    e->_coordY = coords.y;
    e->_type = entity.getType();

    if(entity.has<CompAIMain>())
    {
        CompAIMain* comp_raw_ptr = entity.component<CompAIMain>().get();
        std::shared_ptr<CompAIMain> comp_ptr(comp_raw_ptr);
        e->_AIMain = comp_ptr;
    }

    if(entity.has<CompAIWarrior>())
    {
        CompAIWarrior* comp_raw_ptr = entity.component<CompAIWarrior>().get();
        std::shared_ptr<CompAIWarrior> comp_ptr(comp_raw_ptr);
        e->_AIWarrior = comp_ptr;
    }

    if(entity.has<CompAIDefender>())
    {
        CompAIDefender* comp_raw_ptr = entity.component<CompAIDefender>().get();
        std::shared_ptr<CompAIDefender> comp_ptr(comp_raw_ptr);
        e->_AIDefender = comp_ptr;
    }

    if(entity.has<CompAISpawner>())
    {
        CompAISpawner* comp_raw_ptr = entity.component<CompAISpawner>().get();
        std::shared_ptr<CompAISpawner> comp_ptr(comp_raw_ptr);
        e->_AISpawner = comp_ptr;
    }

    if(entity.has<CompAIWalker>())
    {
        CompAIWalker* comp_raw_ptr = entity.component<CompAIWalker>().get();
        std::shared_ptr<CompAIWalker> comp_ptr(comp_raw_ptr);
        e->_AIWalker = comp_ptr;
    }

    if(entity.has<CompAIFlyer>())
    {
        CompAIFlyer* comp_raw_ptr = entity.component<CompAIFlyer>().get();
        std::shared_ptr<CompAIFlyer> comp_ptr(comp_raw_ptr);
        e->_AIFlyer = comp_ptr;
    }

    if(entity.has<CompTeam>())
    {
        CompTeam* comp_raw_ptr = entity.component<CompTeam>().get();
        std::shared_ptr<CompTeam> comp_ptr(comp_raw_ptr);
        e->_team = comp_ptr;
    }

    if(entity.has<CompSkin>())
    {
        CompSkin* comp_raw_ptr = entity.component<CompSkin>().get();
        std::shared_ptr<CompSkin> comp_ptr(comp_raw_ptr);
        e->_skin = comp_ptr;
    }

    if(entity.has<CompHp>())
    {
        CompHp* comp_raw_ptr = entity.component<CompHp>().get();
        std::shared_ptr<CompHp> comp_ptr(comp_raw_ptr);
        e->_hp = comp_ptr;
    }

    return e;
}

std::uint32_t EntityData::convertToEntity(Game& game)
{

    sf::Vector2i coord(_coordX,_coordY);
    sf::Vector2f pos = game.mapCoordsToPixel(coord);

    auto id = game.entities.create();
    Entity& e = game.entities.get(id);

    e._type = _type;
    game.setPosition(e,sf::Vector2i(0,0),sf::Vector2f(0,0),coord,pos);


    if(this->_AIMain)
    {
        e.add<CompAIMain>();
        auto comp = e.component<CompAIMain>();

        *comp.get() = *_AIMain;
    }

    std::cout<<*this<<std::endl;

   /* if(this->_AIWarrior)
    {
        CompAIWarrior* comp_raw_ptr = entity.component<CompAIWarrior>().get();
        std::shared_ptr<CompAIWarrior> comp_ptr(comp_raw_ptr);
        e->_AIWarrior = comp_ptr;
    }

    if(this->_AIDefender)
    {
        CompAIDefender* comp_raw_ptr = entity.component<CompAIDefender>().get();
        std::shared_ptr<CompAIDefender> comp_ptr(comp_raw_ptr);
        e->_AIDefender = comp_ptr;
    }

    if(this->_AISpawner)
    {
        CompAISpawner* comp_raw_ptr = entity.component<CompAISpawner>().get();
        std::shared_ptr<CompAISpawner> comp_ptr(comp_raw_ptr);
        e->_AISpawner = comp_ptr;
    }

    if(this->_AIWalker)
    {
        CompAIWalker* comp_raw_ptr = entity.component<CompAIWalker>().get();
        std::shared_ptr<CompAIWalker> comp_ptr(comp_raw_ptr);
        e->_AIWalker = comp_ptr;
    }

    if(this->_AIFlyer)
    {
        CompAIFlyer* comp_raw_ptr = entity.component<CompAIFlyer>().get();
        std::shared_ptr<CompAIFlyer> comp_ptr(comp_raw_ptr);
        e->_AIFlyer = comp_ptr;
    }

    if(this->_team)
    {
        CompTeam* comp_raw_ptr = entity.component<CompTeam>().get();
        std::shared_ptr<CompTeam> comp_ptr(comp_raw_ptr);
        e->_team = comp_ptr;
    }

    if(this->_skin)
    {
        CompSkin* comp_raw_ptr = entity.component<CompSkin>().get();
        std::shared_ptr<CompSkin> comp_ptr(comp_raw_ptr);
        e->_skin = comp_ptr;
    }

    if(this->_hp)
    {
        CompHp* comp_raw_ptr = entity.component<CompHp>().get();
        std::shared_ptr<CompHp> comp_ptr(comp_raw_ptr);
        e->_hp = comp_ptr;
    }*/



    return id;
}

void EntityData::after_load()
{

    sf::Vector2i coords(_coordX,_coordY);

    book::MakeAs makAs = book::getMakeAs(_type);
}

void EntityData::before_save()
{

}

void EntityData::before_update()
{
    before_save();
}
