#include<iostream>

using namespace std;

class Library{
    
   private :
      
    string Book;
      int ID;
      
      public :
          void inputdetails(){
              cout<<"Enter book Name"<<endl;
              cin>>Book;
              cout<<endl;
              cout<<"Enter the book ID"<<endl;
              cin>>ID;
              cout<<endl;
              
          }
          void Displaydetails(){
              cout<<"The name of the book is shown below: "<<Book;
              cout<<endl;
              cout<<"The code of the book is shown below:"<<ID;
              cout<<endl;
          }
          
          bool searhCode(int Bookcode){
              return (Bookcode==ID);
              
                  
              
                  cout<<"the Book is not in the Library: "<<endl;
                  
                  
                  
              }
              
          };

      
     
int main(){
   Library library[5];
    int searchno;
    
    cout<<"Enter details of 5 books: \n";
    for(int i=0;i<5;i++){
        cout<<"\n Book "<<i+1<<"\n";
        library[i].inputdetails();
        cout<<endl;
        
        
    }
    
    cout<<"\n All book details are shown below:"<<endl;
    for(int i=0;i<5;i++){
        library[i].Displaydetails();
        
        
    }
    
    cout<<"\n Enter Book code to search"<<endl;
    cin>>searchno;
    
    bool found=false;
    for(int i=0;i<5;i++){
      if(library[i].searhCode(searchno)){
          cout<<"\n ---Book Found -----\n";
          library[i].Displaydetails();
          found=true;
          break;
          
      }
    }
    if(!found){
        cout<<"\n Book with code:"<<searchno<<"not found \n";
        cout<<endl;
        
        
    }
    return 0;
}
