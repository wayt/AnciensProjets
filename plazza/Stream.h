/*
** Stream.h for Plazza in /home/leroy_v/github/Plazza
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Fri Apr 19 13:40:12 2013 vincent leroy
** Last update Fri Apr 19 18:59:27 2013 maxime ginters
*/

#ifndef STREAM_H_
# define STREAM_H_

#include <string>

class Stream
{
    public:
        explicit Stream();
        virtual ~Stream();

        bool open(const std::string &filename, bool read);
        void close();
        bool is_open() const;
        bool send(const std::string &msg) const;
        bool recv(std::string &msg) const;

    private:
        int _fd;
        bool _isOpen;
};

Stream const& operator<<(Stream const& stream, const std::string &msg);
Stream const& operator>>(Stream const& stream, std::string &msg);

#endif /* !STREAM_H_ */
