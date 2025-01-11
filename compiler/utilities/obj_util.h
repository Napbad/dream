//
// Created by napbad on 11/19/24.
//

#ifndef OBJ_UTIL_H
#define OBJ_UTIL_H
#include <queue>

namespace obj_util
{
class DelayDeleteObjBase
{
};

template <typename T> class DelayDeleteObj : public DelayDeleteObjBase
{
  public:
    T *obj;

    ~DelayDeleteObj()
    {
        delete obj;
    }

    explicit DelayDeleteObj(T *obj) : obj(obj)
    {
    }
};

static std::vector<DelayDeleteObjBase *> delayedDeleteObjVector;

void deleteDelayedObj();

} // namespace obj_util

#endif // OBJ_UTIL_H