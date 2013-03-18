#ifndef ICONVEYORBELT_H_
#define ICONVEYORBELT_H_
#include <string>
#include "Object.h"

class IConveyorBelt {
    public:
	virtual ~IConveyorBelt() {}
	virtual Object* take() = 0;
	virtual void put(Object*) = 0;
	virtual std::string Look() = 0;
	virtual void IN() = 0;
	virtual void OUT() = 0;
};

#endif /* !ICONVEYORBELT_H_ */
