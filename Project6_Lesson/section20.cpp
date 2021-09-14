#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using std::cout;
using std::endl;
using std::vector;
using std::pow;
using std::distance;
using std::min_element;

int main() {
  // define vectors in Map coordinate
  vector<vector<double>> tobs = {{6.,3.},{2.,2.},{0.,5.}};
  vector<vector<double>> sensor_obs = {{5.,3.},{2.,1.},{6.,1.},{7.,4.},{4.,7.}};
  vector<double> dist = {0,0,0,0,0};
  vector<int> dist_index = {0,0,0,0,0};
  vector<int> nearestL = {0,0,0};
  int nearestIndex;
  double temp_dist;
  int temp_dist_index;

  vector<double> mg_probability = {0.,0.,0.};
 
  // set same standard deviation for sigma_x^2, sigma_y^2, sigma_x*sigma_y
  double stdev_com = 0.3*0.3;

  // calculate distances
  for (int i = 0; i < tobs.size(); i++){
    for (int j = 0; j < sensor_obs.size(); j++){
      dist[j] = sqrt(pow(tobs[i][0]-sensor_obs[j][0],2)+pow(tobs[i][1]-sensor_obs[j][1],2));
    }

    double dist_0 = dist[0];
    double dist_1 = dist[1];
    double dist_2 = dist[2];
    double dist_3 = dist[3];
    double dist_4 = dist[4];

    for (int k = 0; k < dist.size(); k++){
      dist_index[k] = k;
    }

    int dist_index_0 = dist[0];
    int dist_index_1 = dist[1];
    int dist_index_2 = dist[2];
    int dist_index_3 = dist[3];
    int dist_index_4 = dist[4];

    for (int k = 0; k < (dist.size() -1); k++){
      if(dist[k]<dist[k+1]){
        temp_dist = dist[k+1];
        temp_dist_index = dist_index[k+1];
        dist[k+1] = dist[k];
        dist_index[k+1] = dist_index[k];
        dist[k] = temp_dist;
        dist_index[k] = temp_dist_index;        
      }
    }

    nearestIndex = dist_index[dist_index.size()-1];

    mg_probability[i] = 1.0/(2.0*M_PI*stdev_com)*
                        exp(-(pow((tobs[i][0]-sensor_obs[nearestIndex][0]),2)/(2.0*stdev_com)
                        +pow((tobs[i][1]-sensor_obs[nearestIndex][1]),2)/(2.0*stdev_com)));

    nearestL[i] = nearestIndex;
  }

  int nearestL_0 = nearestL[0];
  int nearestL_1 = nearestL[1];
  int nearestL_2 = nearestL[2];

  double mg_probability_0 = mg_probability[0];
  double mg_probability_1 = mg_probability[1];
  double mg_probability_2 = mg_probability[2];

  double mg_probability_total = mg_probability[0]* mg_probability[1]* mg_probability[2];
  

  std::ofstream outputfile("test.txt");
  outputfile << nearestL[0] << "," << nearestL[1] << "," << nearestL[2] << endl;
  outputfile << mg_probability[0] << "," << mg_probability[1] << "," << mg_probability[2] << endl;
  outputfile << mg_probability_total << endl;
  
  outputfile.close();

  return 0;
}