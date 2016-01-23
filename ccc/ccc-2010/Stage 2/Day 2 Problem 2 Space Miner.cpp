#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x)(x).begin(),(x).end()
#define x first
#define y second
using namespace std;


struct vector3D{
     double x,y,z;
     vector3D(){x = y = z = 0;}
     vector3D(double _x,double _y,double _z){
          x = _x,y = _y,z = _z;
     }
     // misceallanous
     double magnitude(){
        return sqrt(x*x+y*y+z*z);
     }
     // operators
     void operator = (const vector3D&v){
          x = v.x;
          y = v.y;
          z = v.z;
     }
     vector3D unit_vector(){// unit vector
        return (vector3D){x/this->magnitude(),y/this->magnitude(),z/this->magnitude()};
     }
     // operations
     vector3D operator + (const vector3D&v){ // addition
         return (vector3D){x+v.x,y+v.y,z+v.z};
     }
     vector3D operator - (const vector3D&v){// substraction
         return (vector3D){x-v.x,y-v.y,z-v.z};
     }
     vector3D operator * (const vector3D&v){// cross product
        return (vector3D){y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x};
     }
     double operator ^ (const vector3D&v){// dot product
          return x*v.x + y*v.y + z*v.z;
     }

};

struct planet{
   int v,r;
   vector3D p;
   planet(double x,double y, double z,int _v,int _r){
      v = _v, r = _r;
      p = (vector3D){x,y,z};
   }
};
struct gate{
  vector3D p;
  gate(double x,double y, double z){
     p = (vector3D){x,y,z};
  }
};



const int MAXM = 1000;
int M,N,D;
bool vis[MAXM];
vector<planet>planets;
vector<gate>gates;


bool within_range(gate one,gate two,planet pt){
    vector3D v0 = two.p-one.p;
    vector3D v1 = pt.p-one.p;
    vector3D v2 = pt.p-two.p;
    if( (v1 ^ v0) < 0){
       // the projection of the vector lies outside the line segment
       // and counter clockwise to the line segment. So we just take
       // the magnitude of v1
       if(v1.magnitude() <= pt.r+D )
          return true;
       else
          return false;
    }
    if( (v2^v0) > 0){
       // the projection of the vector lies outside the line segment
       // and lockwise to the line segment. So we just take
       // the magnitude of v2
       if(v2.magnitude() <= pt.r+D)
          return true;
       else
         return false;
    }
    // the point is within the boundaries of the vector so we take the cross product
    // of v0 and v1 to get the area of the parrelogram then we divide it by its base
    // to get the height. Which in this case is the distance from the line
    if( (v0*v1).magnitude()/v0.magnitude() <= pt.r+D )
        return true;

    return false;
}

int main(){
    freopen("Input/space1.in","r",stdin);
    cin >> M;
    for(int i = 0;i < M;i++){
        double x,y,z;
        int v,r;
        cin >> x >> y >> z >> v >> r;
        planets.pb( (planet){x,y,z,v,r});
    }
    cin >> N;
    for(int i = 0;i < N;i++){
        double x,y,z;
        cin >> x >> y >> z;
        gates.pb( (gate){x,y,z});
    }
    cin >> D;
    int cnt = 0;
    for(int i = 0;i < (int)gates.size()-1;i++){
        for(int j = 0;j < M;j++){
            if( !vis[j] && within_range(gates[i],gates[i+1],planets[j])){
                vis[j] = true;
                cnt += planets[j].v;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

