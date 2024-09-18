//
// Created by napbad on 9/12/24.
//


#ifndef DATASOURCE_H
#define DATASOURCE_H
#include <string>
#include <vector>

#include "obj/val.h"

constexpr short ALIVE = 1;
constexpr short DEAD = 0;

class DataSource {
    std::string _name;
    std::vector<std::pair<Dval *, short> > _data;

public:
    DataSource();

    DataSource(const std::string &name, const std::vector<std::pair<Dval *, short> > &data);

    ~DataSource();

    [[nodiscard]] std::string name() const;

    [[nodiscard]] std::vector<std::pair<Dval *, short> > data() const;

    void set_data(const std::vector<std::pair<Dval *, short> > &data);

    void set_name(const std::string &name);

    void add_data(Dval *data);
};

#endif //DATASOURCE_H
