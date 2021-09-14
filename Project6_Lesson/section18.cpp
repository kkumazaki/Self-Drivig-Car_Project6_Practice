#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

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
  //vector<double> dist;
  //vector<int> dist_index;
  //vector<int> nearestL;
  vector<double> dist = {0,0,0,0,0};
  vector<int> dist_index = {0,0,0,0,0};
  vector<int> nearestL = {0,0,0};
  int nearestIndex;
  double temp_dist;
  int temp_dist_index;

  /*
  double tobs_00 = tobs[0][0];
  double tobs_01 = tobs[0][1];
  double tobs_10 = tobs[1][0];
  double tobs_11 = tobs[1][1];
  double tobs_20 = tobs[2][0];
  double tobs_21 = tobs[2][1];

  double sensor_00 = sensor_obs[0][0];
  double sensor_01 = sensor_obs[0][1];
  double sensor_10 = sensor_obs[1][0];
  double sensor_11 = sensor_obs[1][1];
  double sensor_20 = sensor_obs[2][0];
  double sensor_21 = sensor_obs[2][1];
  double sensor_30 = sensor_obs[3][0];
  double sensor_31 = sensor_obs[3][1];
  double sensor_40 = sensor_obs[4][0];
  double sensor_41 = sensor_obs[4][1];
  */

  // calculate distances
  for (int i = 0; i < tobs.size(); i++){
    for (int j = 0; j < sensor_obs.size(); j++){
      // somehow, push_back cannot control index correctly...
      //dist.push_back(sqrt(pow(tobs[i][0]-sensor_obs[j][0],2)+pow(tobs[i][1]-sensor_obs[j][1],2)));
      dist[j] = sqrt(pow(tobs[i][0]-sensor_obs[j][0],2)+pow(tobs[i][1]-sensor_obs[j][1],2));
    }

    double dist_0 = dist[0];
    double dist_1 = dist[1];
    double dist_2 = dist[2];
    double dist_3 = dist[3];
    double dist_4 = dist[4];

    // somehow, error occurs in the following codes...
    //vector<int>::iterator minIt = min_element(dist.begin(), dist.end());
    //size_t minIndex = distance(dist.begin(), minIt);

    // get the index of smallest distance
    //vector<int> dist_index;
    //double temp_dist;
    //int temp_dist_index;

    for (int k = 0; k < dist.size(); k++){
      // somehow, push_back cannot control index correctly...
      //dist_index.push_back(k);
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
    //cout << nearestIndex << endl;

    //clear the temporary vectors
    // if I don't use push_back, these are not necessary
    //dist.clear();
    //dist.shrink_to_fit();
    //dist_index.clear();
    //dist_index.shrink_to_fit();

    // somehow, push_back cannot control index correctly... 
    //nearestL.push_back(nearestIndex);
    nearestL[i] = nearestIndex;
  }

  int nearestL_0 = nearestL[0];
  int nearestL_1 = nearestL[1];
  int nearestL_2 = nearestL[2];

  cout << "Nearest from TOBS1: " << nearestL[0] << endl;
  cout << "Nearest from TOBS2: " << nearestL[1] << endl;
  cout << "Nearest from TOBS3: " << nearestL[2] << endl;


  return 0;
}