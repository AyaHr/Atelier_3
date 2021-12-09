#include <iostream>
#include<cmath>
using namespace std;

//Programme1
	class Myclass{
	        public:
		    string nom;
		    Myclass();
		    ~Myclass();
	    
	    void print(){
	        cout<<"Entrez votre nom : "<<endl;
	        getline(cin,nom);
	        cout<<"Entre nom est : "<<nom<<endl;
	    };
	};
	
	    Myclass::Myclass(){};
	 
	    Myclass::~Myclass(){};
	    
	int main(){
	    Myclass etu;    
	    
	    etu.print();
	    return 0;
	};
	
//Programme2 
	class Shape
	{
		protected:
		  float x, y;
		public:
		  Shape(float _x, float _y)
		  {
		    x = _x;
		    y = _y;
		  }
	};
	
	class Rectangle: public Shape
	{
		public:
		  Rectangle(float _x, float _y) : Shape(_x, _y) {}
		  float area()
		  {
		    return (x * y);
		  }
	};
	
	class Triangle: public Shape
		{
		public:
		  Triangle(float _x, float _y) : Shape(_x, _y) {}
		  float area()
		  {
		    return (x * y / 2);
		  }
	};
	
	int main (){
	  Rectangle rectangle(2,3);
	  Triangle triangle(2,3);
	  cout << rectangle.area() << endl;   
	  cout << triangle.area() << endl;    
	  return 0;
	}
	
//Programme3

	using namespace std;
	class complexe{
	
	public:
		int r1;
		int r2;
		int im1;
		int im2;
		
		string operation;
		 complexe(){
		 	cout<<"Entrer votre premiere nombre reel "<<endl;		
			cin>>r1; 
		    cout<<"Entrer votre premiere nombre imaginaire"<<endl;		
			cin>>im1; 	
			cout<<"Entrer votre deuxieme nombre reel "<<endl;		
			cin>>r2;
			cout<<"Entrer votre deuxieme nombre imaginaire "<<endl;		
			cin>>im2;  
			cout<<"Entrer votre operation : "<<endl;
			cin>>operation;
			};
			
	void calcul(){
		if(operation=="+"){
	    cout<<"la nouvelle partie reele : " <<r1+r2<<endl;
	  	 cout<<"la nouvelle partie imaginaire: " <<im1+im2<<endl;
	}
	  else if (operation=="-")  {
	  	 cout<<"la nouvelle partie reele : " <<r1-r2<<endl;
	  	 cout<<"la nouvelle partie imaginaire: " <<im1-im2<<endl;
	  	}
	  	else if(operation=="*"){
	  		cout<<"la nouvelle partie reele"<<r1*r2+im1*im2<<endl;
	  		cout<<"la nouvelle partie imaginaire : "<<r1*im2+im1*r2<<endl;
			 }
		  else if(operation=="/"){
		   if(im2==0 && r2==0){
		   	cout<<"erreur";
		   }
		   else{
		        cout<<"Partie reele apres l\'operation : " <<float(im1*im2-r1*r2)/float(im2*im2+r2*r2)<<endl;
		  		cout<<"Partie imaginaire apres l\'operation : " <<float(im1*r2-r1*im2)/float(r2*r2+im2*im2)<<endl;
		  		}
			 
		  }
		  else{
		  	cout<<"vous n'avez pas choisis une operation arithmethique!"<<endl;
		  }
	}
};
	int main(){
		complexe a;
		a.calcul();	
	
		return 0;
	};
	
//Programme4
	class A{
	public:
	  void display ()
	  {
	    cout << "La méthode display de la classe A est exécutee\n";
	  }
	};
	
	class B : public A{
		public:
		  void display ()
		  {
		    cout << "La méthode display de la classe B est exécutee\n";
		  }
	};
	
	int main ()
	{
	  B b;
	  b.display();
	  return 0;
	}

//Programme 7
	class vecteur3d {
		float x;
		float y;
		float z;
		
	public:
	vecteur3d(float a = 0, float b = 0, float c = 0) : x(a), y(b), z(c) {
	}
	
	vecteur3d(const vecteur3d & v) {
		x = v.x;
		y = v.y;
		z = v.z;		
	}
	
	void afficher() {
		cout << "("<<x<<","<<y<<","<<z<<")" << endl;
	}
	
	vecteur3d somme(const vecteur3d & v) {
		vecteur3d s;
		s.x = x + v.x;
		s.y = y + v.y;
		s.z = z + v.z;
		return s;
	}
	
	float produit(const vecteur3d & v) {
		return x*v.x + y*v.y + z*v.z;
	}
	
	bool coincide(const vecteur3d & v) {
		return (x == v.x && y == v.y && z == v.z);
	}

	float norme() {
		return sqrt(x*x + y*y + z*z);
	}
	
	vecteur3d normax(vecteur3d v) {
		if( this->norme() > v.norme())
		    return *this;
		    
		return v;
	}
	
	vecteur3d * normax(vecteur3d * v) {
		if( this->norme() > v->norme())
		    return this;
		    
		return v;
	}
	vecteur3d & normaxR(vecteur3d &v) {
		if( this->norme() > v.norme())
		    return *this;
		    
		return v;
	}
};

	int main() {
		vecteur3d v1(1,2,3);
		cout << "Vecteur V1";
		v1.afficher();
		vecteur3d v2(5,6,7);
		cout << "Vecteur V2";
		v2.afficher();
		cout<<endl;
		cout << "La somme des vecteurs v1 et v2 est : ";
		(v1.somme(v2)).afficher();
		cout << "Le produit scalaire des vecteurs v1 et v2 est : " << v1.produit(v2) << endl;
		cout<<endl;
		cout << "Copier le vecteur V1 dans V3:" << endl;
		vecteur3d v3(v1);
		cout << "Vecteur V3";
		v3.afficher();
		if(v1.coincide(v3))
		    cout << "Les vecteurs v1 et v3 coincident " << endl; 
		else
		    cout << "Les vecteurs v1 et v3 ne coincident pas " << endl;
		
		cout<<endl;
		cout << "Le vecteur qui a la plus grande norme est (par valeur): ";
		(v1.normax(v2)).afficher();
		cout << "Le vecteur qui a la plus grande norme est (par adresse): ";
		(v1.normax(&v2))->afficher();
		cout << "Le vecteur qui a la plus grande norme est (par reference) :";
		(v1.normaxR(v2)).afficher();
		cout<<endl;
	}

//Programme 9
class test{
		public:
			int i;
			
			test(){
				this->i = 0;
			}
				
			int call (){
				return this->i++;
			}
	};
	int main(){
		int n(5);
		test t;
		int stop(0);
		
		while (stop == 0)
		{	
			cout <<"voulez vous appelez la fonction call (oui = 0 , non =1)"<<endl;
			cin >> stop ;
			
			if (stop == 0 ){
				t.call();
			}
		}
		
		cout << "Le nombre d'appel = "<< t.i;
		return 0;
	}	




















	
