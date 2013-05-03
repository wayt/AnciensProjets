/*
** main.cpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Apr 15 11:37:55 2013 maxime ginters
** Last update Sat Apr 20 17:09:43 2013 fabien casters
*/

#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <csignal>
#include <cstring>
#include <iostream>
#include <execinfo.h>
#include "Accueil.h"
#include "Log.h"
#include "CommunicatorAK.h"

void inter_sig(int signum)
{
    signal(signum, &inter_sig);

    if (signum == SIGINT)
        sAccueil->stop();
    else if (signum == SIGWINCH)
    {
        sAccueil->resize();
        signal(SIGWINCH, &inter_sig);
    }
    else if (signum == SIGSEGV)
        std::cout << "Et c'est le segfault !" << std::endl;
}

void print_usage()
{
    std::cout << "Usage : ./plazza cook_time_multiplicator cook_count regen_time" << std::endl;
}

int	main(int ac, char **av)
{
    if (!sLog->initialize())
        return 1;

    signal(SIGCHLD, SIG_IGN);
    signal(SIGINT, &inter_sig);
    signal(SIGWINCH, &inter_sig);

    if (!sAccueil->initialize(ac, av))
    {
        print_usage();
        return 1;
    }


    sAccueil->run();
    delete sAccueil;
    delete sLog;
    delete sCommunicatorAK;
    return (0);
}
