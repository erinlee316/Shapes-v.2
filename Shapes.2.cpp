// Assignment 3, Shapes v.2

// Program will read from entire text file and process it line-by-line, parsing
// the shapes and making them as objects, which are stored in a bag for later.
// Objects will be retrieved to call functions that calculate and output the area,
// perimeter, volume, and surface area of various shapes into different sources.

// c++ libraries
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// c libraries
#include <cstdlib>   // atof
#include <cmath>     // sqrt and M_PI

// structure variables
// square dimensions
struct Square
{
  double length;
};

// rectangle dimensions
struct Rectangle
{
  double length;
  double width;
};

// circle dimensions
struct Circle
{
  double radius;
};

// triangle dimensions
struct Triangle
{
  double length;
};

// cube dimensions
struct Cube
{
  double length;
};

// box dimensions
struct Box
{
  double length;
  double width;
  double height;
};

// cylinder dimensions
struct Cylinder
{
  double height;
  double radius;
};

// prism dimensions
struct Prism
{
  double length;
  double height;
};

// function prototypes
void id();
void calcSquare(ostream&, const Square&);
void calcRectangle(ostream&, const Rectangle&);
void calcCircle(ostream&, const Circle&);
void calcTriangle(ostream&, const Triangle&);
void calcCube(ostream&, const Cube&);
void calcBox(ostream&, const Box&);
void calcCylinder(ostream&, const Cylinder&);
void calcPrism(ostream&, const Prism&);
vector<string> parseString(string);

int main()
{
  // function call for identification information
  id();

  // declare and initialize variables
  ifstream fin;     
  ofstream fout; 
  string line;
  vector<string> tokens;   
  vector<void*> myBag;
  vector<int> myBagType;

  // open files
  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");

  // Check if input file is opened successfully
  if (!fin.good())
  {
    cout << "Input file failed to open." << endl;
    return 1;
  }
 
  // Check if output file is opened successfully
  if (!fout.good())
  {
    cout << "Output file failed to open." << endl;
    return 1;
  }

  // keep looping until end of file is reached
  while (!fin.eof())
  {
    // read each line from input file and call function to get tokens
    getline(fin, line);
    tokens = parseString(line);

    // will skip any empty lines from input file
    if (tokens.size() != 0)
    {
      // check if token is square
      if (tokens[0] == "SQUARE")
      {
        // dynamically allocate memory for a new square object and store in bag
        // store 1 into different bag to represent square shape
        Square* s = new Square;
        myBag.push_back(s);
        myBagType.push_back(1);

        // check if enough tokens for sides
        // if not, assign the side with 0
        s->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
      }

      // check if token is rectangle
      else if (tokens[0] == "RECTANGLE")
      {
        // dynamically allocate memory for a new rectangle object and store in bag
        // store 2 into different bag to represent rectangle shape
        Rectangle* r = new Rectangle;
        myBag.push_back(r);
        myBagType.push_back(2);

        // check if enough tokens for sides
        // if not, assign the side with 0
        r->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        r->width = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;
      }

      // check if token is circle
      else if (tokens[0] == "CIRCLE")
      {
        // dynamically allocate memory for a new circle object and store in bag
        // store 3 into different bag to represent circle shape
        Circle* c = new Circle;
        myBag.push_back(c);
        myBagType.push_back(3);

        // check if enough tokens for sides
        // if not, assign the side with 0
        c->radius = (tokens.size() > 1) ?  atof(tokens[1].c_str()) : 0;
      }

      // check if token is triangle
      else if (tokens[0] == "TRIANGLE")
      {
        // dynamically allocate memory for a new triangle object and store in bag
        // store 4 into different bag to represent triangle shape
        Triangle* t = new Triangle;
        myBag.push_back(t);
        myBagType.push_back(4);

        // check if enough tokens for sides
        // if not, assign the side with 0
        t->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
      }

      // check if token is cube
      else if (tokens[0] == "CUBE")
      {
        // dynamically allocate memory for a new cube object and store in bag
        // store 5 into different bag to represent cube shape
        Cube* c = new Cube;
        myBag.push_back(c);
        myBagType.push_back(5);

        // check if enough tokens for sides
        // if not, assign the side with 0
        c->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
      }

      // check if token is box           
      else if (tokens[0] == "BOX")
      {
        // dynamically allocate memory for a new box object and store in bag
        // store 6 into different bag to represent box shape
        Box* b = new Box;
        myBag.push_back(b);
        myBagType.push_back(6);

        // check if enough tokens for sides
        // if not, assign the side with 0
        b->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        b->width = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;
        b->height = (tokens.size() > 3) ? atof(tokens[3].c_str()) : 0;
      }

      // check if token is cylinder      
      else if (tokens[0] == "CYLINDER")
      {
        // dynamically allocate memory for a new cylinder object and store in bag
        // store 7 into different bag to represent cylinder shape
        Cylinder* c = new Cylinder;
        myBag.push_back(c);
        myBagType.push_back(7);

        // check if enough tokens for sides
        // if not, assign the side with 0
        c->radius = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        c->height = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;
      }

      // check if token is prism
      else if (tokens[0] == "PRISM")
      {
        // dynamically allocate memory for a new prism object and store in bag
        // store 8 into different bag to represent prism shape
        Prism* p = new Prism;
        myBag.push_back(p);
        myBagType.push_back(8);

        // check if enough tokens for sides
        // if not, assign the side with 0
        p->length = (tokens.size() > 1) ? atof(tokens[1].c_str()) : 0;
        p->height = (tokens.size() > 2) ? atof(tokens[2].c_str()) : 0;
      }

      // check if token is EOF      
      else if (tokens[0] == "EOF")
        break;

      // token does not match one of eight objects
      else
        cout << tokens[0] << " invalid object" << endl;
    }
  }

  // close input file
  fin.close();

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert pointer in vector into pointer to square object
        // dereference the pointer to access square object
        // call function to calculate and display info to console output        
        Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
        Square& rSquare = *pSquare;
        calcSquare(cout, rSquare);
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert pointer in vector into pointer to rectangle object
        // dereference the pointer to access rectangle object     
        // call function to calculate and display info to console output        
        Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
        Rectangle& rRectangle = *pRectangle; 
        calcRectangle(cout, rRectangle);
        break;
      }
      // integer 3 represents circle
      case 3:
      {
        // convert pointer in vector into pointer to circle object
        // dereference the pointer to access circle object            
        // call function to calculate and display info to console output        
        Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
        Circle& rCircle = *pCircle;
        calcCircle(cout, rCircle);
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert pointer in vector into pointer to triangle object
        // dereference the pointer to access triangle object           
        // call function to calculate and display info to console output        
        Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
        Triangle& rTriangle = *pTriangle;
        calcTriangle(cout, rTriangle);
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert pointer in vector into pointer to cube object
        // dereference the pointer to access cube object            
        // call function to calculate and display info to console output        
        Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
        Cube& rCube = *pCube;
        calcCube(cout, rCube);
        break;
      }
      
      // integer 6 represents box
      case 6:
      {
        // convert pointer in vector into pointer to box object
        // dereference the pointer to access box object            
        // call function to calculate and display info to console output        
        Box* pBox = reinterpret_cast<Box*>(myBag[i]);
        Box& rBox = *pBox;
        calcBox(cout, rBox);
        break;
      }

      // integer 7 represents cylinder
      case 7:
      {
        // convert pointer in vector into pointer to cylinder object
        // dereference the pointer to access cylinder object           
        // call function to calculate and display info to console output        
        Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
        Cylinder& rCylinder = *pCylinder;
        calcCylinder(cout, rCylinder);
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert pointer in vector into pointer to prism object
        // dereference the pointer to access prism object   
        // call function to calculate and display info to console output        
        Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
        Prism& rPrism = *pPrism;
        calcPrism(cout, rPrism);
        break;
      }

      default:
        break;
    }
  }

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert pointer in vector into pointer to square object
        // dereference the pointer to access square object            
        // call function to calculate and display info to file output        
        Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
        Square& rSquare = *pSquare;
        calcSquare(fout, rSquare);
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert pointer in vector into pointer to rectangle object
        // dereference the pointer to access rectangle object            
        // call function to calculate and display info to file output        
        Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
        Rectangle& rRectangle = *pRectangle; 
        calcRectangle(fout, rRectangle);
        break;
      }

      // integer 3 represents circle
      case 3:
      {
        // convert pointer in vector into pointer to circle object
        // dereference the pointer to access circle object            
        // call function to calculate and display info to file output        
        Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
        Circle& rCircle = *pCircle;
        calcCircle(fout, rCircle);
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert pointer in vector into pointer to triangle object
        // dereference the pointer to access triangle object            
        // call function to calculate and display info to file output        
        Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
        Triangle& rTriangle = *pTriangle;
        calcTriangle(fout, rTriangle);
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert pointer in vector into pointer to cube object
        // dereference the pointer to access cube object            
        // call function to calculate and display info to file output        
        Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
        Cube& rCube = *pCube;
        calcCube(fout, rCube);
        break;
      }

      // integer 6 represents box
      case 6:
      {
        // convert pointer in vector into pointer to box object
        // dereference the pointer to access box object            
        // call function to calculate and display info to file output        
        Box* pBox = reinterpret_cast<Box*>(myBag[i]);
        Box& rBox = *pBox;
        calcBox(fout, rBox);
        break;
      }

      // integer 7 represents cylinder
      case 7:
      {
        // convert pointer in vector into pointer to cylinder object
        // dereference the pointer to access cylinder object            
        // call function to calculate and display info to file output        
        Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
        Cylinder& rCylinder = *pCylinder;
        calcCylinder(fout, rCylinder);
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert pointer in vector into pointer to prism object
        // dereference the pointer to access prism object            
        // call function to calculate and display info to file output        
        Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
        Prism& rPrism = *pPrism;
        calcPrism(fout, rPrism);
        break;
      }

      default:
        break;
    }
  }

  // keeps looping until all elements in bag are processed
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    // check shape type of object at current index in vector
    switch (myBagType[i])
    {
      // integer 1 represents square
      case 1:
      {
        // convert pointer in vector into pointer to square object
        // delete dynamically allocated square object      
        Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
        delete pSquare;
        break;
      }

      // integer 2 represents rectangle
      case 2:
      {
        // convert pointer in vector into pointer to rectangle object
        // delete dynamically allocated rectangle object   
        Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
        delete pRectangle;
        break;
      }

      // integer 3 represents circle
      case 3:
      {
        // convert pointer in vector into pointer to circle object
        // delete dynamically allocated circle object   
        Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
        delete pCircle;
        break;
      }

      // integer 4 represents triangle
      case 4:
      {
        // convert pointer in vector into pointer to triangle object
        // delete dynamically allocated triangle object   
        Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
        delete pTriangle;
        break;
      }

      // integer 5 represents cube
      case 5:
      { 
        // convert pointer in vector into pointer to cube object
        // delete dynamically allocated cube object   
        Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
        delete pCube;
        break;
      }

      // integer 6 represents box
      case 6:
      {
        // convert pointer in vector into pointer to box object
        // delete dynamically allocated box object   
        Box* pBox = reinterpret_cast<Box*>(myBag[i]);
        delete pBox;
        break;
      }
     
      // integer 7 represents cylinder
      case 7:
      {
        // convert pointer in vector into pointer to cylinder object
        // delete dynamically allocated cylinder object   
        Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
        delete pCylinder;
        break;
      }

      // integer 8 represents prism
      case 8:
      {
        // convert pointer in vector into pointer to prism object
        // delete dynamically allocated prism object   
        Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
        delete pPrism;
        break;
      }

      default:
        break;
    }
  }

  // close output file
  fout.close();

  return 0;
}

// function will display identification information
void id()
{
  cout << "Programmer: Erin Lee" << endl;
  cout << "Programmer's ID: 1805820" << endl;
  cout << "File: " << __FILE__ << endl;
}

// function will take a string and create an array of tokens
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}

// function will perform calculations for square and display results 
void calcSquare(ostream& out, const Square& s)
{
  // calculate area and perimeter
  double area = s.length * s.length;
  double perimeter = 4 * s.length;

  // display results to console or file
  out << "SQUARE side=" << s.length;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << area << " perimeter=" << perimeter << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

// function will perform calculations for rectangle and display results 
void calcRectangle(ostream& out, const Rectangle& r)
{ 
  // calculate area and perimeter
  double area = r.length * r.width;
  double perimeter = 2 * (r.length + r.width);

  // display results to console or file
  out << "RECTANGLE length=" << r.length << " width=" << r.width;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << area << " perimeter=" << perimeter << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

// function will perform calculations for circle and display results 
void calcCircle(ostream& out, const Circle& c)
{        
  // calculate area and perimeter
  double area = M_PI * c.radius * c.radius;
  double perimeter = 2 * M_PI * c.radius;

  // display results to console or file
  out << "CIRCLE radius=" << c.radius;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << area << " perimeter=" << perimeter << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

// function will perform calculations for triangle and display results 
void calcTriangle(ostream& out, const Triangle& t)
{        
  // calculate area and perimeter
  double area = (sqrt(3) / 4) * t.length * t.length;
  double perimeter = 3 * t.length;

  // display results to console or file
  out << "TRIANGLE side=" << t.length;
  out.setf(ios::fixed);
  out.precision(2);
  out << " area=" << area << " perimeter=" << perimeter << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

// function will perform calculations for cube and display results 
void calcCube(ostream& out, const Cube& c)
{
  // calculate surface area and volume
  double area = 6 * c.length * c.length;
  double volume = c.length * c.length * c.length;

  // display results to console or file
  out << "CUBE side=" << c.length;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface area=" << area << " volume=" << volume << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

// function will perform calculations for box and display results 
void calcBox(ostream& out, const Box& b)
{
  // calculate surface area and volume
  double area = 2 * ((b.length * b.width) + (b.width * b.height) + (b.length * b.height));
  double volume = b.length * b.width * b.height;

  // display results to console or file
  out << "BOX length=" << b.length << " width=" << b.width << " height=" << b.height;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface area=" << area << " volume=" << volume << endl;
  out.unsetf(ios::fixed);
  out.precision(6);    
}

// function will perform calculations for cylinder and display results 
void calcCylinder(ostream& out, const Cylinder& c)
{
  // calculate surface area and volume
  double area = (2 * M_PI * c.radius * c.radius) + (2 * M_PI * c.radius * c.height);
  double volume = M_PI * c.radius * c.radius * c.height;

  // display results to console or file
  out << "CYLINDER radius=" << c.radius << " height=" << c.height;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface area=" << area << " volume=" << volume << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}

// function will perform calculations for prism and display results 
void calcPrism(ostream& out, const Prism& p)
{
  // calculate surface area and volume
  double area = ((sqrt(3) / 2) * p.length * p.length) + (3 * p.length * p.height);
  double volume = (sqrt(3) / 4) * p.length * p.length * p.height;

  // display results to console or file
  out << "PRISM side=" << p.length << " height=" << p.height;
  out.setf(ios::fixed);
  out.precision(2);
  out << " surface area=" << area << " volume=" << volume << endl;
  out.unsetf(ios::fixed);
  out.precision(6);
}
