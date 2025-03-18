using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>

#include <list>
#include <string>


int main()
{
    int number;
    ifstream ReadFile("cities2.txt");
    string query;
    string empty;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // storing File's Data into a character array. References used: https://cplusplus.com/reference/istream/istream/read/
    ReadFile.seekg(0,ReadFile.end);
    int fileLength = ReadFile.tellg();
    ReadFile.seekg(0,ReadFile.beg);
    // cout<<fileLength<<endl;
    char *storage = new char[fileLength];
    ReadFile.read(storage,fileLength);  
    // cout<<storage;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    istringstream numberOfLines(storage);
    int n=0;

    getline(numberOfLines,empty,'\n');
    while (numberOfLines.eof()==0)
    {
        n++;
        getline(numberOfLines,empty,'\n');
    }
    printf("Read in %d lines\n",n);

    istringstream lineReading(storage);
    
    struct City
    {
        int population;
        string name;
        /* data */
    };
    City x;
    list <City> allCities;

    while (lineReading.eof()==0){
        getline(lineReading,empty,' ');
        while (empty==" ")
        {
            getline(lineReading,empty,' ');
        }
        if (lineReading.eof()==1)
        {
            break;
        }
        lineReading>>x.population;
        getline(lineReading,empty,'\t');
        getline(lineReading,x.name);
        cout<<x.name<<endl;
        allCities.emplace_back(x);
    }

    cout<<"Enter the initial letters of a city to find its similarly name cities, ranked by population (this is case-sensitive)."<<endl;
    City *y;
    for (int i = 0; i < 100; i++)
    {
        /* code */
            getline(cin,query);
            if (cin.eofbit==0)
            {
                break;  
            }
            
            list <City> matches_found;
            for (auto & city: allCities)
            {
                if (city.name.find(query)==0)
                matches_found.push_back(city);
            }

            cout<< "TOP MATCHES FOR '"<<query<<"' ARE:"<<endl;
            int count=1;
            for (auto & city: matches_found)
            {
                if (count<=10)
                {
                    cout<<"\t"<<count<<") "<< city.name<<" has a population of "<<city.population<<endl;             
                }
                else
                break;
                count++;
            }
            cout<<"Another city? (use CTRL-D to exist)"<<endl;
    }
    ReadFile.close();   
}               