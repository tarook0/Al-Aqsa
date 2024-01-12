#include "Mesh.h"
#include "Transform.h"
#include "Color.hpp"
#include <Octagon.h>


using namespace std;
using namespace glm;

Octagon::Octagon(glm::vec3 c,int x,const char* texturePath,Material material) : Mesh(Transform(),texturePath,material,GL_POLYGON,nullptr) 
{
  
  if(x==0){
    upFace(c);
  }
  else if(x==1){
    downFace(c);
  }
  else if(x==2){
    octagonDarw1(c);
  }
  else if(x==3){
    octagonDarw2(c);
  }
  else if(x==4){
    octagonDarw3(c);
  }
  else if(x==5){
    octagonDarw4(c);
  }
  else if(x==6){
    octagonDarw5(c);
  }
  else if(x==7){
    octagonDarw6(c);
  }
  else if(x==8){
    octagonDarw7(c);
  }
else if(x==9){
    octagonDarw8(c);
  }
    init(true);
}

void Octagon::upFace(glm::vec3 c)
{
positions = {
    {1.84791f,0.0f,  0.764999f},      //0
    {0.76647f,0.0f,  1.8473f},        //1
    {-0.763527f,0.0f, 1.84852f},     //2
    {-1.84669f,0.0f ,0.767941f},     //3
    {-1.84913f,0.0f ,-0.762055f},    //4
    {-0.769411f,0.0f,-1.84608f},    //5
    {0.760582f,0.0f ,-1.84973f},     //6
    {1.84547f,0.0f  ,-0.770882f},     //7    
};

 
  normals = vector<vec3>(8, {0, 1, 0});
  uvs = vector<vec2>{
                      {0.0f, 0.3f},  // 0
                   {0.0f, 0.6f},  // 1
                   {0.3f, 0.9f},  // 2
                   {0.6f, 0.9f},   // 3
                   {0.9f, 0.6f}, // 4
                   {0.9f, 0.3f}, // 5
                   {0.6f, 0.0f},   // 6
                   {0.3f, 0.0f}     // 7          
};
   colors = vector<vec4>(8, {c, 1});

}

void Octagon::octagonDarw1(glm::vec3 c)
{
    init(true);
     positions= {{1.84791f   ,0.0f,0.764999f},      //0
    {1.84791f   ,2.0f,0.764999f},        //0
    {0.76647f   ,2.0f,1.8473f},      //1
    {0.76647f   ,0.0f,1.8473f},};        //1
    normals = vector<vec3>(8, {0, 1, 0});
  uvs = vector<vec2>{{0.0f, 0.0f},  // 0
                   {0.0f, 1.0f},   // 1
                   {1.0f, 1.0f},
                   {1.0f, 0.0f} 
};
   colors = vector<vec4>(4, {c, 1});
}

void Octagon::octagonDarw2(glm::vec3 c)
{
    init(true);
    positions={{0.76647f   ,0.0f,1.8473f},        //1
    {0.76647f   ,2.0f,1.8473f},     //1
    {-0.763527f ,2.0f,1.84852f},     //2
    {-0.763527f,0.0f,1.84852f},};     //2
     normals = vector<vec3>(8, {0, 1, 0});
  uvs = vector<vec2>{{0.0f, 0.0f},  // 0
                   {0.0f, 1.0f},   // 1
                   {1.0f, 1.0f},
                   {1.0f, 0.0f}   // 2
                   
};
   colors = vector<vec4>(4, {c, 1});
}

void Octagon::octagonDarw3(glm::vec3 c)
{
    init(true);
    
   positions={ {-0.763527f,0.0f,1.84852f},     //2
    {-0.763527f ,2.0f,1.84852f},     //2
    {-1.84669f  ,2.0f,0.767941f},     //3
    {-1.84669f,0.0f,0.767941f},   } ; //3
     normals = vector<vec3>(8, {0, 1, 0});
  uvs = vector<vec2>{{0.0f, 0.0f},  // 0
                   {0.0f, 1.0f},   // 1
                   {1.0f, 1.0f},
                   {1.0f, 0.0f} 
};
   colors = vector<vec4>(4, {c, 1});
}

void Octagon::octagonDarw4(glm::vec3 c)
{
    init(true);
    positions={
    {-1.84669f,0.0f,0.767941f},     //3
    {-1.84669f  ,2.0f,0.767941f},     //3
    {-1.84913f  ,2.0f,-0.762055f},    //4
    {-1.84913f,0.0f,-0.762055f},    //4
};
     normals = vector<vec3>(4, {0, 1, 0});
  uvs = vector<vec2>{{0.0f, 0.0f},  // 0
                   {0.0f, 1.0f},   // 1
                   {1.0f, 1.0f},
                   {1.0f, 0.0f} 
};
   colors = vector<vec4>(4, {c, 1});
   
}

void Octagon::octagonDarw5(glm::vec3 c)
{
    init(true);
    positions={    
    {-1.84913f,0.0f,-0.762055f},    //4
    {-1.84913f  ,2.0f,-0.762055f},    //4
    {-0.769411f ,2.0f,-1.84608f},    //5
    {-0.769411f,0.0f,-1.84608f},    //5
};
    normals = vector<vec3>(4, {0, 1, 0});
  uvs = vector<vec2>{{0.0f, 0.0f},  // 0
                   {0.0f, 1.0f},   // 1
                   {1.0f, 1.0f},
                   {1.0f, 0.0f} 
  };
   colors = vector<vec4>(4, {c, 1});
}

void Octagon::octagonDarw6(glm::vec3 c)
{
    init(true);
    positions={
    {-0.769411f,0.0f,-1.84608f},    //5
    {-0.769411f ,2.0f,-1.84608f},    //5
    {0.760582f  ,2.0f,-1.84973f},     //6
    {0.760582f,0.0f,-1.84973f},};  //6
        normals = vector<vec3>(4, {0, 1, 0});
  uvs = vector<vec2>{{0.0f, 0.0f},  // 0
                   {0.0f, 1.0f},   // 1
                   {1.0f, 1.0f},
                   {1.0f, 0.0f} 
};
   colors = vector<vec4>(4, {c, 1});
}

void Octagon::octagonDarw7(glm::vec3 c)
{
    init(true);
    positions={
    {0.760582f,0.0f,-1.84973f},     //6
    {0.760582f  ,2.0f,-1.84973f},     //6
    {1.84547f   ,2.0f,-0.770882f},     //7
    {1.84547f,0.0f,-0.770882f},     //7
    };
    normals = vector<vec3>(4, {0, 1, 0});
  uvs = vector<vec2>{{0.0f, 0.0f},  // 0
                   {0.0f, 1.0f},   // 1
                   {1.0f, 1.0f},
                   {1.0f, 0.0f} 
};
    colors = vector<vec4>(4, {c, 1});
}

void Octagon::octagonDarw8(glm::vec3 c)
{
    init(true);
    positions={    
    {1.84547f,0.0f,-0.770882f},     //7
    {1.84547f   ,2.0f,-0.770882f},     //7
    {1.84791f   ,2.0f,0.764999f},      //0
    {1.84791f,0.0f,0.764999f},      //0
};
    normals = vector<vec3>(4, {0, 1, 0});
  uvs = vector<vec2>{{0.0f, 0.0f},  // 0
                   {0.0f, 1.0f},   // 1
                   {1.0f, 1.0f},
                   {1.0f, 0.0f} 
};
   colors = vector<vec4>(4, {c, 1});
}

void Octagon::downFace(glm::vec3 c)
{
    init(true);
    positions={{1.84791f   ,2.0f,0.764999f},      //0
    {0.76647f   ,2.0f,1.8473f},        //1
    {-0.763527f ,2.0f,1.84852f},     //2
    {-1.84669f  ,2.0f,0.767941f},     //3
    {-1.84913f  ,2.0f,-0.762055f},    //4
    {-0.769411f ,2.0f,-1.84608f},    //5
    {0.760582f  ,2.0f,-1.84973f},     //6
    {1.84547f   ,2.0f,-0.770882f},     //7
};
normals = vector<vec3>(8, {0, 1, 0});
  uvs = vector<vec2>{{0.5f, 1.0f},  // 0
                   {1.0f, 0.75f},  // 1
                   {1.0f, 0.25f},  // 2
                   {0.5f, 0.0f},   // 3
                   {0.0f, 0.25f},  // 4
                   {0.0f, 0.75f},  // 5
                   {0.5f, 1.0f},   // 6
                   {1.0f, 0.75f}   // 7
};
   colors = vector<vec4>(8, {c, 1});

}

