#ifndef EMPLOYEEREPO_H
#define EMPLOYEEREPO_H

#include <fstream>
#include "Employee.h"
#include <string>
#include <vector>
const string DATABASE_FOLDER = "Databases/";
using namespace std;

class EmployeeRepo
{
    public:
        EmployeeRepo();
        void write(Employee e);
        //write the Employee class to file
        vector<string> read_until_comma(string in);
        //Returns a vector where each element is a substring
        //made by dividing the string where a comma occurs.
        vector<string> open_by_year(const string& year);
        //Postcondtion: If the file is not empty, then the return
        //value is a vector where v[0] is the year followed by the month,
        //name, SSN and salary until and so on until there is no information
        //left to read.
        vector<string> open_by_SSN(const string& SSN);
        //Postcondtion: If the file is not empty, then the return
        //value is a vector where v[0] is the name, v[1] is the SSN
        //and then month, year, salary, and so on... until no
        //information is left to read.
        bool first_instance(const string& input, const string& file, int pos);
        //Opens the stream from file and checks if the first string realative
        //to pos until a whitespace is read is the same as input.
        //The return value is true if the string is not found. Also,
        //if the file is not successfully open, the return value is true
        string year_write_format(const Employee& e);
        //The return value is the year format of the data to be written
        string id_write_format(const Employee& e);
        //The return value is the id format of the data to be written
        void rewrite(const Employee& e);
        //Rewrites correspondig to information gotten from e.
    private:
        void rewrite_id_data(Employee e, string month);
        //Precondition: tell contains the postition of the stream
        //gotten from the rewrite_if_same_month, also this function
        //should only be called from within rewrite_if_same_month since
        //information is realative to that function.
        //Postcondition: The id database has been rewritten corresponding
        //the rewrites made to the year database.
        void rewrite_year_data(int tell, Employee e);
        //Similar to the above function.
        void get_year_from_stream(string& out_year, string in_year);
        //Helper function for the year DATABASE, gets the year from a file.
        void get_name_ssn_from_stream(string& name, string& SSN, string id);
        //Helper function for open_by_SSN. Gets the name from a file.
        void rewrite_data(string emp, string folder, int tell, vector<string> lines);
        //Helper function for rewrite.
        void write_by_id(Employee e);
        //Helper function for writing id.database.information.
        //Writes a prelude to the file if there is none and calls id_write_format().
        void write_by_year(Employee e);
        //Helper function for writing year.database.information.
        //Writes a prelude for a file in the year DATABASE.
        int month_position(Employee e);
        //Finds the first occurrence of month in file, and then returns after
        //finding the first occurrence of the given month, and return value
        //is the position in the stream.
        string remove_new_line(string in);
        //Removes line breaks.
        int find_line_in_id(string month, string SSN);
        //If month is found in the id database corresponding to the SSN
        //then the return value is the line position of the stream.
        //Else -1 is returned.
        Employee empl;
};

#endif // EMPLOYEEREPO_H
