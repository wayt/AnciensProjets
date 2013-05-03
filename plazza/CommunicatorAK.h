/*
** CommunicatorAK.h for namedPipe in /home/leroy_v/Epitech/projet_tek2/namedPipe
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Tue Apr 16 18:21:25 2013 vincent leroy
** Last update Fri Apr 19 19:03:41 2013 maxime ginters
*/

#ifndef COMMUNICATORAK_H_
# define COMMUNICATORAK_H_

#include <string>
#include <map>
#include "SharedDefines.h"
#include "Singleton.hpp"
#include "Stream.h"

#define PIPE_AK_NAME "pipeAK"
#define PIPE_KA_NAME "pipeKA"


class CommunicatorAK : public Singleton<CommunicatorAK>
{
    public:
        explicit CommunicatorAK();
        virtual ~CommunicatorAK();

        void init();
        void addKitchen(uint32 id);
        void removeKitchen(uint32 id);
        bool send(const std::string &msg, uint32 id) const;
        std::string recv() const;

        static void delFdOut(std::pair<const uint32, Stream>& p);

        Stream const& operator[](uint32 id) const;

        CommunicatorAK const& operator>>(std::string &msg) const;

    private:
        Stream _fdIn;
        std::map<uint32, Stream> _fdOut;
};

#define sCommunicatorAK CommunicatorAK::instance()

#endif /* !COMMUNICATORAK_H_ */
