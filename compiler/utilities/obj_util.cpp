//
// Created by napbad on 11/19/24.
//

#include "obj_util.h"

void obj_util::deleteDelayedObj()
{
    while (!delayedDeleteObjVector.empty()) {
        const auto obj = delayedDeleteObjVector.back();
        delayedDeleteObjVector.erase(delayedDeleteObjVector.end() - 1);
        delete obj;
    }
}