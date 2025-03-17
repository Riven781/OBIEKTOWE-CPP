#include <iostream>

class Shape{
protected:
    long int _x;
    long int _y;
public:
    Shape(long x, long y): _x{x}, _y{y}{};
    virtual void draw() = 0;
    virtual ~Shape(){};
};

class Rectangle : public Shape{
public:    
    Rectangle(long ll_x,long ll_y): Shape(ll_x,ll_y) {};
    virtual void draw(){
        std::cout << "--Rectangle--" << std::endl;
    }
};

class Circle : public Shape{
private:
    long _r;

public:    
    Circle(long ll_x,long ll_y, long r): Shape(ll_x,ll_y), _r{r} {};
    virtual void draw(){
        std::cout << "--Circle--" << std::endl;
    }
};

void draw_shapes(Shape *table[],size_t n) {
    for(size_t i=0;i<n;++i)
      table[i]->draw();
} 


template<typename T> void draw_template(T table[],size_t n) {
    for(size_t i=0;i<n;++i)
      table[i].draw();
} 


int main(int argc, char const *argv[])
{
    std::cout << "POLIMORFIZM DYNAMICZNY" << std::endl;
    Shape *list[4];
    list[0]=new Circle(0,0,100);
    list[1]=new Rectangle(20,20);
    list[2]=new Circle(10,10,5);
    list[3]=new Rectangle(20,0);
    draw_shapes(list,4);
    std::cout << "POLIMORFIZM STATYCZNY" << std::endl;
    Circle table1[2]{ Circle(0,0,100), Circle(10,10,5)};
    draw_template(table1,2);

    return 0;
}
