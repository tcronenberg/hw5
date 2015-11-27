#include <iostream>
#include <cmath>

using namespace std;

int main(){
  const double T = 20*M_PI;
  const double dt = M_PI/100.0;
  const double N = T/dt;
  
  double yf[2] = {1,0};
  double yb[2] = {1,0};
  double analyt = 1;
 
  cout << "0" << "\t" << yf[0] << "\t" << yb[0] << "\t" << analyt << endl;
  
  for(int i=1; i <= N; i++){
    yf[0] = yf[0] + dt * yf[1];
    yf[1] = yf[1] - dt * yf[0];
    yb[0] = (yb[0] + yb[1] * dt) / (1 + dt*dt);
    yb[1] = (yb[1] - yb[0] * dt) / (1 - dt*dt);
    analyt = cos(i*dt);
    cout << i*dt << "\t" << yf[0] << "\t" << yb[0] << "\t" << analyt << endl;
  }
  
  return 0;
}