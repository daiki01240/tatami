#include "tatami.hpp"

void tatami::registry(account_name school_name, std::string pub_key)
{
    require_auth(school_name);
    //_users.get(school, "User is already exist");

    _schools.emplace(get_self(),[&](auto &s)
    {
        s.school_id = _schools.available_primary_key();
        s.school_name = school_name;
        s.pub_key = pub_key;
    });
}

void tatami::addclaim(account_name student_name, vector<string> &signature, vector<string> &row_type)
{
    require_auth(student_name);
    //_users.get(school, "User is already exist");

    _students.emplace(get_self(), [&](auto &s) {
        s.student_name = student_name;
        s.signature = signature;
        s.row_type = row_type;
    });
}

void tatami::verifyclaim(account_name student_name, uint64_t index)
{
    return;
}