/*
** koalatchi.c for ex07 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_j01-2016-ginter_m/ex07
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 09 21:08:24 2013 maxime ginters
** Last update Wed Jan 09 22:20:56 2013 maxime ginters
*/

#include <stdint.h>
#include <stdio.h>

enum MessageType
{
    TYPE_NOTIFICATION   = 0x01,
    TYPE_REQUEST        = 0x02,
    TYPE_ERROR          = 0x04
};

enum ApplicationDomain
{
    DOM_NUTRITION       = 0x01,
    DOM_ENTRAINEMENT    = 0x02,
    DOM_EDUCATION       = 0x04,
};

int prettyprint_message(uint32_t header, char const* content)
{
    if ((header >> 24) & TYPE_NOTIFICATION)
    {
        if ((header >> 16) & DOM_NUTRITION)
        {
            if (header & 0x01)
                printf("Notification Nutrition Eat");
            else if (header & 0x02)
                printf("Notification Nutrition Defecate");
            else
            {
                printf("Invalid message.\n");
                return 1;
            }
        }
        else if ((header >> 16) & DOM_ENTRAINEMENT)
        {
            if (header & 0x01)
                printf("Notification Entretainement Ball");
            else if (header & 0x02)
                printf("Notification Entretainement Bite");
            else
            {
                printf("Invalid message.\n");
                return 1;
            }
        }
        else if ((header >> 16) & DOM_EDUCATION)
        {
            if (header & 0x01)
                printf("Notification Education TeachCoding");
            else if (header & 0x02)
                printf("Notification Education BeAwesome");
            else
            {
                printf("Invalid message.\n");
                return 1;
            }
        }
        else
        {
            printf("Invalid message.\n");
            return 1;
        }
    }
    else if ((header >> 24) & TYPE_REQUEST)
    {
        if ((header >> 16) & DOM_NUTRITION)
        {
            if (header & 0x01)
                printf("Request Nutrition Hungry");
            else if (header & 0x02)
                printf("Request Nutrition Thirsty");
            else
            {
                printf("Invalid message.\n");
                return 1;
            }
        }
        else if ((header >> 16) & DOM_ENTRAINEMENT)
        {
            if (header & 0x01 && !(header & 0x02))
                printf("Request Entretainement NeedAffection");
            else if (header & 0x02 && !(header & 0x01))
                printf("Request Entretainement WannaPlay");
            else if (header & 0x03)
                printf("Request Entretainement Hug");
            else
            {
                printf("Invalid message.\n");
                return 1;
            }
        }
        else if ((header >> 16) & DOM_EDUCATION)
        {
            if (header & 0x01)
                printf("Request Education FeelStupid");
            else
            {
                printf("Invalid message.\n");
                return 1;
            }
        }
        else
        {
            printf("Invalid message.\n");
            return 1;
        }
    }
    else if ((header >> 24) & TYPE_ERROR)
    {
        if ((header >> 16) & DOM_NUTRITION)
        {
            if (header & 0x01)
                printf("Error Nutrition Indigestior");
            else if (header & 0x02)
                printf("Error Nutrition Straving");
            else
            {
                printf("Invalid message.\n");
                return 1;
            }
        }
        else if ((header >> 16) & DOM_ENTRAINEMENT)
        {
            if (header & 0x01)
                printf("Error Entertainement Bored");
            else
            {
                printf("Invalid message.\n");
                return 1;
            }
        }
        else if ((header >> 16) & DOM_EDUCATION)
        {
            if (header & 0x01)
                printf("Error Education BrainDamage");
            else
            {
                printf("Invalid message.\n");
                return 1;
            }
        }
        else
        {
            printf("Invalid message.\n");
            return 1;
        }
    }
    else
    {
        printf("Invalid message.\n");
        return 1;
    }

    if (content)
        printf(" %s", content);
    printf("\n");
    return 0;
}
