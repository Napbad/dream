//
// Created by napbadsen on 24-10-17.
//

#include "FunDataRoot.h"
#include "../reserve/d_define.h"
#include "../dbg/debug_util.h"

void FunDataRoot::add_data(GCable* data)
{
    _data.push_back(data);
}

void FunDataRoot::gc()
{
    for (const auto& d : _data)
        d->gc();
}

void FunDataRoot::exit()
{
    #ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "Exit FunDataRoot: %p \n\0", this);
    dbg_util::dbg_print(std::cout, buffer);
#endif


}

void FunDataRoot::destroy()
{
#ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "Destroy FunDataRoot: %p \n\0", this);
    dbg_util::dbg_print(std::cout, buffer);
#endif
    for (const auto data : _data)
        data->destroy();
}
