#ifndef BOOK_FUNCIDS_HPP
#define BOOK_FUNCIDS_HPP

namespace book
{
    namespace FuncIds{
        enum FUNCIDS {
            //specials
            IdHandler = 0,
            IdDisconnected,

            //main menu
            IdGetListGame, //client
            IdSetListGame, //server
            IdCreateGame, //client
            IdJoinGame, //client
            IdJoinGameConfirmation, //server
            IdJoinGameReject, //server

            //in game
            IdCreateEntity, //client
            IdDestroyEntity, //client and server
            IdMoveEntity, //server
            IdHittedEntity, //server
            IdHitEntity, //server
            IdSetAnimationEntity, //server
            IdAddGoldTeam, //server
        };
    }
}

#endif