#ifndef PLOTTER_H
#define PLOTTER_H

#include <vector>
#include <string>

class Plotter{
    public:
        void plot(std::vector<std::vector<float>> data); // add a layer of abstraction between the plotting and saving functiosn and the user
        // 
    private:
        void saveData(std::vector<std::vector<float>> data);
        void plotData();
        std::string _datafilename = "data.txt";
        std::vector<std::vector<float>> _data;
};

#endif