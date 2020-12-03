#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <fstream>
#include <vector>
 using namespace std;
 
 //function pour menalger le mot
 string melanger(string mot)
     {
       string m;
        int p(0);
		
		while (mot.size() != 0)
        {
     
         p = rand() % mot.size();
         m+= mot[p];
         mot.erase(p, 1);
        }

  
   return m;
}


  int main ()
  {
  	string rep2;
  	 do 
  	  {
		
  		srand(time(0));
  	int rep;
  	 string mot1,motMyster;
  	cout<<"bienvenu dans le jeux des mots "<<endl<<" mode de jeux  : "<<endl<<" ***** un seule joueure ***** taper 1"<<endl<<" *****   deux joueure   ***** taper 2  "<<endl;
  	cin>>rep;
  	if (rep==1)
  	{
  		//mode de jeux 1
  		string const file("dico/dico.txt");

    

     string line;

      vector<string> vLines;

       ifstream flux(file.c_str());

       int nbLine(0);

      if(flux)

      {

        while(getline(flux,line))

      {

       vLines.push_back(line);

       }

    nbLine = rand() % vLines.size();

    mot1=vLines[nbLine];


   }

   else

   {

       cout << "ERREUR impossible d'ouvrir le fichier " << endl;
       return 0;

   }
	  }
	  
	  
      else if(rep == 2)
	  {
	  	//mode de jeux 2
	  	
	  //le joueure 1 entre un mot
	  
	  cout<<"joueure 1 entrez un mot   :  "	;
	  cin>>mot1;
	  cout<<endl;	
}
	  //le melange du mot
	
	    
     cout<<" le mot melanger est :  ";
  	    motMyster= melanger(mot1);
  	    cout<<motMyster;
  	//joueure 2 entre le mot 
  	 string motj2;
  	 cout<<"  joueure 2 tenter votre chance  :  ";
  	 cin>>motj2;
  	 
	   // comparaison
  	
	   int i=0;
  	 while(motj2 != mot1 && i < 5)
  	 {
  	 	int t1 = 4-i ;
  	 	cout<<"incorect il vous reste "<<t1<<" tentative "<<endl;
  	 	cin>>motj2;
  	 	i=i+1;
	   }
	 //jujement des performance 
	 if(motj2 == mot1)
	 {
	 	cout<<"vous avez gagnier vous ete le meilleur  "<<endl;
	 }
	 else 
	 {
	 	cout<<"domage vous avez perdu mais vou  etai presque  courage !!!"<<endl<<"la reponse correcte etai : "<<mot1<<"  retanter cotre chance"<<endl;

	 }
	  
	 cout<<" vous voulais refaire une partie : yes/no ::::::::::: ";
	 cin>>rep2;
	 
	 cout<<endl<<"***************************************"<<endl<<"***************************************"<<endl<<endl;
	 
  	 
    
	
	
	}while(rep2== "yes");
	
    

    return 0;
  }
