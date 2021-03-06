//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_HOTELDATABASEDAO_H
#define PSQLWORK_HOTELDATABASEDAO_H


#include "../HotelDAO.h"

class HotelDataBaseDAO : public HotelDAO {
public:
    virtual QList<Hotel *> getAll();

    virtual Hotel *getById(int id);

    virtual void add(Hotel *model);

    virtual void update(Hotel *model);

    virtual void del(Hotel *model);

    virtual QList<Hotel *> getAllFilled();
};


#endif //PSQLWORK_HOTELDATABASEDAO_H
