//
// Created by napbad on 9/12/24.
//

#include "DataSource.h"

DataSource::DataSource() {
    _data = std::vector<std::pair<Dval *, short> >();
    _name = "ROOT";
}

DataSource::DataSource(const std::string &name, const std::vector<std::pair<Dval *, short> > &data) {
    _data = data;
    _name = name;
}

DataSource::~DataSource() {
    for (const auto &i: _data) {
        delete i.first;
    }
    _data.clear();
}

std::string DataSource::name() const {
    return _name;
}

std::vector<std::pair<Dval *, short> > DataSource::data() const {
    return _data;
}

void DataSource::set_data(const std::vector<std::pair<Dval *, short> > &data) {
    _data = data;
}

void DataSource::set_name(const std::string &name) {
    _name = name;
}

void DataSource::add_data(Dval *data) {
    _data.emplace_back(data, ALIVE);
}
