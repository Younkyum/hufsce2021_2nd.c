#include <iostream>
#include <string>
using namespace std;
const float pi=3.14;

class Shape {
private:
	int x;
	int y;
};



int main(){
   int check=0;
   int xpoint, ypoint;
   double width, height;
   double radius;

   cin>>check;
   if(check==0){
      cin>> xpoint >> ypoint>> width >> height;
      //Square 객체 만들고 print함수 실행
      Square S(xpoint,ypoint,width,height);
      S.print();
   }
   else if(check==1){
      cin>>xpoint>>ypoint >> radius;
      //Circle 객체 만들고 print함수 실행
      Circle C(xpoint,ypoint,radius);
      C.print();
   }
   else{
      cin>>xpoint >> ypoint >> width >> height;
      //Triangle 객체 만들고 print함수 실행
      Triangle T(xpoint, ypoint,width,height);
      T.print();
   }

   return 0;
}
