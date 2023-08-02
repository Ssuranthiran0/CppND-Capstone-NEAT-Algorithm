#include "plotter.h"

#include <vector>
#include <fstream>

void Plotter::plot(std::vector<std::vector<float>> data){
    saveData(data); // save
    plotData(); // plot
}

void Plotter::saveData(std::vector<std::vector<float>> data){
    _data = data;

    std::ofstream datafile; // output filestream
    datafile.open(_datafilename); // open file
    for (int i=0; i< _data.size(); i++){ // loop through all
        datafile << _data[i][0] << _data[i][1] << "\n"; // add to file
    }
    datafile.close(); // close file

}

void Plotter::plotData(){}