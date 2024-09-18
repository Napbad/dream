//
// Created by napbad on 9/12/24.
//

#include "gc.h"

void GC::collect(const DataSource *ds) {
    //
    for (const std::vector<std::pair<Dval *, short>> vector = ds->data();
        const auto &[fst, snd] : vector) {
        const Dval *dval = fst;
        if (snd < 1) {
            delete dval;
        }
    }
}

void GC::collect(const Dval *val) {

}
