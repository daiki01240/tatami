#include <string>
#include <stdio.h>
#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>
#include <eosio.token/eosio.token.hpp>
#include <eosio.system/eosio.system.hpp>

using namespace eosio;

class tatami : public eosio::contract
{
    private:
      //@abi table schools
      struct school
      {
          uint64_t school_id;
          std::string school_name;
          std::string pub_key;

          auto primary_key() const { return school_id; }
      };

      //@abi table students
      struct student
      {
          account_name student_name;
          vector<string> signature;
          vector<string> row_type;
          //   vector<cliam> claim;
          auto primary_key() const { return student_name; }
      };

    //   //@abi table informations
    //   struct infomation
    //   {
    //       std::stirng signature;
    //       std::string row_type;
    //   }

    //   typedef std::string claim;

      typedef eosio::multi_index<N(schools),school> schools_table;
      typedef eosio::multi_index<N(students), student> students_table;

      schools_table _schools;
      students_table _students;

    public:
      tatami(account_name self) : contract(self), _schools(self, self), _students(self, self){}

      void registry(account_name school_name, std::string pub_key);

      void addclaim(account_name student_name, vector<string> &signature, vector<string> &row_type);

      void verifyclaim(account_name student_name, uint64_t index);
};